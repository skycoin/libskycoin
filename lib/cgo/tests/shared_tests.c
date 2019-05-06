#include "shared_tests.h"

#include <stdio.h>
#include <string.h>

#include "libskycoin.h"
#include "skyerrors.h"
#include "skystring.h"
#include "skytest.h"

void TestAddressNullShared(xUnitTest *xunit) {
  cipher__Address a;
  memset(&a, 0, sizeof(cipher__Address));
  GoUint32 result;
  GoUint8 isNull;
  result = SKY_cipher_Address_Null(&a, &isNull);
  xunit->assert_msg(result == SKY_OK, "SKY_cipher_Address_Null");
  xunit->assert(isNull == 1);

  cipher__PubKey p;
  cipher__SecKey s;

  result = SKY_cipher_GenerateKeyPair(&p, &s);
  xunit->assert_msg(result == SKY_OK, "SKY_cipher_GenerateKeyPair failed");

  result = SKY_cipher_AddressFromPubKey(&p, &a);
  xunit->assert_msg(result == SKY_OK, "SKY_cipher_AddressFromPubKey failed");
  result = SKY_cipher_Address_Null(&a, &isNull);
  xunit->assert_msg(result == SKY_OK, "SKY_cipher_Address_Null");
  xunit->assert(isNull == 0);
}
