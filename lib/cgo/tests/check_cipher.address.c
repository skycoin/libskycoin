
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"

#define SKYCOIN_ADDRESS_VALID "2GgFvqoyk9RjwVzj8tqfcXVXB4orBwoc9qv"

TestSuite(cipher_address, .init = setup, .fini = teardown);

// buffer big enough to hold all kind of data needed by test cases
unsigned char buff[1024];

Test(cipher_address, TestDecodeBase58Address)
{

  GoString strAddr = {
      SKYCOIN_ADDRESS_VALID,
      35};
  cipher__Address addr;

  cr_assert(SKY_cipher_DecodeBase58Address(strAddr, &addr) == SKY_OK, "accept valid address");

  char tempStr[50];
  int errorcode;

  // preceding whitespace is invalid
  strcpy(tempStr, " ");
  strcat(tempStr, SKYCOIN_ADDRESS_VALID);
  strAddr.p = tempStr;
  strAddr.n = strlen(tempStr);
  errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
  cr_assert(
      errorcode == SKY_ERROR,
      "preceding whitespace is invalid");

  // preceding zeroes are invalid
  strcpy(tempStr, "000");
  strcat(tempStr, SKYCOIN_ADDRESS_VALID);
  strAddr.p = tempStr;
  strAddr.n = strlen(tempStr);
  errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
  cr_assert(
      errorcode == SKY_ERROR,
      "leading zeroes prefix are invalid");

  // trailing whitespace is invalid
  strcpy(tempStr, SKYCOIN_ADDRESS_VALID);
  strcat(tempStr, " ");
  strAddr.p = tempStr;
  strAddr.n = strlen(tempStr);
  errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
  cr_assert(
      errorcode == SKY_ERROR,
      "trailing whitespace is invalid");

  // trailing zeroes are invalid
  strcpy(tempStr, SKYCOIN_ADDRESS_VALID);
  strcat(tempStr, "000");
  strAddr.p = tempStr;
  strAddr.n = strlen(tempStr);
  errorcode = SKY_cipher_DecodeBase58Address(strAddr, &addr);
  cr_assert(
      errorcode == SKY_ERROR,
      "trailing zeroes suffix are invalid");
}

Test(cipher_address, TestAddressFromBytes)
{
  cipher__Address addr, addr2;
  cipher__SecKey sk;
  cipher__PubKey pk;
  GoSlice bytes;
  GoSlice_ tempBytes;

  GoUint32 err = SKY_cipher_GenerateKeyPair(&pk, &sk);
  cr_assert(err == SKY_OK);
  SKY_cipher_AddressFromPubKey(&pk, &addr);

  tempBytes.data = buff;
  tempBytes.len = 0;
  tempBytes.cap = sizeof(buff);

  SKY_cipher_Address_Bytes(&addr, &tempBytes);
  cr_assert(tempBytes.len > 0, "address bytes written");
  copyGoSlice_toGoSlice(&bytes, &tempBytes, tempBytes.len);
  err = SKY_cipher_AddressFromBytes(bytes, &addr2);
  cr_assert(err == SKY_OK, "convert bytes to SKY address");

  cr_assert(eq(type(cipher__Address), addr, addr2));

  int bytes_len = bytes.len;

  bytes.len = bytes.len - 2;
  cr_assert(SKY_cipher_AddressFromBytes(bytes, &addr2) == SKY_ErrAddressInvalidLength, "no SKY address due to short bytes length");

  bytes.len = bytes_len;
  ((char *)bytes.data)[bytes.len - 1] = '2';
  cr_assert(SKY_cipher_AddressFromBytes(bytes, &addr2) == SKY_ErrAddressInvalidChecksum, "no SKY address due to corrupted bytes");

  addr.Version = 2;
  SKY_cipher_Address_Bytes(&addr, &tempBytes);
  copyGoSlice_toGoSlice(&bytes, &tempBytes, tempBytes.len);
  cr_assert(SKY_cipher_AddressFromBytes(bytes, &addr2) == SKY_ErrAddressInvalidVersion, "Invalid version");
}

Test(cipher_address, TestAddressVerify)
{

  cipher__PubKey pubkey;
  cipher__SecKey seckey;
  cipher__PubKey pubkey2;
  cipher__SecKey seckey2;
  cipher__Address addr;

  SKY_cipher_GenerateKeyPair(&pubkey, &seckey);
  SKY_cipher_AddressFromPubKey(&pubkey, &addr);

  // Valid pubkey+address
  cr_assert(SKY_cipher_Address_Verify(&addr, &pubkey) == SKY_OK, "Valid pubkey + address");

  SKY_cipher_GenerateKeyPair(&pubkey, &seckey2);
  //   // Invalid pubkey
  cr_assert(SKY_cipher_Address_Verify(&addr, &pubkey) == SKY_ErrAddressInvalidPubKey, " Invalid pubkey");

  // Bad version
  addr.Version = 0x01;
  cr_assert(SKY_cipher_Address_Verify(&addr, &pubkey) == SKY_ErrAddressInvalidVersion, "  Bad version");
}

Test(cipher_address, TestAddressString)
{
  cipher__PubKey pk;
  cipher__SecKey sk;
  cipher__Address addr, addr2, addr3;
  GoString str;

  str.p = (char *)buff;
  str.n = 0;

  SKY_cipher_GenerateKeyPair(&pk, &sk);
  SKY_cipher_AddressFromPubKey(&pk, &addr);
  SKY_cipher_Address_String(&addr, (GoString_ *)&str);
  cr_assert(SKY_cipher_DecodeBase58Address(str, &addr2) == SKY_OK);
  cr_assert(eq(type(cipher__Address), addr, addr2));

  SKY_cipher_Address_String(&addr2, (GoString_ *)&str);
  cr_assert(SKY_cipher_DecodeBase58Address(str, &addr3) == SKY_OK);
  cr_assert(eq(type(cipher__Address), addr, addr2));
}

Test(cipher_address, TestAddressBulk)
{

  unsigned char buff[50];
  GoSlice slice = {buff, 0, 50};
  int i;
  for (i = 0; i < 1024; ++i)
  {
    GoUint32 err;
    randBytes(&slice, 32);
    cipher__PubKey pubkey;
    cipher__SecKey seckey;
    err = SKY_cipher_GenerateDeterministicKeyPair(slice, &pubkey, &seckey);
    cr_assert(err == SKY_OK);
    cipher__Address addr;
    err = SKY_cipher_AddressFromPubKey(&pubkey, &addr);
    cr_assert(err == SKY_OK);
    err = SKY_cipher_Address_Verify(&addr, &pubkey);
    cr_assert(err == SKY_OK);

    GoString_ tempstrAddr;
    err = SKY_cipher_Address_String(&addr, &tempstrAddr);
    cr_assert(err == SKY_OK);
    registerMemCleanup((void *)tempstrAddr.p);
    cipher__Address addr2;
    GoString strAddr;
    strAddr.n = tempstrAddr.n;
    strAddr.p = tempstrAddr.p;
    err = SKY_cipher_DecodeBase58Address(strAddr, &addr2);
    cr_assert(err == SKY_OK);
    cr_assert(eq(type(cipher__Address), addr, addr2));
  }
}

Test(cipher_address, TestAddressNull)
{
  cipher__Address a;
  memset(&a, 0, sizeof(cipher__Address));
  GoUint32 result;
  GoUint8 isNull;
  result = SKY_cipher_Address_Null(&a, &isNull);
  cr_assert(result == SKY_OK, "SKY_cipher_Address_Null");
  cr_assert(isNull == 1);

  cipher__PubKey p;
  cipher__SecKey s;

  result = SKY_cipher_GenerateKeyPair(&p, &s);
  cr_assert(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");

  result = SKY_cipher_AddressFromPubKey(&p, &a);
  cr_assert(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
  result = SKY_cipher_Address_Null(&a, &isNull);
  cr_assert(result == SKY_OK, "SKY_cipher_Address_Null");
  cr_assert(isNull == 0);
}
