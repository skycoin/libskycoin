# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## Unreleased

### Added
- Added swagger specification for `Skycoin REST API` to v0.27.0

### Changed
- Update `lib/curl` to v0.27.0

## [0.26.0] - 2019-07-12

### Added
- Added datatype `api__TransactionInput`
- Added datatype `transaction__UxBalance`
- Added function `SKY_transaction_NewUxBalances`, 
- Added function `SKY_transaction_DistributeCoinHoursProportional`, `SKY_transaction_DistributeSpendHours`
- Added funcion `SKY_coin_VerifyInputSignatures`
- Added funcion `SKY_coin_BlockHeader_SetTime`
- Added funcion `SKY_coin_BlockHeader_SetBkSeq`
- Added funcion `SKY_coin_BlockHeader_SetFee`
- Added funcion `SKY_coin_BlockHeader_SetVersion`
- Added funcion `SKY_coin_BlockHeader_Version`
- Added funcion `SKY_coin_BlockHeader_PrevHash`
- Support for this new functions in `skyapi`:
  - Add POST /api/v2/wallet/transaction/sign to sign an unsigned transaction with a wallet
  - Add POST /api/v2/transaction to create an unsigned transaction from addresses or unspent outputs without a wallet
  - Add /api/v2/data APIs for transaction notes and generic key-value storage.
  - Update /metrics endpoint to add metrics from /health: unspent_outputs, unconfirmed_txns, time_since_last_block_seconds, open_connections, outgoing_connections, incoming_connections, start_at, uptime_seconds, last_block_seq.

### Changed
- Support for this changed functions in `skyapi`:
  - Add /api/v1/resendUnconfirmedTxns to the WALLET API set
  - In POST /api/v1/wallet/transaction, moved wallet parameters to the top level of the object
  - POST /api/v2/wallet/seed/verify returns an error if the seed's checksum is invalid
  - Increase the detail of error messages for invalid seeds sent to POST /api/v2/wallet/seed/verify

### Removed
- Removed symbolic links from vendor
- Removed function `SKY_webrpc_NewClient`, `SKY_webrpc_Client_CSRF`, `SKY_webrpc_Client_InjectTransaction`, `SKY_webrpc_Client_GetStatus`,`SKY_webrpc_Client_GetTransactionByID`, `SKY_webrpc_Client_GetAddressUxOuts`, `SKY_webrpc_Client_GetBlocksInRange`, `SKY_webrpc_Client_GetBlocksBySeq` and `SKY_webrpc_Client_GetLastBlocks`.
- Removed datatype `wallet__UxBalance`
- Removed fuction `SKY_cipher_VerifySignedHash`
- Removed fuction `SKY_bip39_MnemonicToByteArray`
- Removed fuction `SKY_api_Client_Spend`, `SKY_api_Client_AddressTransactions`
- Removed fuction `SKY_coin_Block_PreHashHeader`, `SKY_coin_Block_String` and `SKY_coin_BlockHeader_String`.
- Removed functions exported for `coin.math`
- Removed function `SKY_coin_Transaction_TxID`
- Removed function `SKY_wallet_DistributeSpendHours`
- Removed function `SKY_wallet_DistributeCoinHoursProportional`
- Removed function `SKY_wallet_NewUxBalances`
- Removed support for next functions in `skyapi`:
  - /api/v1/explorer/address endpoint (use GET /api/v1/transactions?verbose=1 instead). See https://github.com/skycoin/skycoin/blob/develop/src/api/README.md#migrating-from--api-v1-explorer-address
  - The unversioned REST API (the -enable-unversioned-api is removed, prefix your API requests with /api/v1 if they don't have an /api/vx prefix already). See https://github.com/skycoin/skycoin/blob/develop/src/api/README.md#migrating-from-the-unversioned-api
  - /api/v1/wallet/spend endpoint (use POST /api/v1/wallet/transaction followed by POST /api/v1/injectTransaction instead). See https://github.com/skycoin/skycoin/blob/develop/src/api/README.md#migrating-from--api-v1-spend


## [0.25.1] - 2019-06-30

### Added

- Be able to set a build type for lib curl.
- Export functions in Skycoin 0.25.1 core API's
- `skyapi` C client for Skycoin node REST at `lib/curl`.
- Support for building `libskycoin` on ARM and 32 / 64 bits.

### Fixed

- `/api/v1/health` will return correct build info when running Docker containers based on `skycoin/skycoin` mainnet image.

### Changed

- Adapt `libskycoin` after switching `skycoin-cli` from `urfave/cli` to `spf13/cobra`.

### Removed

- Delete function `SKY_base58_String2Hex`

## [0.25.0] - 2018-12-19

### Added

- Export functions in Skycoin 0.25.0 core API's
- Coinhour burn factor when creating transactions can be configured at runtime with `USER_BURN_FACTOR` envvar
- Max transaction size when creating transactions can be configured at runtime with `USER_MAX_TXN_SIZE` envvar
- Max decimals allowed when creating transactions can be configured at runtime with `USER_MAX_DECIMALS` envvar
- Complete support for `cipher` package in `libskycoin` C API.
- Add `coin`, `wallet`, `util/droplet` and `util/fee` methods as part of `libskycoin` C API
- Add `util/droplet` and `util/fee` API's as part of `libskycoin`
- Implement SWIG interfaces in order to generate client libraries for multiple programming languages

