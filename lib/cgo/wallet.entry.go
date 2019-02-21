package main

import (
	"unsafe"

	wallet "github.com/skycoin/skycoin/src/wallet"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
*/
import "C"

//export SKY_wallet_Entry_SkycoinAddress
func SKY_wallet_Entry_SkycoinAddress(_we *C.wallet__Entry, _arg0 *C.cipher__Address) (____error_code uint32) {
	we := (*wallet.Entry)(unsafe.Pointer(_we))
	addr := we.SkycoinAddress()
	*_arg0 = *(*C.cipher__Address)(unsafe.Pointer(&addr))
	return
}

//export SKY_wallet_Entry_BitcoinAddress
func SKY_wallet_Entry_BitcoinAddress(_we *C.wallet__Entry, _arg0 *C.cipher__BitcoinAddress) (____error_code uint32) {
	we := (*wallet.Entry)(unsafe.Pointer(_we))
	addr := we.BitcoinAddress()
	*_arg0 = *(*C.cipher__BitcoinAddress)(unsafe.Pointer(&addr))
	return
}

//export SKY_wallet_Entry_Verify
func SKY_wallet_Entry_Verify(_we *C.wallet__Entry) (____error_code uint32) {
	we := (*wallet.Entry)(unsafe.Pointer(_we))
	____return_err := we.Verify()
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}

//export SKY_wallet_Entry_VerifyPublic
func SKY_wallet_Entry_VerifyPublic(_we *C.wallet__Entry) (____error_code uint32) {
	we := (*wallet.Entry)(unsafe.Pointer(_we))
	____return_err := we.VerifyPublic()
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}
