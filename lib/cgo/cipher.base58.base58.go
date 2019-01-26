package main

import (
	"encoding/hex"
	"reflect"
)

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
