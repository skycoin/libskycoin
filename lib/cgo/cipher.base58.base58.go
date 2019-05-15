package main

import (
	"reflect"
	"unsafe"

	"github.com/skycoin/skycoin/src/cipher/base58"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
*/
import "C"

//export SKY_base58_Hex2Base58
func SKY_base58_Hex2Base58(_val []byte, _arg1 *C.GoString_) (____error_code uint32) {
	val := *(*[]byte)(unsafe.Pointer(&_val))
	__arg1 := string(base58.Encode(val))
	copyString(__arg1, _arg1)
	return
}

//export SKY_base58_Encode
func SKY_base58_Encode(_bin []byte, _arg1 *C.GoString_) (____error_code uint32) {
	bin := *(*[]byte)(unsafe.Pointer(&_bin))
	__arg1 := base58.Encode(bin)
	copyString(__arg1, _arg1)
	return
}

//export SKY_base58_Decode
func SKY_base58_Decode(_s string, _arg1 *C.GoSlice_) (____error_code uint32) {
	s := _s
	__arg1, ____return_err := base58.Decode(s)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
	}

	return
}
