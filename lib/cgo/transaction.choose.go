package main

import (
	"reflect"
	"unsafe"

	coin "github.com/skycoin/skycoin/src/coin"
	"github.com/skycoin/skycoin/src/transaction"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
	#include "skyfee.h"
*/
import "C"

//export SKY_transaction_ChooseSpendsMaximizeUxOuts
func SKY_transaction_ChooseSpendsMaximizeUxOuts(_uxa []C.transaction__UxBalance, _coins, _hours uint64, _arg2 *C.GoSlice_) (____error_code uint32) {
	txa := *(*[]transaction.UxBalance)(unsafe.Pointer(&_uxa))
	coins := _coins
	hours := _hours
	__arg2, ____return_err := transaction.ChooseSpendsMaximizeUxOuts(txa, coins, hours)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg2), _arg2)
	}
	return
}

//export SKY_transaction_ChooseSpendsMinimizeUxOuts
func SKY_transaction_ChooseSpendsMinimizeUxOuts(_uxa []C.transaction__UxBalance, _coins, _hours uint64, _arg2 *C.GoSlice_) (____error_code uint32) {
	uxa := *(*[]transaction.UxBalance)(unsafe.Pointer(&_uxa))
	coins := _coins
	hours := _hours
	__arg2, ____return_err := transaction.ChooseSpendsMinimizeUxOuts(uxa, coins, hours)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg2), _arg2)
	}
	return
}

//export SKY_transaction_NewUxBalance
func SKY_transaction_NewUxBalance(_headTime uint64, _ux *C.coin__UxOut, _arg2 *C.transaction__UxBalance) (____error_code uint32) {
	headTime := _headTime
	ux := *(*coin.UxOut)(unsafe.Pointer(_ux))
	__arg2, ____return_err := transaction.NewUxBalance(headTime, ux)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		*_arg2 = *(*C.transaction__UxBalance)(unsafe.Pointer(&__arg2))
	}
	return
}

//export SKY_transaction_NewUxBalances
func SKY_transaction_NewUxBalances(_headTime uint64, _uxa *C.coin__UxArray, _arg2 *C.GoSlice_) (____error_code uint32) {
	headTime := _headTime
	uxa := *(*coin.UxArray)(unsafe.Pointer(_uxa))
	__arg2, ____return_err := transaction.NewUxBalances(uxa, headTime)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg2), _arg2)
	}
	return
}
