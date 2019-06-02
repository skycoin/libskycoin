package main

import (
	"reflect"
	"unsafe"

	"github.com/skycoin/skycoin/src/transaction"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
	#include "skyfee.h"
*/
import "C"

//export SKY_transaction_DistributeCoinHoursProportional
func SKY_transaction_DistributeCoinHoursProportional(_coins []uint64, _hours uint64, _arg2 *C.GoSlice_) (____error_code uint32) {
	coins := *(*[]uint64)(unsafe.Pointer(&_coins))
	hours := _hours
	__arg2, ____return_err := transaction.DistributeCoinHoursProportional(coins, hours)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg2), _arg2)
	}
	return
}

//export SKY_transaction_DistributeSpendHours
func SKY_transaction_DistributeSpendHours(_inputHours, _nAddrs uint64, _haveChange bool, _arg2 *uint64, _arg3 *C.GoSlice_, _arg4 *uint64) (____error_code uint32) {
	inputHours := _inputHours
	nAddrs := _nAddrs
	haveChange := _haveChange
	__arg2, __arg3, __arg4 := transaction.DistributeSpendHours(inputHours, nAddrs, haveChange)
	*_arg2 = __arg2
	copyToGoSlice(reflect.ValueOf(__arg3), _arg3)
	*_arg4 = __arg4
	return
}
