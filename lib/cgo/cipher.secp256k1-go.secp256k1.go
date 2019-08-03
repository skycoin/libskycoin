package main

import (
	"reflect"
	"unsafe"

	"github.com/skycoin/skycoin/src/cipher/secp256k1-go"
)

/*

#include <string.h>
#include <stdlib.h>
#include "skytypes.h"
*/
import "C"

//export SKY_secp256k1_PubkeyFromSeckey
func SKY_secp256k1_PubkeyFromSeckey(__seckey []byte, _arg1 *C.GoSlice_) (____error_code uint32) {
	seckey := *(*[]byte)(unsafe.Pointer(&__seckey))
	__arg1 := secp256k1.PubkeyFromSeckey(seckey)
	if __arg1 != nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
		return SKY_OK
	}
	return SKY_ERROR
}

//export SKY_secp256k1_VerifyPubkey
func SKY_secp256k1_VerifyPubkey(__pubkey []byte) (____error_code int) {
	pubkey := *(*[]byte)(unsafe.Pointer(&__pubkey))
	____error_code = secp256k1.VerifyPubkey(pubkey)
	return
}

//export SKY_secp256k1_VerifySecKey
func SKY_secp256k1_VerifySecKey(__seckey []byte) (____error_code int) {
	seckey := *(*[]byte)(unsafe.Pointer(&__seckey))
	____error_code = secp256k1.VerifySeckey(seckey)
	return
}

//export SKY_secp256k1_ECDH
func SKY_secp256k1_ECDH(_pub []byte, _sec []byte, _arg1 *C.GoSlice_) (____error_code uint32) {
	pubkey := *(*[]byte)(unsafe.Pointer(&_pub))
	seckey := *(*[]byte)(unsafe.Pointer(&_sec))
	__arg1 := secp256k1.ECDH(pubkey, seckey)
	if __arg1 != nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
		return SKY_OK
	}
	return SKY_ERROR
}
