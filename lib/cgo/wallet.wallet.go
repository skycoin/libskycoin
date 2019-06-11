package main

import (
	"reflect"
	"unsafe"

	cipher "github.com/skycoin/skycoin/src/cipher"
	wallet "github.com/skycoin/skycoin/src/wallet"
)

/*

  #include <string.h>
  #include <stdlib.h>

  #include "skytypes.h"
*/
import "C"

//export SKY_wallet_NewError
func SKY_wallet_NewError(_err error) (____error_code uint32) {
	err := _err
	____return_err := wallet.NewError(err)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}

//export SKY_wallet_NewWallet
func SKY_wallet_NewWallet(_wltName string, _opts C.Options__Handle, _arg2 *C.Wallet__Handle) (____error_code uint32) {
	__opts, okopts := lookupOptionsHandle(_opts)
	if !okopts {
		____error_code = SKY_BAD_HANDLE
		return
	}
	opts := *__opts
	__arg2, ____return_err := wallet.NewWallet(_wltName, opts)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		*_arg2 = registerWalletHandle(__arg2)
	}
	return
}

//export SKY_wallet_Wallet_Lock
func SKY_wallet_Wallet_Lock(_w C.Wallet__Handle, _password []byte, _cryptoType string) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	password := *(*[]byte)(unsafe.Pointer(&_password))
	cryptoType := wallet.CryptoType(_cryptoType)
	____return_err := w.Lock(password, cryptoType)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}

//export SKY_wallet_Wallet_Unlock
func SKY_wallet_Wallet_Unlock(_w C.Wallet__Handle, _password []byte, _arg1 *C.Wallet__Handle) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	password := *(*[]byte)(unsafe.Pointer(&_password))
	__arg1, ____return_err := w.Unlock(password)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		*_arg1 = registerWalletHandle(__arg1)
	}
	return
}

//export SKY_wallet_Load
func SKY_wallet_Load(_wltFile string, _arg1 *C.Wallet__Handle) (____error_code uint32) {
	wltFile := _wltFile
	__arg1, ____return_err := wallet.Load(wltFile)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		*_arg1 = registerWalletHandle(__arg1)
	}
	return
}

//export SKY_wallet_Wallet_Save
func SKY_wallet_Wallet_Save(_w C.Wallet__Handle, _dir string) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	dir := _dir
	____return_err := w.Save(dir)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}

//export SKY_wallet_Wallet_Validate
func SKY_wallet_Wallet_Validate(_w C.Wallet__Handle) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	____return_err := w.Validate()
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}

//export SKY_wallet_Wallet_Type
func SKY_wallet_Wallet_Type(_w C.Wallet__Handle, _arg0 *C.GoString_) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	__arg0 := w.Type()
	copyString(__arg0, _arg0)
	return
}

//export SKY_wallet_Wallet_Version
func SKY_wallet_Wallet_Version(_w C.Wallet__Handle, _arg0 *C.GoString_) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	__arg0 := w.Version()
	copyString(__arg0, _arg0)
	return
}

//export SKY_wallet_Wallet_Filename
func SKY_wallet_Wallet_Filename(_w C.Wallet__Handle, _arg0 *C.GoString_) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	__arg0 := w.Filename()
	copyString(__arg0, _arg0)
	return
}

//export SKY_wallet_Wallet_Label
func SKY_wallet_Wallet_Label(_w C.Wallet__Handle, _arg0 *C.GoString_) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	__arg0 := w.Label()
	copyString(__arg0, _arg0)
	return
}

//export SKY_wallet_Wallet_IsEncrypted
func SKY_wallet_Wallet_IsEncrypted(_w C.Wallet__Handle, _arg0 *bool) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	__arg0 := w.IsEncrypted()
	*_arg0 = __arg0
	return
}

//export SKY_wallet_Wallet_GenerateAddresses
func SKY_wallet_Wallet_GenerateAddresses(_w C.Wallet__Handle, _num uint64, _arg1 *C.GoSlice_) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	num := _num
	__arg1, ____return_err := w.GenerateAddresses(num)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
		copyToGoSlice(reflect.ValueOf(__arg1), _arg1)
	}
	return
}

//export SKY_wallet_Wallet_GetAddresses
func SKY_wallet_Wallet_GetAddresses(_w C.Wallet__Handle, _arg0 *C.GoSlice_) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	__arg0 := w.GetAddresses()
	copyToGoSlice(reflect.ValueOf(__arg0), _arg0)
	return
}

//export SKY_wallet_Wallet_GetEntry
func SKY_wallet_Wallet_GetEntry(_w C.Wallet__Handle, _a *C.cipher__Address, _arg1 *C.wallet__Entry, _arg2 *bool) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	a := *(*cipher.Address)(unsafe.Pointer(_a))
	__arg1, __arg2 := w.GetEntry(a)
	*_arg1 = *(*C.wallet__Entry)(unsafe.Pointer(&__arg1))
	*_arg2 = __arg2
	return
}

//export SKY_wallet_Wallet_AddEntry
func SKY_wallet_Wallet_AddEntry(_w C.Wallet__Handle, _entry *C.wallet__Entry) (____error_code uint32) {
	w, okw := lookupWalletHandle(_w)
	if !okw {
		____error_code = SKY_BAD_HANDLE
		return
	}
	entry := *(*wallet.Entry)(unsafe.Pointer(_entry))
	____return_err := w.AddEntry(entry)
	____error_code = libErrorCode(____return_err)
	if ____return_err == nil {
	}
	return
}
