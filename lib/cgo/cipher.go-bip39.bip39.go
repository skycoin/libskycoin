package main

import (
	"reflect"
	"unsafe"

	gobip39 "github.com/skycoin/skycoin/src/cipher/bip39"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
*/
import "C"

//export SKY_bip39_NewDefaultMnemomic
func SKY_bip39_NewDefaultMnemomic(_arg0 *C.GoString_) (____error_code uint32) {
	__arg0, ____return_err := gobip39.NewDefaultMnemonic()
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyString(__arg0, _arg0)
	}
	return
}

//export SKY_bip39_NewEntropy
func SKY_bip39_NewEntropy(_bitSize int, _arg1 *C.GoSlice_) (____error_code uint32) {
	bitSize := _bitSize
	__arg1, ____return_err := gobip39.NewEntropy(bitSize)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
	}
	return
}

//export SKY_bip39_NewMnemonic
func SKY_bip39_NewMnemonic(_entropy []byte, _arg1 *C.GoString_) (____error_code uint32) {
	entropy := *(*[]byte)(unsafe.Pointer(&_entropy))
	__arg1, ____return_err := gobip39.NewMnemonic(entropy)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyString(__arg1, _arg1)
	}
	return
}

//export SKY_bip39_ValidateMnemonic
func SKY_bip39_ValidateMnemonic(_mnemonic string) (____error_code uint32) {
	mnemonic := _mnemonic
	____return_err := gobip39.ValidateMnemonic(mnemonic)
	____error_code = libErrorCode(____return_err)
	return
}

//export SKY_bip39_NewSeed
func SKY_bip39_NewSeed(_mnemonic string, _password string, _arg1 *C.GoSlice_) (____error_code uint32) {
	mnemonic := _mnemonic
	password := _password
	__arg1, ____return_err := gobip39.NewSeed(mnemonic, password)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
	}
	return
}
