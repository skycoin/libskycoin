# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`struct `[`_json_object_entry`](#struct__json__object__entry) | 
`struct `[`_json_value`](#struct__json__value) | 
`struct `[`api__NetworkConnectionsFilter`](#structapi_____network_connections_filter) | 
`struct `[`api__RichlistParams`](#structapi_____richlist_params) | 
`struct `[`cipher__Address`](#structcipher_____address) | Addresses of SKY accounts
`struct `[`cipher__BitcoinAddress`](#structcipher_____bitcoin_address) | Addresses of Bitcoin accounts
`struct `[`cipher_Addresses`](#structcipher___addresses) | 
`struct `[`cipher_Checksum`](#structcipher___checksum) | 
`struct `[`cipher_PubKey`](#structcipher___pub_key) | 
`struct `[`cipher_PubKeys`](#structcipher___pub_keys) | 
`struct `[`cipher_Ripemd160`](#structcipher___ripemd160) | 
`struct `[`cipher_SecKey`](#structcipher___sec_key) | 
`struct `[`cipher_SecKeys`](#structcipher___sec_keys) | 
`struct `[`cipher_SHA256`](#structcipher___s_h_a256) | 
`struct `[`cipher_SHA256s`](#structcipher___s_h_a256s) | 
`struct `[`cipher_Sig`](#structcipher___sig) | 
`struct `[`cli__SendAmount`](#structcli_____send_amount) | Structure used to specify amounts transferred in a transaction.
`struct `[`coin__Block`](#structcoin_____block) | 
`struct `[`coin__BlockBody`](#structcoin_____block_body) | 
`struct `[`coin__BlockHeader`](#structcoin_____block_header) | 
`struct `[`coin__SignedBlock`](#structcoin_____signed_block) | 
`struct `[`coin__Transaction`](#structcoin_____transaction) | Skycoin transaction.
`struct `[`coin__TransactionOutput`](#structcoin_____transaction_output) | Skycoin transaction output.
`struct `[`coin__UxBody`](#structcoin_____ux_body) | 
`struct `[`coin__UxHead`](#structcoin_____ux_head) | 
`struct `[`coin__UxOut`](#structcoin_____ux_out) | 
`struct `[`coin_UxOutArray`](#structcoin___ux_out_array) | 
`struct `[`cr_mem`](#structcr__mem) | 
`struct `[`encrypt__ScryptChacha20poly1305`](#structencrypt_____scrypt_chacha20poly1305) | 
`struct `[`Fee_Calculator`](#struct_fee___calculator) | 
`struct `[`FeeCalculator`](#struct_fee_calculator) | 
`struct `[`GoComplex128_`](#struct_go_complex128__) | Instances of Go `complex` type.
`struct `[`GoComplex64_`](#struct_go_complex64__) | Instances of Go `complex` type.
`struct `[`GoInterface_`](#struct_go_interface__) | Instances of Go interface types.
`struct `[`GoSlice_`](#struct_go_slice__) | Instances of Go slices
`struct `[`GoString_`](#struct_go_string__) | Instances of Go `string` type.
`struct `[`httphelper__Address`](#structhttphelper_____address) | 
`struct `[`httphelper__SHA256`](#structhttphelper_____s_h_a256) | 
`struct `[`InputTestData`](#struct_input_test_data) | 
`struct `[`InputTestDataJSON`](#struct_input_test_data_j_s_o_n) | 
`struct `[`json_settings`](#structjson__settings) | 
`struct `[`KeysTestData`](#struct_keys_test_data) | 
`struct `[`KeysTestDataJSON`](#struct_keys_test_data_j_s_o_n) | 
`struct `[`Number`](#struct_number) | 
`struct `[`secp256k1go__Field`](#structsecp256k1go_____field) | 
`struct `[`secp256k1go__XY`](#structsecp256k1go_____x_y) | 
`struct `[`secp256k1go__XYZ`](#structsecp256k1go_____x_y_z) | 
`struct `[`SeedTestData`](#struct_seed_test_data) | 
`struct `[`SeedTestDataJSON`](#struct_seed_test_data_j_s_o_n) | 
`struct `[`Signature`](#struct_signature) | 
`struct `[`Wallet`](#struct_wallet) | Internal representation of a Skycoin wallet.
`struct `[`wallet__Balance`](#structwallet_____balance) | 
`struct `[`wallet__BalancePair`](#structwallet_____balance_pair) | 
`struct `[`wallet__Entry`](#structwallet_____entry) | [Wallet](#struct_wallet) entry.
`struct `[`wallet__Note`](#structwallet_____note) | 
`struct `[`wallet__ReadableNote`](#structwallet_____readable_note) | 
`struct `[`wallet__UxBalance`](#structwallet_____ux_balance) | Intermediate representation of a UxOut for sorting and spend choosing.

# struct `_json_object_entry` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public json_char * `[`name`](#struct__json__object__entry_1a3c3e575cdb04c92d1bd8e2ffbfd871cc) | 
`public unsigned int `[`name_length`](#struct__json__object__entry_1a3f3f10ffae1e364e84a38517a174b01e) | 
`public struct `[`_json_value`](#struct__json__value)` * `[`value`](#struct__json__object__entry_1ae4f19c247094dd7870bfbf798d79ac99) | 

## Members

#### `public json_char * `[`name`](#struct__json__object__entry_1a3c3e575cdb04c92d1bd8e2ffbfd871cc) 

#### `public unsigned int `[`name_length`](#struct__json__object__entry_1a3f3f10ffae1e364e84a38517a174b01e) 

#### `public struct `[`_json_value`](#struct__json__value)` * `[`value`](#struct__json__object__entry_1ae4f19c247094dd7870bfbf798d79ac99) 

# struct `_json_value` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public struct `[`_json_value`](#struct__json__value)` * `[`parent`](#struct__json__value_1aa86e0e17a210b00b008a001e866050cd) | 
`public json_type `[`type`](#struct__json__value_1a5b632686c28261d4d52390dfc8dc0dcd) | 
`public int `[`boolean`](#struct__json__value_1afc58e0c0df35925913174accbf1114cb) | 
`public json_int_t `[`integer`](#struct__json__value_1a45f8bcb9c0a1417f182d41049a2107e5) | 
`public double `[`dbl`](#struct__json__value_1a57291299e530453fdec37a931c728239) | 
`public unsigned int `[`length`](#struct__json__value_1ac8d42bcd4a44e078047ccd7291059238) | 
`public json_char * `[`ptr`](#struct__json__value_1af340cb5b3b56fa2cc2b043529017fd3a) | 
`public struct _json_value::@0::@2 `[`string`](#struct__json__value_1adbf96c673bfce83dd224c60f5a1eedc4) | 
`public `[`json_object_entry`](#struct__json__object__entry)` * `[`values`](#struct__json__value_1a35eecbf6405a59adaf2c2001b9b224b0) | 
`public struct _json_value::@0::@3 `[`object`](#struct__json__value_1a67174883be078cb852d4748b78aa60ce) | 
`public struct `[`_json_value`](#struct__json__value)` ** `[`values`](#struct__json__value_1a6244a16657c988883bbb1fa7f1f0ba55) | 
`public struct _json_value::@0::@4 `[`array`](#struct__json__value_1ac837a4233a38fcd3c3d51da2c3a56f0c) | 
`public union _json_value::@0 `[`u`](#struct__json__value_1a2e5a72cccd43ae6e6b1dc476fc327d17) | 
`public struct `[`_json_value`](#struct__json__value)` * `[`next_alloc`](#struct__json__value_1a6b6c655ef17b09a6ea18d94612a27304) | 
`public void * `[`object_mem`](#struct__json__value_1aa166262c3b34bfb69a85f6e625970226) | 
`public union _json_value::@1 `[`_reserved`](#struct__json__value_1ac7cdbd31aad7b4a672e38721c1122f35) | 

## Members

#### `public struct `[`_json_value`](#struct__json__value)` * `[`parent`](#struct__json__value_1aa86e0e17a210b00b008a001e866050cd) 

#### `public json_type `[`type`](#struct__json__value_1a5b632686c28261d4d52390dfc8dc0dcd) 

#### `public int `[`boolean`](#struct__json__value_1afc58e0c0df35925913174accbf1114cb) 

#### `public json_int_t `[`integer`](#struct__json__value_1a45f8bcb9c0a1417f182d41049a2107e5) 

#### `public double `[`dbl`](#struct__json__value_1a57291299e530453fdec37a931c728239) 

#### `public unsigned int `[`length`](#struct__json__value_1ac8d42bcd4a44e078047ccd7291059238) 

#### `public json_char * `[`ptr`](#struct__json__value_1af340cb5b3b56fa2cc2b043529017fd3a) 

#### `public struct _json_value::@0::@2 `[`string`](#struct__json__value_1adbf96c673bfce83dd224c60f5a1eedc4) 

#### `public `[`json_object_entry`](#struct__json__object__entry)` * `[`values`](#struct__json__value_1a35eecbf6405a59adaf2c2001b9b224b0) 

#### `public struct _json_value::@0::@3 `[`object`](#struct__json__value_1a67174883be078cb852d4748b78aa60ce) 

#### `public struct `[`_json_value`](#struct__json__value)` ** `[`values`](#struct__json__value_1a6244a16657c988883bbb1fa7f1f0ba55) 

#### `public struct _json_value::@0::@4 `[`array`](#struct__json__value_1ac837a4233a38fcd3c3d51da2c3a56f0c) 

#### `public union _json_value::@0 `[`u`](#struct__json__value_1a2e5a72cccd43ae6e6b1dc476fc327d17) 

#### `public struct `[`_json_value`](#struct__json__value)` * `[`next_alloc`](#struct__json__value_1a6b6c655ef17b09a6ea18d94612a27304) 

#### `public void * `[`object_mem`](#struct__json__value_1aa166262c3b34bfb69a85f6e625970226) 

#### `public union _json_value::@1 `[`_reserved`](#struct__json__value_1ac7cdbd31aad7b4a672e38721c1122f35) 

# struct `api__NetworkConnectionsFilter` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`GoString_`](#struct_go_string__)` `[`States`](#structapi_____network_connections_filter_1aadc5a43c4721265d5e7c507e5bbef628) | 
`public `[`GoString_`](#struct_go_string__)` `[`Direction`](#structapi_____network_connections_filter_1aa7b6314710356d969facc923f8b1962e) | 

## Members

#### `public `[`GoString_`](#struct_go_string__)` `[`States`](#structapi_____network_connections_filter_1aadc5a43c4721265d5e7c507e5bbef628) 

#### `public `[`GoString_`](#struct_go_string__)` `[`Direction`](#structapi_____network_connections_filter_1aa7b6314710356d969facc923f8b1962e) 

# struct `api__RichlistParams` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoInt_ `[`N`](#structapi_____richlist_params_1a9341d3d326cce1ab3e82bf4223d61631) | 
`public BOOL `[`IncludeDistribution`](#structapi_____richlist_params_1a77a606b3480624b44e5cf95ad5fe5fe5) | 

## Members

#### `public GoInt_ `[`N`](#structapi_____richlist_params_1a9341d3d326cce1ab3e82bf4223d61631) 

#### `public BOOL `[`IncludeDistribution`](#structapi_____richlist_params_1a77a606b3480624b44e5cf95ad5fe5fe5) 

# struct `cipher__Address` 

Addresses of SKY accounts

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8_ `[`Version`](#structcipher_____address_1a606dc32a5b849202a1bd5ab70ec7c3f0) | Address version identifier. Used to differentiate testnet vs mainnet addresses, for ins
`public cipher__Ripemd160 `[`Key`](#structcipher_____address_1a16586cd3bfc67010c3c185d0da01317c) | Address hash identifier.

## Members

#### `public GoUint8_ `[`Version`](#structcipher_____address_1a606dc32a5b849202a1bd5ab70ec7c3f0) 

Address version identifier. Used to differentiate testnet vs mainnet addresses, for ins

#### `public cipher__Ripemd160 `[`Key`](#structcipher_____address_1a16586cd3bfc67010c3c185d0da01317c) 

Address hash identifier.

# struct `cipher__BitcoinAddress` 

Addresses of Bitcoin accounts

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8_ `[`Version`](#structcipher_____bitcoin_address_1a606dc32a5b849202a1bd5ab70ec7c3f0) | Address version identifier. Used to differentiate testnet vs mainnet addresses, for instance.
`public cipher__Ripemd160 `[`Key`](#structcipher_____bitcoin_address_1a16586cd3bfc67010c3c185d0da01317c) | Address hash identifier.

## Members

#### `public GoUint8_ `[`Version`](#structcipher_____bitcoin_address_1a606dc32a5b849202a1bd5ab70ec7c3f0) 

Address version identifier. Used to differentiate testnet vs mainnet addresses, for instance.

#### `public cipher__Ripemd160 `[`Key`](#structcipher_____bitcoin_address_1a16586cd3bfc67010c3c185d0da01317c) 

Address hash identifier.

# struct `cipher_Addresses` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher__Address`](#structcipher_____address)` * `[`data`](#structcipher___addresses_1a64c43e3b2bdb0384e70ff35c301f6d48) | 
`public int `[`count`](#structcipher___addresses_1ad43c3812e6d13e0518d9f8b8f463ffcf) | 

## Members

#### `public `[`cipher__Address`](#structcipher_____address)` * `[`data`](#structcipher___addresses_1a64c43e3b2bdb0384e70ff35c301f6d48) 

#### `public int `[`count`](#structcipher___addresses_1ad43c3812e6d13e0518d9f8b8f463ffcf) 

# struct `cipher_Checksum` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8 `[`data`](#structcipher___checksum_1af2b5494d85bbe57bdc0e0284c687dbe7) | 

## Members

#### `public GoUint8 `[`data`](#structcipher___checksum_1af2b5494d85bbe57bdc0e0284c687dbe7) 

# struct `cipher_PubKey` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8 `[`data`](#structcipher___pub_key_1a3d3ea6251fa06829c27e1305d1273f83) | 

## Members

#### `public GoUint8 `[`data`](#structcipher___pub_key_1a3d3ea6251fa06829c27e1305d1273f83) 

# struct `cipher_PubKeys` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher_PubKey`](#structcipher___pub_key)` * `[`data`](#structcipher___pub_keys_1ad1e8d7c9e96a254032b925957a69c5fc) | 
`public int `[`count`](#structcipher___pub_keys_1ad43c3812e6d13e0518d9f8b8f463ffcf) | 

## Members

#### `public `[`cipher_PubKey`](#structcipher___pub_key)` * `[`data`](#structcipher___pub_keys_1ad1e8d7c9e96a254032b925957a69c5fc) 

#### `public int `[`count`](#structcipher___pub_keys_1ad43c3812e6d13e0518d9f8b8f463ffcf) 

# struct `cipher_Ripemd160` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8 `[`data`](#structcipher___ripemd160_1ad270f78d3abe5fdbc9c63b9f2b66063e) | 

## Members

#### `public GoUint8 `[`data`](#structcipher___ripemd160_1ad270f78d3abe5fdbc9c63b9f2b66063e) 

# struct `cipher_SecKey` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8 `[`data`](#structcipher___sec_key_1a0a1a4b21103f9c48a4ba08e82d8f0976) | 

## Members

#### `public GoUint8 `[`data`](#structcipher___sec_key_1a0a1a4b21103f9c48a4ba08e82d8f0976) 

# struct `cipher_SecKeys` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher_SecKey`](#structcipher___sec_key)` * `[`data`](#structcipher___sec_keys_1a6cc7dc96b18d848347e7d0a7f8c1604c) | 
`public int `[`count`](#structcipher___sec_keys_1ad43c3812e6d13e0518d9f8b8f463ffcf) | 

## Members

#### `public `[`cipher_SecKey`](#structcipher___sec_key)` * `[`data`](#structcipher___sec_keys_1a6cc7dc96b18d848347e7d0a7f8c1604c) 

#### `public int `[`count`](#structcipher___sec_keys_1ad43c3812e6d13e0518d9f8b8f463ffcf) 

# struct `cipher_SHA256` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8 `[`data`](#structcipher___s_h_a256_1a0a1a4b21103f9c48a4ba08e82d8f0976) | 

## Members

#### `public GoUint8 `[`data`](#structcipher___s_h_a256_1a0a1a4b21103f9c48a4ba08e82d8f0976) 

# struct `cipher_SHA256s` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher_SHA256`](#structcipher___s_h_a256)` * `[`data`](#structcipher___s_h_a256s_1a731288d0297a94e8b6817872c8a36536) | 
`public int `[`count`](#structcipher___s_h_a256s_1ad43c3812e6d13e0518d9f8b8f463ffcf) | 

## Members

#### `public `[`cipher_SHA256`](#structcipher___s_h_a256)` * `[`data`](#structcipher___s_h_a256s_1a731288d0297a94e8b6817872c8a36536) 

#### `public int `[`count`](#structcipher___s_h_a256s_1ad43c3812e6d13e0518d9f8b8f463ffcf) 

# struct `cipher_Sig` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint8 `[`data`](#structcipher___sig_1acfabdfac9f5f366a659ba0288fcc4aba) | 

## Members

#### `public GoUint8 `[`data`](#structcipher___sig_1acfabdfac9f5f366a659ba0288fcc4aba) 

# struct `cli__SendAmount` 

Structure used to specify amounts transferred in a transaction.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`GoString_`](#struct_go_string__)` `[`Addr`](#structcli_____send_amount_1af646aec99cf83d30d17fd62e014d19f8) | Sender / receipient address.
`public GoInt64_ `[`Coins`](#structcli_____send_amount_1a7733f16af3115d3cfc712f2f687b73e4) | Amount transferred (e.g. measured in SKY)

## Members

#### `public `[`GoString_`](#struct_go_string__)` `[`Addr`](#structcli_____send_amount_1af646aec99cf83d30d17fd62e014d19f8) 

Sender / receipient address.

#### `public GoInt64_ `[`Coins`](#structcli_____send_amount_1a7733f16af3115d3cfc712f2f687b73e4) 

Amount transferred (e.g. measured in SKY)

# struct `coin__Block` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`coin__BlockHeader`](#structcoin_____block_header)` `[`Head`](#structcoin_____block_1a64c1bf574366c3afc7adc2af819adafe) | 
`public `[`coin__BlockBody`](#structcoin_____block_body)` `[`Body`](#structcoin_____block_1a59caa9af8b9909183c8b9831444b7633) | 

## Members

#### `public `[`coin__BlockHeader`](#structcoin_____block_header)` `[`Head`](#structcoin_____block_1a64c1bf574366c3afc7adc2af819adafe) 

#### `public `[`coin__BlockBody`](#structcoin_____block_body)` `[`Body`](#structcoin_____block_1a59caa9af8b9909183c8b9831444b7633) 

# struct `coin__BlockBody` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`coin__Transactions`](#struct_go_slice__)` `[`Transactions`](#structcoin_____block_body_1a95a9585b57fa4742b7be88c7f2a6d42c) | 

## Members

#### `public `[`coin__Transactions`](#struct_go_slice__)` `[`Transactions`](#structcoin_____block_body_1a95a9585b57fa4742b7be88c7f2a6d42c) 

# struct `coin__BlockHeader` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint32_ `[`Version`](#structcoin_____block_header_1a3b774030b8018017c41c377d74512089) | 
`public GoUint64_ `[`Time`](#structcoin_____block_header_1a1260435bd13330d2d5c2c61d044b1603) | 
`public GoUint64_ `[`BkSeq`](#structcoin_____block_header_1a5f647c638c8d6a7e2b9ba8b409bf94f2) | 
`public GoUint64_ `[`Fee`](#structcoin_____block_header_1af9cf0d58378a9d4cebbd504006db852d) | 
`public cipher__SHA256 `[`PrevHash`](#structcoin_____block_header_1a4787d7554bca4e07b6c7538a1aa70d17) | 
`public cipher__SHA256 `[`BodyHash`](#structcoin_____block_header_1a4101954b75ceebe672014e6313074225) | 
`public cipher__SHA256 `[`UxHash`](#structcoin_____block_header_1ae2ed7673c2a3cd72f697835bebab9cd5) | 

## Members

#### `public GoUint32_ `[`Version`](#structcoin_____block_header_1a3b774030b8018017c41c377d74512089) 

#### `public GoUint64_ `[`Time`](#structcoin_____block_header_1a1260435bd13330d2d5c2c61d044b1603) 

#### `public GoUint64_ `[`BkSeq`](#structcoin_____block_header_1a5f647c638c8d6a7e2b9ba8b409bf94f2) 

#### `public GoUint64_ `[`Fee`](#structcoin_____block_header_1af9cf0d58378a9d4cebbd504006db852d) 

#### `public cipher__SHA256 `[`PrevHash`](#structcoin_____block_header_1a4787d7554bca4e07b6c7538a1aa70d17) 

#### `public cipher__SHA256 `[`BodyHash`](#structcoin_____block_header_1a4101954b75ceebe672014e6313074225) 

#### `public cipher__SHA256 `[`UxHash`](#structcoin_____block_header_1ae2ed7673c2a3cd72f697835bebab9cd5) 

# struct `coin__SignedBlock` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`coin__Block`](#structcoin_____block)` `[`_unnamed`](#structcoin_____signed_block_1a891758f1c7853767c037ca433f977565) | 
`public cipher__Sig `[`Sig`](#structcoin_____signed_block_1a3dc2280cefb5cc2f3ddb00ab7adc66a4) | 

## Members

#### `public `[`coin__Block`](#structcoin_____block)` `[`_unnamed`](#structcoin_____signed_block_1a891758f1c7853767c037ca433f977565) 

#### `public cipher__Sig `[`Sig`](#structcoin_____signed_block_1a3dc2280cefb5cc2f3ddb00ab7adc66a4) 

# struct `coin__Transaction` 

Skycoin transaction.

Instances of this struct are included in blocks.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoInt32_ `[`Length`](#structcoin_____transaction_1a8a3c288e7b3f7245e0b7916ce322e5f9) | Current transaction's length expressed in bytes.
`public GoInt8_ `[`Type`](#structcoin_____transaction_1a5bf4f40bde41c84f4ab5ff82bc74f744) | Transaction's version. When a node tries to process a transaction, it must verify whether it supports the transaction's type. This is intended to provide a way to update skycoin clients and servers without crashing the network. If the transaction is not compatible with the node, it should not process it.
`public cipher__SHA256 `[`InnerHash`](#structcoin_____transaction_1af5187a82f283be2deca0f1781fa628ad) | It's a SHA256 hash of the inputs and outputs of the transaction. It is used to protect against transaction mutability. This means that the transaction cannot be altered after its creation.
`public `[`GoSlice_`](#struct_go_slice__)` `[`Sigs`](#structcoin_____transaction_1af0a2ba807a16f9ae66dd5682c243b943) | A list of digital signiatures generated by the skycoin client using the private key. It is used by Skycoin servers to verify the authenticy of the transaction. Each input requires a different signature.
`public `[`GoSlice_`](#struct_go_slice__)` `[`In`](#structcoin_____transaction_1a317b73fcfa2b93fd16dfeab7ba228c39) | A list of references to unspent transaction outputs. Unlike other cryptocurrencies, such as Bitcoin, Skycoin unspent transaction outputs (UX) and Skycoin transactions (TX) are separated in the blockchain protocol, allowing for lighter transactions, thus reducing the broadcasting costs across the network.
`public `[`GoSlice_`](#struct_go_slice__)` `[`Out`](#structcoin_____transaction_1a181edcb164c89b192b3838de7792cc89) | Outputs: A list of outputs created by the client, that will be recorded in the blockchain if transactions are confirmed. An output consists of a data structure representing an UTXT, which is composed by a Skycoin address to be sent to, the amount in Skycoin to be sent, and the amount of Coin Hours to be sent, and the SHA256 hash of the previous fields.

## Members

#### `public GoInt32_ `[`Length`](#structcoin_____transaction_1a8a3c288e7b3f7245e0b7916ce322e5f9) 

Current transaction's length expressed in bytes.

#### `public GoInt8_ `[`Type`](#structcoin_____transaction_1a5bf4f40bde41c84f4ab5ff82bc74f744) 

Transaction's version. When a node tries to process a transaction, it must verify whether it supports the transaction's type. This is intended to provide a way to update skycoin clients and servers without crashing the network. If the transaction is not compatible with the node, it should not process it.

#### `public cipher__SHA256 `[`InnerHash`](#structcoin_____transaction_1af5187a82f283be2deca0f1781fa628ad) 

It's a SHA256 hash of the inputs and outputs of the transaction. It is used to protect against transaction mutability. This means that the transaction cannot be altered after its creation.

#### `public `[`GoSlice_`](#struct_go_slice__)` `[`Sigs`](#structcoin_____transaction_1af0a2ba807a16f9ae66dd5682c243b943) 

A list of digital signiatures generated by the skycoin client using the private key. It is used by Skycoin servers to verify the authenticy of the transaction. Each input requires a different signature.

#### `public `[`GoSlice_`](#struct_go_slice__)` `[`In`](#structcoin_____transaction_1a317b73fcfa2b93fd16dfeab7ba228c39) 

A list of references to unspent transaction outputs. Unlike other cryptocurrencies, such as Bitcoin, Skycoin unspent transaction outputs (UX) and Skycoin transactions (TX) are separated in the blockchain protocol, allowing for lighter transactions, thus reducing the broadcasting costs across the network.

#### `public `[`GoSlice_`](#struct_go_slice__)` `[`Out`](#structcoin_____transaction_1a181edcb164c89b192b3838de7792cc89) 

Outputs: A list of outputs created by the client, that will be recorded in the blockchain if transactions are confirmed. An output consists of a data structure representing an UTXT, which is composed by a Skycoin address to be sent to, the amount in Skycoin to be sent, and the amount of Coin Hours to be sent, and the SHA256 hash of the previous fields.

# struct `coin__TransactionOutput` 

Skycoin transaction output.

Instances are integral part of transactions included in blocks.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structcoin_____transaction_output_1a36182709852829827005f90eef8bf78c) | Receipient address.
`public GoUint64_ `[`Coins`](#structcoin_____transaction_output_1aa8ecc8470e80feb9af67d2e39d01b1eb) | Amount sent to the receipient address.
`public GoUint64_ `[`Hours`](#structcoin_____transaction_output_1a527c44c111577ee7ae35d7a53ab11332) | Amount of Coin Hours sent to the receipient address.

## Members

#### `public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structcoin_____transaction_output_1a36182709852829827005f90eef8bf78c) 

Receipient address.

#### `public GoUint64_ `[`Coins`](#structcoin_____transaction_output_1aa8ecc8470e80feb9af67d2e39d01b1eb) 

Amount sent to the receipient address.

#### `public GoUint64_ `[`Hours`](#structcoin_____transaction_output_1a527c44c111577ee7ae35d7a53ab11332) 

Amount of Coin Hours sent to the receipient address.

# struct `coin__UxBody` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public cipher__SHA256 `[`SrcTransaction`](#structcoin_____ux_body_1a94a1b2134fcadb6f35f5a1573f771cde) | 
`public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structcoin_____ux_body_1a36182709852829827005f90eef8bf78c) | 
`public GoUint64_ `[`Coins`](#structcoin_____ux_body_1aa8ecc8470e80feb9af67d2e39d01b1eb) | 
`public GoUint64_ `[`Hours`](#structcoin_____ux_body_1a527c44c111577ee7ae35d7a53ab11332) | 

## Members

#### `public cipher__SHA256 `[`SrcTransaction`](#structcoin_____ux_body_1a94a1b2134fcadb6f35f5a1573f771cde) 

#### `public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structcoin_____ux_body_1a36182709852829827005f90eef8bf78c) 

#### `public GoUint64_ `[`Coins`](#structcoin_____ux_body_1aa8ecc8470e80feb9af67d2e39d01b1eb) 

#### `public GoUint64_ `[`Hours`](#structcoin_____ux_body_1a527c44c111577ee7ae35d7a53ab11332) 

# struct `coin__UxHead` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint64_ `[`Time`](#structcoin_____ux_head_1a1260435bd13330d2d5c2c61d044b1603) | 
`public GoUint64_ `[`BkSeq`](#structcoin_____ux_head_1a5f647c638c8d6a7e2b9ba8b409bf94f2) | 

## Members

#### `public GoUint64_ `[`Time`](#structcoin_____ux_head_1a1260435bd13330d2d5c2c61d044b1603) 

#### `public GoUint64_ `[`BkSeq`](#structcoin_____ux_head_1a5f647c638c8d6a7e2b9ba8b409bf94f2) 

# struct `coin__UxOut` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`coin__UxHead`](#structcoin_____ux_head)` `[`Head`](#structcoin_____ux_out_1ad77c0fb7d1545bcda1657269eab9721c) | 
`public `[`coin__UxBody`](#structcoin_____ux_body)` `[`Body`](#structcoin_____ux_out_1a29e9173d148f64e9129d98a8d9bf5ed2) | 

## Members

#### `public `[`coin__UxHead`](#structcoin_____ux_head)` `[`Head`](#structcoin_____ux_out_1ad77c0fb7d1545bcda1657269eab9721c) 

#### `public `[`coin__UxBody`](#structcoin_____ux_body)` `[`Body`](#structcoin_____ux_out_1a29e9173d148f64e9129d98a8d9bf5ed2) 

# struct `coin_UxOutArray` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`coin__UxOut`](#structcoin_____ux_out)` * `[`data`](#structcoin___ux_out_array_1a406bf2d3fbcb470171cda7891e79c62a) | 
`public int `[`count`](#structcoin___ux_out_array_1ad43c3812e6d13e0518d9f8b8f463ffcf) | 

## Members

#### `public `[`coin__UxOut`](#structcoin_____ux_out)` * `[`data`](#structcoin___ux_out_array_1a406bf2d3fbcb470171cda7891e79c62a) 

#### `public int `[`count`](#structcoin___ux_out_array_1ad43c3812e6d13e0518d9f8b8f463ffcf) 

# struct `cr_mem` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public const void * `[`data`](#structcr__mem_1a0d49d74db4c035719c3867723cf7e779) | 
`public size_t `[`size`](#structcr__mem_1a854352f53b148adc24983a58a1866d66) | 

## Members

#### `public const void * `[`data`](#structcr__mem_1a0d49d74db4c035719c3867723cf7e779) 

#### `public size_t `[`size`](#structcr__mem_1a854352f53b148adc24983a58a1866d66) 

# struct `encrypt__ScryptChacha20poly1305` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoInt_ `[`N`](#structencrypt_____scrypt_chacha20poly1305_1a9341d3d326cce1ab3e82bf4223d61631) | 
`public GoInt_ `[`R`](#structencrypt_____scrypt_chacha20poly1305_1a345710bc5a459c491d371ab9882b9deb) | 
`public GoInt_ `[`P`](#structencrypt_____scrypt_chacha20poly1305_1af70f5e03c75f91949266955080b31138) | 
`public GoInt_ `[`KeyLen`](#structencrypt_____scrypt_chacha20poly1305_1a4da9e58cf088f5ea728571a8fa88c141) | 

## Members

#### `public GoInt_ `[`N`](#structencrypt_____scrypt_chacha20poly1305_1a9341d3d326cce1ab3e82bf4223d61631) 

#### `public GoInt_ `[`R`](#structencrypt_____scrypt_chacha20poly1305_1a345710bc5a459c491d371ab9882b9deb) 

#### `public GoInt_ `[`P`](#structencrypt_____scrypt_chacha20poly1305_1af70f5e03c75f91949266955080b31138) 

#### `public GoInt_ `[`KeyLen`](#structencrypt_____scrypt_chacha20poly1305_1a4da9e58cf088f5ea728571a8fa88c141) 

# struct `Fee_Calculator` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FeeCalcFunc `[`callback`](#struct_fee___calculator_1ace64cc72910e5458a0b8098af37a57a1) | 
`public void * `[`context`](#struct_fee___calculator_1ae376f130b17d169ee51be68077a89ed0) | 

## Members

#### `public FeeCalcFunc `[`callback`](#struct_fee___calculator_1ace64cc72910e5458a0b8098af37a57a1) 

#### `public void * `[`context`](#struct_fee___calculator_1ae376f130b17d169ee51be68077a89ed0) 

# struct `FeeCalculator` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public FeeCalcFunc `[`callback`](#struct_fee_calculator_1ace64cc72910e5458a0b8098af37a57a1) | 
`public void * `[`context`](#struct_fee_calculator_1ae376f130b17d169ee51be68077a89ed0) | 

## Members

#### `public FeeCalcFunc `[`callback`](#struct_fee_calculator_1ace64cc72910e5458a0b8098af37a57a1) 

#### `public void * `[`context`](#struct_fee_calculator_1ae376f130b17d169ee51be68077a89ed0) 

# struct `GoComplex128_` 

Instances of Go `complex` type.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`real`](#struct_go_complex128___1a51c821fcf95975271abfc49311e983d4) | 
`public double `[`imaginary`](#struct_go_complex128___1a92dcee8df01cf892620da47f14b8e102) | 

## Members

#### `public double `[`real`](#struct_go_complex128___1a51c821fcf95975271abfc49311e983d4) 

#### `public double `[`imaginary`](#struct_go_complex128___1a92dcee8df01cf892620da47f14b8e102) 

# struct `GoComplex64_` 

Instances of Go `complex` type.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`real`](#struct_go_complex64___1a06ed4269b34924d748f2f77b17db7d21) | 
`public float `[`imaginary`](#struct_go_complex64___1aa4331a3d00f2e714f1cb72efe5ca590e) | 

## Members

#### `public float `[`real`](#struct_go_complex64___1a06ed4269b34924d748f2f77b17db7d21) 

#### `public float `[`imaginary`](#struct_go_complex64___1aa4331a3d00f2e714f1cb72efe5ca590e) 

# struct `GoInterface_` 

Instances of Go interface types.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void * `[`t`](#struct_go_interface___1a6445205ee90f5ff5131595cf7ddfcec0) | Pointer to the information of the concrete Go type bound to this interface reference.
`public void * `[`v`](#struct_go_interface___1a67806b49e20fb1170422969965db6ecb) | Pointer to the data corresponding to the value bound to this interface type.

## Members

#### `public void * `[`t`](#struct_go_interface___1a6445205ee90f5ff5131595cf7ddfcec0) 

Pointer to the information of the concrete Go type bound to this interface reference.

#### `public void * `[`v`](#struct_go_interface___1a67806b49e20fb1170422969965db6ecb) 

Pointer to the data corresponding to the value bound to this interface type.

# struct `GoSlice_` 

Instances of Go slices

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void * `[`data`](#struct_go_slice___1a735984d41155bc1032e09bece8f8d66d) | Pointer to buffer containing slice data.
`public GoInt_ `[`len`](#struct_go_slice___1af7b822f9987d08af70f228eb6dd4b7c7) | [Number](#struct_number) of items stored in slice buffer.
`public GoInt_ `[`cap`](#struct_go_slice___1abb0492bac72ee60cd3cafd152291df94) | Maximum number of items that fits in this slice considering allocated memory and item type's size.

## Members

#### `public void * `[`data`](#struct_go_slice___1a735984d41155bc1032e09bece8f8d66d) 

Pointer to buffer containing slice data.

#### `public GoInt_ `[`len`](#struct_go_slice___1af7b822f9987d08af70f228eb6dd4b7c7) 

[Number](#struct_number) of items stored in slice buffer.

#### `public GoInt_ `[`cap`](#struct_go_slice___1abb0492bac72ee60cd3cafd152291df94) 

Maximum number of items that fits in this slice considering allocated memory and item type's size.

# struct `GoString_` 

Instances of Go `string` type.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public const char * `[`p`](#struct_go_string___1a6bc6b007533335efe02bafff799ec64c) | Pointer to string characters buffer.
`public GoInt_ `[`n`](#struct_go_string___1aa78f60eaaf1d3eb1661886a694b82b23) | String size not counting trailing `\0` char if at all included.

## Members

#### `public const char * `[`p`](#struct_go_string___1a6bc6b007533335efe02bafff799ec64c) 

Pointer to string characters buffer.

#### `public GoInt_ `[`n`](#struct_go_string___1aa78f60eaaf1d3eb1661886a694b82b23) 

String size not counting trailing `\0` char if at all included.

# struct `httphelper__Address` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher__Address`](#structcipher_____address)` `[`_unnamed`](#structhttphelper_____address_1aad3e0caa43af2dc583e1a8cb47357088) | 

## Members

#### `public `[`cipher__Address`](#structcipher_____address)` `[`_unnamed`](#structhttphelper_____address_1aad3e0caa43af2dc583e1a8cb47357088) 

# struct `httphelper__SHA256` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public cipher__SHA256 `[`_unnamed`](#structhttphelper_____s_h_a256_1a7799a54f739725769994b5bcfc44ecfb) | 

## Members

#### `public cipher__SHA256 `[`_unnamed`](#structhttphelper_____s_h_a256_1a7799a54f739725769994b5bcfc44ecfb) 

# struct `InputTestData` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoSlice `[`Hashes`](#struct_input_test_data_1ad0e54a71fc762f7f7c7765162e1a738a) | 

## Members

#### `public GoSlice `[`Hashes`](#struct_input_test_data_1ad0e54a71fc762f7f7c7765162e1a738a) 

# struct `InputTestDataJSON` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoSlice `[`Hashes`](#struct_input_test_data_j_s_o_n_1ad0e54a71fc762f7f7c7765162e1a738a) | 

## Members

#### `public GoSlice `[`Hashes`](#struct_input_test_data_j_s_o_n_1ad0e54a71fc762f7f7c7765162e1a738a) 

# struct `json_settings` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public unsigned long `[`max_memory`](#structjson__settings_1a0a75ed144583eabc50ba61e0e06abfea) | 
`public int `[`settings`](#structjson__settings_1a4bc80b14d6c1a73e1f2ff9f0375dac8b) | 
`public void *(* `[`mem_alloc`](#structjson__settings_1a2e7e359c7ea91e8a2dc289973c1a175b) | 
`public void(* `[`mem_free`](#structjson__settings_1a92bd9d811a0613553d77254839cd7bb2) | 
`public void * `[`user_data`](#structjson__settings_1a0f53d287ac7c064d1a49d4bd93ca1cb9) | 
`public size_t `[`value_extra`](#structjson__settings_1af493db885ec44977143063289b5275db) | 

## Members

#### `public unsigned long `[`max_memory`](#structjson__settings_1a0a75ed144583eabc50ba61e0e06abfea) 

#### `public int `[`settings`](#structjson__settings_1a4bc80b14d6c1a73e1f2ff9f0375dac8b) 

#### `public void *(* `[`mem_alloc`](#structjson__settings_1a2e7e359c7ea91e8a2dc289973c1a175b) 

#### `public void(* `[`mem_free`](#structjson__settings_1a92bd9d811a0613553d77254839cd7bb2) 

#### `public void * `[`user_data`](#structjson__settings_1a0f53d287ac7c064d1a49d4bd93ca1cb9) 

#### `public size_t `[`value_extra`](#structjson__settings_1af493db885ec44977143063289b5275db) 

# struct `KeysTestData` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#struct_keys_test_data_1a36182709852829827005f90eef8bf78c) | 
`public cipher__SecKey `[`Secret`](#struct_keys_test_data_1ab7c6991603c7f6e2f9a7c5b7dd580dac) | 
`public cipher__PubKey `[`Public`](#struct_keys_test_data_1a0bb45c3d09a24a1c34d376092a35dfdc) | 
`public GoSlice `[`Signatures`](#struct_keys_test_data_1ac97779b64174c30fa4cd2386f399d3b5) | 

## Members

#### `public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#struct_keys_test_data_1a36182709852829827005f90eef8bf78c) 

#### `public cipher__SecKey `[`Secret`](#struct_keys_test_data_1ab7c6991603c7f6e2f9a7c5b7dd580dac) 

#### `public cipher__PubKey `[`Public`](#struct_keys_test_data_1a0bb45c3d09a24a1c34d376092a35dfdc) 

#### `public GoSlice `[`Signatures`](#struct_keys_test_data_1ac97779b64174c30fa4cd2386f399d3b5) 

# struct `KeysTestDataJSON` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoString `[`Address`](#struct_keys_test_data_j_s_o_n_1a9d21e8a82d5c1b3ad4f8ecf6f80e62ad) | 
`public GoString `[`Secret`](#struct_keys_test_data_j_s_o_n_1a801564a19fb6529beabfd99e1f4bb12e) | 
`public GoString `[`Public`](#struct_keys_test_data_j_s_o_n_1ac024a1d14cfeb43708ca2b526f176389) | 
`public GoSlice `[`Signatures`](#struct_keys_test_data_j_s_o_n_1ac97779b64174c30fa4cd2386f399d3b5) | 

## Members

#### `public GoString `[`Address`](#struct_keys_test_data_j_s_o_n_1a9d21e8a82d5c1b3ad4f8ecf6f80e62ad) 

#### `public GoString `[`Secret`](#struct_keys_test_data_j_s_o_n_1a801564a19fb6529beabfd99e1f4bb12e) 

#### `public GoString `[`Public`](#struct_keys_test_data_j_s_o_n_1ac024a1d14cfeb43708ca2b526f176389) 

#### `public GoSlice `[`Signatures`](#struct_keys_test_data_j_s_o_n_1ac97779b64174c30fa4cd2386f399d3b5) 

# struct `Number` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public BOOL `[`neg`](#struct_number_1a41cf4ffec7c96f46c8da4178883ff147) | 
`public `[`GoSlice_`](#struct_go_slice__)` `[`nat`](#struct_number_1a5d41c00613550e6235c4cdf379c169b7) | 

## Members

#### `public BOOL `[`neg`](#struct_number_1a41cf4ffec7c96f46c8da4178883ff147) 

#### `public `[`GoSlice_`](#struct_go_slice__)` `[`nat`](#struct_number_1a5d41c00613550e6235c4cdf379c169b7) 

# struct `secp256k1go__Field` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint32_ `[`n`](#structsecp256k1go_____field_1ac59fea67392432d15cdaefebf95f0116) | 

## Members

#### `public GoUint32_ `[`n`](#structsecp256k1go_____field_1ac59fea67392432d15cdaefebf95f0116) 

# struct `secp256k1go__XY` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`X`](#structsecp256k1go_____x_y_1a62f829bef767e88f83f3c7cae1113add) | 
`public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`Y`](#structsecp256k1go_____x_y_1a0b1d10194685c0a24c7a69dfc28fc7c2) | 
`public BOOL `[`Infinity`](#structsecp256k1go_____x_y_1a919e9d6912e340dac3cbeb528c1ae997) | 

## Members

#### `public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`X`](#structsecp256k1go_____x_y_1a62f829bef767e88f83f3c7cae1113add) 

#### `public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`Y`](#structsecp256k1go_____x_y_1a0b1d10194685c0a24c7a69dfc28fc7c2) 

#### `public BOOL `[`Infinity`](#structsecp256k1go_____x_y_1a919e9d6912e340dac3cbeb528c1ae997) 

# struct `secp256k1go__XYZ` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`X`](#structsecp256k1go_____x_y_z_1a62f829bef767e88f83f3c7cae1113add) | 
`public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`Y`](#structsecp256k1go_____x_y_z_1a0b1d10194685c0a24c7a69dfc28fc7c2) | 
`public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`Z`](#structsecp256k1go_____x_y_z_1a72be6494ccdcd76d571dbddf55c5aae1) | 
`public BOOL `[`Infinity`](#structsecp256k1go_____x_y_z_1a919e9d6912e340dac3cbeb528c1ae997) | 

## Members

#### `public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`X`](#structsecp256k1go_____x_y_z_1a62f829bef767e88f83f3c7cae1113add) 

#### `public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`Y`](#structsecp256k1go_____x_y_z_1a0b1d10194685c0a24c7a69dfc28fc7c2) 

#### `public `[`secp256k1go__Field`](#structsecp256k1go_____field)` `[`Z`](#structsecp256k1go_____x_y_z_1a72be6494ccdcd76d571dbddf55c5aae1) 

#### `public BOOL `[`Infinity`](#structsecp256k1go_____x_y_z_1a919e9d6912e340dac3cbeb528c1ae997) 

# struct `SeedTestData` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoSlice `[`Seed`](#struct_seed_test_data_1ac243323ff380d4e4df1741f04f272ad7) | 
`public GoSlice `[`Keys`](#struct_seed_test_data_1af7b3b5dfe2d429d7484447fc5135c3b2) | 

## Members

#### `public GoSlice `[`Seed`](#struct_seed_test_data_1ac243323ff380d4e4df1741f04f272ad7) 

#### `public GoSlice `[`Keys`](#struct_seed_test_data_1af7b3b5dfe2d429d7484447fc5135c3b2) 

# struct `SeedTestDataJSON` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoString `[`Seed`](#struct_seed_test_data_j_s_o_n_1a276b95b641aae441b01fe35bf9ffaba1) | 
`public GoSlice `[`Keys`](#struct_seed_test_data_j_s_o_n_1af7b3b5dfe2d429d7484447fc5135c3b2) | 

## Members

#### `public GoString `[`Seed`](#struct_seed_test_data_j_s_o_n_1a276b95b641aae441b01fe35bf9ffaba1) 

#### `public GoSlice `[`Keys`](#struct_seed_test_data_j_s_o_n_1af7b3b5dfe2d429d7484447fc5135c3b2) 

# struct `Signature` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Number`](#struct_number)` `[`R`](#struct_signature_1a3796f971474f387d51b83ea0d37d1985) | 
`public `[`Number`](#struct_number)` `[`S`](#struct_signature_1a30d286a33e62ae38e1e5ee8b2b8febff) | 

## Members

#### `public `[`Number`](#struct_number)` `[`R`](#struct_signature_1a3796f971474f387d51b83ea0d37d1985) 

#### `public `[`Number`](#struct_number)` `[`S`](#struct_signature_1a30d286a33e62ae38e1e5ee8b2b8febff) 

# struct `Wallet` 

Internal representation of a Skycoin wallet.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoMap_ `[`Meta`](#struct_wallet_1acdf30a4af55c2c677ebf6fc57b27e740) | Records items that are not deterministic, like filename, lable, wallet type, secrets, etc.
`public `[`GoSlice_`](#struct_go_slice__)` `[`Entries`](#struct_wallet_1a57b718d97f8db7e0bc9d9c755510951b) | Entries field stores the address entries that are deterministically generated from seed.

## Members

#### `public GoMap_ `[`Meta`](#struct_wallet_1acdf30a4af55c2c677ebf6fc57b27e740) 

Records items that are not deterministic, like filename, lable, wallet type, secrets, etc.

#### `public `[`GoSlice_`](#struct_go_slice__)` `[`Entries`](#struct_wallet_1a57b718d97f8db7e0bc9d9c755510951b) 

Entries field stores the address entries that are deterministically generated from seed.

# struct `wallet__Balance` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public GoUint64_ `[`Coins`](#structwallet_____balance_1aa8ecc8470e80feb9af67d2e39d01b1eb) | 
`public GoUint64_ `[`Hours`](#structwallet_____balance_1a527c44c111577ee7ae35d7a53ab11332) | 

## Members

#### `public GoUint64_ `[`Coins`](#structwallet_____balance_1aa8ecc8470e80feb9af67d2e39d01b1eb) 

#### `public GoUint64_ `[`Hours`](#structwallet_____balance_1a527c44c111577ee7ae35d7a53ab11332) 

# struct `wallet__BalancePair` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`wallet__Balance`](#structwallet_____balance)` `[`Confirmed`](#structwallet_____balance_pair_1a41316e517db7b9094b239c0506a365d4) | 
`public `[`wallet__Balance`](#structwallet_____balance)` `[`Predicted`](#structwallet_____balance_pair_1adf1a2783f7f9cb7abddceee9da343676) | 

## Members

#### `public `[`wallet__Balance`](#structwallet_____balance)` `[`Confirmed`](#structwallet_____balance_pair_1a41316e517db7b9094b239c0506a365d4) 

#### `public `[`wallet__Balance`](#structwallet_____balance)` `[`Predicted`](#structwallet_____balance_pair_1adf1a2783f7f9cb7abddceee9da343676) 

# struct `wallet__Entry` 

[Wallet](#struct_wallet) entry.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structwallet_____entry_1a36182709852829827005f90eef8bf78c) | [Wallet](#struct_wallet) address.
`public cipher__PubKey `[`Public`](#structwallet_____entry_1a0bb45c3d09a24a1c34d376092a35dfdc) | Public key used to generate address.
`public cipher__SecKey `[`Secret`](#structwallet_____entry_1ab7c6991603c7f6e2f9a7c5b7dd580dac) | Secret key used to generate address.

## Members

#### `public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structwallet_____entry_1a36182709852829827005f90eef8bf78c) 

[Wallet](#struct_wallet) address.

#### `public cipher__PubKey `[`Public`](#structwallet_____entry_1a0bb45c3d09a24a1c34d376092a35dfdc) 

Public key used to generate address.

#### `public cipher__SecKey `[`Secret`](#structwallet_____entry_1ab7c6991603c7f6e2f9a7c5b7dd580dac) 

Secret key used to generate address.

# struct `wallet__Note` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`GoString_`](#struct_go_string__)` `[`TxID`](#structwallet_____note_1a54c4432f84daa21ae7afcac518b95079) | 
`public `[`GoString_`](#struct_go_string__)` `[`Value`](#structwallet_____note_1a51c1749adb41172cb32ea990f8c6b370) | 

## Members

#### `public `[`GoString_`](#struct_go_string__)` `[`TxID`](#structwallet_____note_1a54c4432f84daa21ae7afcac518b95079) 

#### `public `[`GoString_`](#struct_go_string__)` `[`Value`](#structwallet_____note_1a51c1749adb41172cb32ea990f8c6b370) 

# struct `wallet__ReadableNote` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`GoString_`](#struct_go_string__)` `[`TransactionID`](#structwallet_____readable_note_1af10202cabcff3e418cb51d2c48d97791) | 
`public `[`GoString_`](#struct_go_string__)` `[`ActualNote`](#structwallet_____readable_note_1ac0c686c42e8b829b2e553ff4d45460f3) | 

## Members

#### `public `[`GoString_`](#struct_go_string__)` `[`TransactionID`](#structwallet_____readable_note_1af10202cabcff3e418cb51d2c48d97791) 

#### `public `[`GoString_`](#struct_go_string__)` `[`ActualNote`](#structwallet_____readable_note_1ac0c686c42e8b829b2e553ff4d45460f3) 

# struct `wallet__UxBalance` 

Intermediate representation of a UxOut for sorting and spend choosing.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public cipher__SHA256 `[`Hash`](#structwallet_____ux_balance_1ac47f1b6e05da3c25722b2cc93728ee4d) | Hash of underlying UxOut.
`public GoInt64_ `[`BkSeq`](#structwallet_____ux_balance_1a1c1b05acfa8b1a65809ba4525f14a55b) | Block height corresponding to the moment balance calculation is performed at.
`public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structwallet_____ux_balance_1a36182709852829827005f90eef8bf78c) | Account holder address.
`public GoInt64_ `[`Coins`](#structwallet_____ux_balance_1a7733f16af3115d3cfc712f2f687b73e4) | Coins amount (e.g. in SKY).
`public GoInt64_ `[`Hours`](#structwallet_____ux_balance_1a7aef551ad5991173b5a6160fd8fe1594) | Balance of Coin Hours generated by underlying UxOut, depending on UxOut's head time.

## Members

#### `public cipher__SHA256 `[`Hash`](#structwallet_____ux_balance_1ac47f1b6e05da3c25722b2cc93728ee4d) 

Hash of underlying UxOut.

#### `public GoInt64_ `[`BkSeq`](#structwallet_____ux_balance_1a1c1b05acfa8b1a65809ba4525f14a55b) 

Block height corresponding to the moment balance calculation is performed at.

#### `public `[`cipher__Address`](#structcipher_____address)` `[`Address`](#structwallet_____ux_balance_1a36182709852829827005f90eef8bf78c) 

Account holder address.

#### `public GoInt64_ `[`Coins`](#structwallet_____ux_balance_1a7733f16af3115d3cfc712f2f687b73e4) 

Coins amount (e.g. in SKY).

#### `public GoInt64_ `[`Hours`](#structwallet_____ux_balance_1a7aef551ad5991173b5a6160fd8fe1594) 

Balance of Coin Hours generated by underlying UxOut, depending on UxOut's head time.

Generated by [Moxygen](https://sourcey.com/moxygen)