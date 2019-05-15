#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/inline_object.h"
#include "../model/inline_response_200.h"
#include "../model/inline_response_200_1.h"
#include "../model/inline_response_200_2.h"
#include "../model/inline_response_200_3.h"
#include "../model/inline_response_200_4.h"
#include "../model/inline_response_200_5.h"
#include "../model/inline_response_200_6.h"
#include "../model/inline_response_200_7.h"
#include "../model/inline_response_default.h"
#include "../model/object.h"


// Returns the total number of unique address that have coins.
//
object_t*
DefaultAPI_addressCount(apiClient_t *apiClient);


// Returns the historical, spent outputs associated with an address
//
list_t*
DefaultAPI_addressUxouts(apiClient_t *apiClient ,char * address);


// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_balanceGet(apiClient_t *apiClient ,char * addrs);


// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_balancePost(apiClient_t *apiClient ,char * addrs);


// Returns a block by hash or seq. Note: only one of hash or seq is allowed
//
object_t*
DefaultAPI_block(apiClient_t *apiClient ,char * hash ,int seq);


// Returns the blockchain metadata.
//
object_t*
DefaultAPI_blockchainMetadata(apiClient_t *apiClient);


// Returns the blockchain sync progress.
//
object_t*
DefaultAPI_blockchainProgress(apiClient_t *apiClient);


// blocksHandler returns blocks between a start and end point,
//
// or an explicit list of sequences. If using start and end, the block sequences include both the start and end point. Explicit sequences cannot be combined with start and end. Without verbose.
//
object_t*
DefaultAPI_blocksGet(apiClient_t *apiClient ,int start ,int end ,list_t * seqs);


// blocksHandler returns blocks between a start and end point,
//
// or an explicit list of sequences. If using start and end, the block sequences include both the start and end point. Explicit sequences cannot be combined with start and end. Without verbose
//
object_t*
DefaultAPI_blocksPost(apiClient_t *apiClient ,int start ,int end ,list_t * seqs);


// coinSupplyHandler returns coin distribution supply stats
//
object_t*
DefaultAPI_coinSupply(apiClient_t *apiClient);


// Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
//
inline_response_200_1_t*
DefaultAPI_csrf(apiClient_t *apiClient);


// defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
//
list_t*
DefaultAPI_defaultConnections(apiClient_t *apiClient);


// Returns all transactions (confirmed and unconfirmed) for an address
//
list_t*
DefaultAPI_explorerAddress(apiClient_t *apiClient ,char * address);


// Returns node health data.
//
object_t*
DefaultAPI_health(apiClient_t *apiClient);


// Returns the most recent N blocks on the blockchain
//
object_t*
DefaultAPI_lastBlocks(apiClient_t *apiClient ,int num);


// This endpoint returns a specific connection.
//
inline_response_200_3_t*
DefaultAPI_networkConnection(apiClient_t *apiClient ,char * addr);


// This endpoint returns all outgoings connections.
//
list_t*
DefaultAPI_networkConnections(apiClient_t *apiClient ,char* states ,char* direction);


// This endpoint disconnects a connection by ID or address
//
void
DefaultAPI_networkConnectionsDisconnect(apiClient_t *apiClient ,char * id);


// This endpoint returns all connections found through peer exchange
//
list_t*
DefaultAPI_networkConnectionsExchange(apiClient_t *apiClient);


// trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
//
list_t*
DefaultAPI_networkConnectionsTrust(apiClient_t *apiClient);


// If neither addrs nor hashes are specificed, return all unspent outputs. If only one filter is specified, then return outputs match the filter. Both filters cannot be specified.
//
object_t*
DefaultAPI_outputsGet(apiClient_t *apiClient ,list_t * address ,list_t * hash);


// If neither addrs nor hashes are specificed, return all unspent outputs. If only one filter is specified, then return outputs match the filter. Both filters cannot be specified.
//
object_t*
DefaultAPI_outputsPost(apiClient_t *apiClient ,char * address ,char * hash);


// Returns pending (unconfirmed) transactions without verbose
//
list_t*
DefaultAPI_pendingTxs(apiClient_t *apiClient);


// Broadcasts all unconfirmed transactions from the unconfirmed transaction pool
//
void
DefaultAPI_resendUnconfirmedTxns(apiClient_t *apiClient);


// Returns the top skycoin holders.
//
object_t*
DefaultAPI_richlist(apiClient_t *apiClient ,int include_distribution ,char * n);


// Returns a transaction identi`fied by its txid hash with just id
//
object_t*
DefaultAPI_transaction(apiClient_t *apiClient ,char * txid ,int encoded);


// Broadcast a hex-encoded, serialized transaction to the network.
//
object_t*
DefaultAPI_transactionInject(apiClient_t *apiClient ,char * rawtx);


// Returns the hex-encoded byte serialization of a transaction. The transaction may be confirmed or unconfirmed.
//
object_t*
DefaultAPI_transactionRaw(apiClient_t *apiClient ,char * txid);


// Decode and verify an encoded transaction
//
object_t*
DefaultAPI_transactionVerify(apiClient_t *apiClient);


// Returns transactions that match the filters.
//
object_t*
DefaultAPI_transactionsGet(apiClient_t *apiClient ,char * addrs ,char * confirmed);


// Returns transactions that match the filters.
//
object_t*
DefaultAPI_transactionsPost(apiClient_t *apiClient ,char * addrs ,char * confirmed);


// Returns an unspent output by ID.
//
object_t*
DefaultAPI_uxout(apiClient_t *apiClient ,char * uxid);


// Verifies a Skycoin address.
//
inline_response_200_7_t*
DefaultAPI_verifyAddress(apiClient_t *apiClient ,char * address);


// versionHandler returns the application version info
//
object_t*
DefaultAPI_version(apiClient_t *apiClient);


// Returns a wallet by id.
//
object_t*
DefaultAPI_wallet(apiClient_t *apiClient ,char * id);


// Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_walletBalance(apiClient_t *apiClient ,char * id);


// Loads wallet from seed, will scan ahead N address and load addresses till the last one that have coins.
//
object_t*
DefaultAPI_walletCreate(apiClient_t *apiClient ,char * seed ,char * label ,int scan ,int encrypt ,char * password);


// Decrypts wallet.
//
object_t*
DefaultAPI_walletDecrypt(apiClient_t *apiClient ,char * id ,char * password);


// Encrypt wallet.
//
object_t*
DefaultAPI_walletEncrypt(apiClient_t *apiClient ,char * id ,char * password);


// Returns the wallet directory path
//
inline_response_200_6_t*
DefaultAPI_walletFolder(apiClient_t *apiClient ,char * addr);


// Generates new addresses
//
object_t*
DefaultAPI_walletNewAddress(apiClient_t *apiClient ,char * id ,char * num ,char * password);


// Returns the wallet directory path
//
object_t*
DefaultAPI_walletNewSeed(apiClient_t *apiClient ,char* entropy);


// Recovers an encrypted wallet by providing the seed. The first address will be generated from seed and compared to the first address of the specified wallet. If they match, the wallet will be regenerated with an optional password. If the wallet is not encrypted, an error is returned.
//
object_t*
DefaultAPI_walletRecover(apiClient_t *apiClient ,char * id ,char * seed ,char * password);


// This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
//
object_t*
DefaultAPI_walletSeed(apiClient_t *apiClient ,char * id ,char * password);


// Verifies a wallet seed.
//
object_t*
DefaultAPI_walletSeedVerify(apiClient_t *apiClient ,char * seed);


// Creates and broadcasts a transaction sending money from one of our wallets to destination address.
//
object_t*
DefaultAPI_walletSpent(apiClient_t *apiClient ,char * id ,char * dst ,char * coins ,char * password);


// Creates a signed transaction
//
object_t*
DefaultAPI_walletTransaction(apiClient_t *apiClient ,inline_object_t * body);


// Returns returns all unconfirmed transactions for all addresses in a given wallet verbose
//
object_t*
DefaultAPI_walletTransactions(apiClient_t *apiClient ,char * id);


// Unloads wallet from the wallet service.
//
void
DefaultAPI_walletUnload(apiClient_t *apiClient ,char * id);


// Update the wallet.
//
void
DefaultAPI_walletUpdate(apiClient_t *apiClient ,char * id ,char * label);


// Returns all loaded wallets
//
list_t*
DefaultAPI_wallets(apiClient_t *apiClient);


