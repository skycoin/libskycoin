# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- Added datatype `api__TransactionInput`
- Added datatype `transaction__UxBalance`
- Added function `SKY_transaction_NewUxBalances`, 
- Added function `SKY_transaction_DistributeCoinHoursProportional`, `SKY_transaction_DistributeSpendHours`


### Fixed

### Changed

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



## [0.25.1] - 2019-05-24

### Added

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

