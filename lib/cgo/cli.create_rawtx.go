package main

import (
	"unsafe"

	"github.com/skycoin/skycoin/src/transaction"

	cipher "github.com/skycoin/skycoin/src/cipher"
	cli "github.com/skycoin/skycoin/src/cli"
	coin "github.com/skycoin/skycoin/src/coin"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
*/
import "C"

// //export SKY_cli_CreateRawTxFromAddress
// func SKY_cli_CreateRawTxFromAddress(_c C.WebRpcClient__Handle, _addr, _walletFile, _chgAddr string, _toAddrs []C.cli__SendAmount, pwd C.PasswordReader__Handle, _arg4 *C.Transaction__Handle) (____error_code uint32) {
// 	c, okc := lookupWebRpcClientHandle(_c)
// 	if !okc {
// 		____error_code = SKY_BAD_HANDLE
// 		return
// 	}
// 	addr := _addr
// 	walletFile := _walletFile
// 	chgAddr := _chgAddr
// 	toAddrs := *(*[]cli.SendAmount)(unsafe.Pointer(&_toAddrs))
// 	pr, okp := lookupPasswordReaderHandle(pwd)
// 	if !okp {
// 		____error_code = SKY_BAD_HANDLE
// 		return
// 	}
// 	__arg4, ____return_err := cli.CreateRawTxFromAddress(c, addr, walletFile, chgAddr, toAddrs, *pr)
// 	____error_code = libErrorCode(____return_err)
// 	if ____return_err == nil {
// 		*_arg4 = registerTransactionHandle(__arg4)
// 	}
// 	return
// }

//export SKY_cli_NewTransaction
func SKY_cli_NewTransaction(_utxos []C.transaction__UxBalance, _keys []C.cipher__SecKey, _outs []C.coin__TransactionOutput, _arg3 *C.Transaction__Handle) (____error_code uint32) {
	utxos := *(*[]transaction.UxBalance)(unsafe.Pointer(&_utxos))
	keys := *(*[]cipher.SecKey)(unsafe.Pointer(&_keys))
	outs := *(*[]coin.TransactionOutput)(unsafe.Pointer(&_outs))
	__arg3, ____return_err := cli.NewTransaction(utxos, keys, outs)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		*_arg3 = registerTransactionHandle(__arg3)
	}
	return
}
