#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/UNKNOWN_BASE_TYPE.h"
#include "../model/inline_response_200.h"
#include "../model/inline_response_200_1.h"
#include "../model/inline_response_200_2.h"
#include "../model/inline_response_200_3.h"
#include "../model/inline_response_200_4.h"
#include "../model/inline_response_200_5.h"
#include "../model/inline_response_200_6.h"
#include "../model/inline_response_200_7.h"
#include "../model/inline_response_default.h"
#include "../model/network_connection_schema.h"
#include "../model/object.h"
#include "../model/one_ofarrayarray.h"
#include "../model/one_ofblock_schemablock_verbose_schema.h"
#include "../model/one_oflast_blocks_responselast_blocks_verbose_response.h"
#include "../model/one_ofpending_txs_verbose_responsepending_txs_response.h"
#include "../model/one_ofsingle_keymulti_key.h"
#include "../model/one_oftransaction_responsetransaction_verbose_responsetransaction_encoded_response.h"
#include "../model/one_oftransaction_v2_params_unspenttransaction_v2_params_address.h"
#include "../model/one_oftransactions_responsetransaction_verbose_response.h"
#include "../model/one_ofwallet_transactions_responseswallet_transactions_verbose_responses.h"


// Returns the total number of unique address that have coins.
//
inline_response_200_t*
DefaultAPI_addressCount(apiClient_t *apiClient);


// Returns the historical, spent outputs associated with an address
//
list_t*
DefaultAPI_addressUxouts(apiClient_t *apiClient ,char * address);


char*
DefaultAPI_apiV1RawtxGet(apiClient_t *apiClient);


char*
DefaultAPI_apiV2MetricsGet(apiClient_t *apiClient);


// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_balanceGet(apiClient_t *apiClient ,char * addrs);


// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_balancePost(apiClient_t *apiClient ,char * addrs);


// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
one_ofarrayarray_t*
DefaultAPI_block(apiClient_t *apiClient ,char * hash ,int seq ,int verbose);


// Returns the blockchain metadata.
//
object_t*
DefaultAPI_blockchainMetadata(apiClient_t *apiClient);


// Returns the blockchain sync progress.
//
object_t*
DefaultAPI_blockchainProgress(apiClient_t *apiClient);


// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
one_ofblock_schemablock_verbose_schema_t*
DefaultAPI_blocks(apiClient_t *apiClient ,int start ,int end ,list_t * seq ,int verbose);


// coinSupplyHandler returns coin distribution supply stats
//
inline_response_200_1_t*
DefaultAPI_coinSupply(apiClient_t *apiClient);


// Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
//
inline_response_200_2_t*
DefaultAPI_csrf(apiClient_t *apiClient);


void
DefaultAPI_dataDELETE(apiClient_t *apiClient ,char * type ,char * key);


one_ofsingle_keymulti_key_t*
DefaultAPI_dataGET(apiClient_t *apiClient ,char * type ,char * key);


void
DefaultAPI_dataPOST(apiClient_t *apiClient ,char * type ,char * key ,char * val);


// defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
//
list_t*
DefaultAPI_defaultConnections(apiClient_t *apiClient);


// Returns node health data.
//
object_t*
DefaultAPI_health(apiClient_t *apiClient);


// Returns the most recent N blocks on the blockchain
//
one_oflast_blocks_responselast_blocks_verbose_response_t*
DefaultAPI_lastBlocks(apiClient_t *apiClient ,int num ,int verbose);


// This endpoint returns a specific connection.
//
network_connection_schema_t*
DefaultAPI_networkConnection(apiClient_t *apiClient ,char * addr);


// This endpoint returns all outgoings connections.
//
inline_response_200_3_t*
DefaultAPI_networkConnections(apiClient_t *apiClient ,states_e states ,direction_e direction);


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


one_ofpending_txs_verbose_responsepending_txs_response_t*
DefaultAPI_pendingTxs(apiClient_t *apiClient ,int verbose);


// Broadcasts all unconfirmed transactions from the unconfirmed transaction pool
//
object_t*
DefaultAPI_resendUnconfirmedTxns(apiClient_t *apiClient);


// Returns the top skycoin holders.
//
object_t*
DefaultAPI_richlist(apiClient_t *apiClient ,int include_distribution ,char * n);


// Returns a transaction identified by its txid hash with just id
//
one_oftransaction_responsetransaction_verbose_responsetransaction_encoded_response_t*
DefaultAPI_transaction(apiClient_t *apiClient ,char * txid ,int verbose ,int encoded);


// Broadcast a hex-encoded, serialized transaction to the network.
//
char*
DefaultAPI_transactionInject(apiClient_t *apiClient ,char * rawtx);


inline_response_200_6_t*
DefaultAPI_transactionPost(apiClient_t *apiClient ,UNKNOWN_BASE_TYPE_t * UNKNOWN_BASE_TYPE);


// Returns the hex-encoded byte serialization of a transaction. The transaction may be confirmed or unconfirmed.
//
object_t*
DefaultAPI_transactionRaw(apiClient_t *apiClient ,char * txid);


// Decode and verify an encoded transaction
//
object_t*
DefaultAPI_transactionVerify(apiClient_t *apiClient ,UNKNOWN_BASE_TYPE_t * UNKNOWN_BASE_TYPE);


// Returns transactions that match the filters.
//
one_oftransactions_responsetransaction_verbose_response_t*
DefaultAPI_transactionsGet(apiClient_t *apiClient ,char * addrs ,char * confirmed ,int verbose);


// Returns transactions that match the filters.
//
one_oftransactions_responsetransaction_verbose_response_t*
DefaultAPI_transactionsPost(apiClient_t *apiClient ,char * addrs ,char * confirmed ,int verbose);


// Returns an unspent output by ID.
//
object_t*
DefaultAPI_uxout(apiClient_t *apiClient ,char * uxid);


// Verifies a Skycoin address.
//
object_t*
DefaultAPI_verifyAddress(apiClient_t *apiClient ,object_t * address);


// versionHandler returns the application version info
//
inline_response_200_4_t*
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
inline_response_200_5_t*
DefaultAPI_walletFolder(apiClient_t *apiClient ,char * addr);


// Generates new addresses
//
object_t*
DefaultAPI_walletNewAddress(apiClient_t *apiClient ,char * id ,char * num ,char * password);


// Returns the wallet directory path
//
object_t*
DefaultAPI_walletNewSeed(apiClient_t *apiClient ,entropy_e entropy);


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


// Creates a signed transaction
//
object_t*
DefaultAPI_walletTransaction(apiClient_t *apiClient ,UNKNOWN_BASE_TYPE_t * UNKNOWN_BASE_TYPE);


// Creates a signed transaction
//
inline_response_200_7_t*
DefaultAPI_walletTransactionSign(apiClient_t *apiClient ,UNKNOWN_BASE_TYPE_t * UNKNOWN_BASE_TYPE);


one_ofwallet_transactions_responseswallet_transactions_verbose_responses_t*
DefaultAPI_walletTransactions(apiClient_t *apiClient ,char * id ,int verbose);


// Unloads wallet from the wallet service.
//
void
DefaultAPI_walletUnload(apiClient_t *apiClient ,char * id);


// Update the wallet.
//
char*
DefaultAPI_walletUpdate(apiClient_t *apiClient ,char * id ,char * label);


// Returns all loaded wallets
//
list_t*
DefaultAPI_wallets(apiClient_t *apiClient);


