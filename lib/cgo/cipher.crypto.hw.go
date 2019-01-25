package main

import (
	"reflect"
	"unsafe"

	cipher "github.com/skycoin/skycoin/src/cipher"
)

//export SKY_cipher_SecKeyFromHex
func SKY_cipher_SecKeyFromHex(_s string, _arg1 *C.cipher__SecKey) (____error_code uint32) {
	sk, err := cipher.SecKeyFromHex(_s)
	errcode := libErrorCode(err)
	if err == nil {
		copyToBuffer(reflect.ValueOf(sk[:]), unsafe.Pointer(_arg1), uint(SizeofSecKey))
	}
	____error_code = errcode
	return
}

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
*/
import "C"

//export SKY_base58_String2Hex
func SKY_base58_String2Hex(_s string, _arg1 *C.GoSlice_) (____error_code uint32) {
	s := _s
	__arg1, ____return_err := hex.DecodeString(s)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
	}

	return
}

//export SKY_cipher_BitcoinAddressFromSecKey
func SKY_cipher_BitcoinAddressFromSecKey(_secKey *C.cipher__SecKey, _arg1 *C.cipher__BitcoinAddress) uint32 {
	secKey := (*cipher.SecKey)(unsafe.Pointer(_secKey))

	addr, err := cipher.BitcoinAddressFromSecKey(*secKey)
	if err == nil {
		*_arg1 = *(*C.cipher__BitcoinAddress)(unsafe.Pointer(&addr))
	}
	return libErrorCode(err)
}

//export SKY_cipher_BitcoinAddressFromPubKey
func SKY_cipher_BitcoinAddressFromPubKey(_pubKey *C.cipher__PubKey, _arg1 *C.cipher__BitcoinAddress) {
	pubKey := (*cipher.PubKey)(unsafe.Pointer(_pubKey))

	addr := cipher.BitcoinAddressFromPubKey(*pubKey)
	*_arg1 = *(*C.cipher__BitcoinAddress)(unsafe.Pointer(&addr))
}

//export SKY_cipher_GenerateDeterministicKeyPair
func SKY_cipher_GenerateDeterministicKeyPair(_seed []byte, _arg1 *C.cipher__PubKey, _arg2 *C.cipher__SecKey) (____error_code uint32) {
	p, s, err := cipher.GenerateDeterministicKeyPair(_seed)
	if err == nil {
		copyToBuffer(reflect.ValueOf(p[:]), unsafe.Pointer(_arg1), uint(SizeofPubKey))
		copyToBuffer(reflect.ValueOf(s[:]), unsafe.Pointer(_arg2), uint(SizeofSecKey))
	}

	____error_code = libErrorCode(err)
	return
}

//export SKY_cipher_SumSHA256
func SKY_cipher_SumSHA256(_b []byte, _arg1 *C.cipher__SHA256) (____error_code uint32) {
	h := cipher.SumSHA256(_b)

	copyToBuffer(reflect.ValueOf(h[:]), unsafe.Pointer(_arg1), uint(SizeofSHA256))
	return
}

//export SKY_cipher_SHA256_Set
func SKY_cipher_SHA256_Set(_g *C.cipher__SHA256, _b []byte) (____error_code uint32) {
	g := (*cipher.SHA256)(unsafe.Pointer(_g))

	err := g.Set(_b)
	____error_code = libErrorCode(err)
	return
}

//export SKY_cipher_ECDH
func SKY_cipher_ECDH(_pub *C.cipher__PubKey, _sec *C.cipher__SecKey, _arg2 *C.GoSlice_) (____error_code uint32) {
	pub := (*cipher.PubKey)(unsafe.Pointer(_pub))
	sec := (*cipher.SecKey)(unsafe.Pointer(_sec))
	b, err := cipher.ECDH(*pub, *sec)
	____error_code = libErrorCode(err)
	if err == nil {
		copyToGoSlice(reflect.ValueOf(b), _arg2)
	}
	return
}

//export SKY_cipher_DoubleSHA256
func SKY_cipher_DoubleSHA256(_b []byte, _arg1 *C.cipher__SHA256) (____error_code uint32) {
	h := cipher.DoubleSHA256(_b)
	copyToBuffer(reflect.ValueOf(h[:]), unsafe.Pointer(_arg1), uint(SizeofSHA256))
	return
}

//export SKY_handle_copy
func SKY_handle_copy(handle C.Handle, copy *C.Handle) uint32 {
	obj, ok := lookupHandle(handle)
	if ok {
		*copy = registerHandle(obj)
		return SKY_OK
	} else {
		return SKY_BAD_HANDLE
	}
}

//export SKY_cipher_PubKeyFromSig
func SKY_cipher_PubKeyFromSig(_sig *C.cipher__Sig, _hash *C.cipher__SHA256, _arg2 *C.cipher__PubKey) (____error_code uint32) {
	sig := (*cipher.Sig)(unsafe.Pointer(_sig))
	hash := (*cipher.SHA256)(unsafe.Pointer(_hash))

	pubkey, err := cipher.PubKeyFromSig(*sig, *hash)

	errcode := libErrorCode(err)
	if err == nil {
		copyToBuffer(reflect.ValueOf(pubkey[:]), unsafe.Pointer(_arg2), uint(SizeofPubKey))

	}
	____error_code = errcode
	return
}

//export SKY_cipher_PubKeyFromSecKey
func SKY_cipher_PubKeyFromSecKey(_seckey *C.cipher__SecKey, _arg1 *C.cipher__PubKey) (____error_code uint32) {
	seckey := (*cipher.SecKey)(unsafe.Pointer(_seckey))

	pubkey, err := cipher.PubKeyFromSecKey(*seckey)
	____error_code = libErrorCode(err)

	if err == nil {
		copyToBuffer(reflect.ValueOf(pubkey[:]), unsafe.Pointer(_arg1), uint(SizeofPubKey))
	}

	return
}