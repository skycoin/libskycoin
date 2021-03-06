#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/apply_settings_request.h"
#include "../model/check_message_signature_request.h"
#include "../model/configure_pin_code_request.h"
#include "../model/csrf_response.h"
#include "../model/features_response.h"
#include "../model/generate_addresses_request.h"
#include "../model/generate_addresses_response.h"
#include "../model/generate_mnemonic_request.h"
#include "../model/http_error_response.h"
#include "../model/http_success_response.h"
#include "../model/inline_response_200.h"
#include "../model/passphrase_request.h"
#include "../model/pin_matrix_request.h"
#include "../model/recovery_request.h"
#include "../model/set_mnemonic_request.h"
#include "../model/sign_message_request.h"
#include "../model/sign_message_response.h"
#include "../model/transaction_sign_request.h"
#include "../model/version_response.h"
#include "../model/word_request.h"


// Apply hardware wallet settings.
//
http_success_response_t*
DefaultAPI_applySettingsPost(apiClient_t *apiClient ,apply_settings_request_t * apply_settings_request);


// check whether a skywallet is connected to the machine.
//
inline_response_200_t*
DefaultAPI_availableGet(apiClient_t *apiClient);


// Start seed backup procedure.
//
http_success_response_t*
DefaultAPI_backupPost(apiClient_t *apiClient);


// Cancels the current operation.
//
http_success_response_t*
DefaultAPI_cancelPut(apiClient_t *apiClient);


// Check a message signature matches the given address.
//
http_success_response_t*
DefaultAPI_checkMessageSignaturePost(apiClient_t *apiClient ,check_message_signature_request_t * check_message_signature_request);


// Configure a pin code on the device.
//
http_success_response_t*
DefaultAPI_configurePinCodePost(apiClient_t *apiClient ,configure_pin_code_request_t * configure_pin_code_request);


// Returns csrf token
//
csrf_response_t*
DefaultAPI_csrfGet(apiClient_t *apiClient);


// Returns device information.
//
features_response_t*
DefaultAPI_featuresGet(apiClient_t *apiClient);


// Update firmware
//
http_success_response_t*
DefaultAPI_firmwareUpdatePut(apiClient_t *apiClient);


// Generate addresses for the hardware wallet seed.
//
generate_addresses_response_t*
DefaultAPI_generateAddressesPost(apiClient_t *apiClient ,generate_addresses_request_t * generate_addresses_request);


// Generate mnemonic can be used to initialize the device with a random seed.
//
http_success_response_t*
DefaultAPI_generateMnemonicPost(apiClient_t *apiClient ,generate_mnemonic_request_t * generate_mnemonic_request);


// button ack request.
//
http_success_response_t*
DefaultAPI_intermediateButtonPost(apiClient_t *apiClient);


// passphrase ack request.
//
http_success_response_t*
DefaultAPI_intermediatePassphrasePost(apiClient_t *apiClient ,passphrase_request_t * passphrase_request);


// pin matrix ack request.
//
http_success_response_t*
DefaultAPI_intermediatePinMatrixPost(apiClient_t *apiClient ,pin_matrix_request_t * pin_matrix_request);


// word ack request.
//
http_success_response_t*
DefaultAPI_intermediateWordPost(apiClient_t *apiClient ,word_request_t * word_request);


// Recover existing wallet using seed.
//
http_success_response_t*
DefaultAPI_recoveryPost(apiClient_t *apiClient ,recovery_request_t * recovery_request);


// Set mnemonic can be used to initialize the device with your own seed.
//
http_success_response_t*
DefaultAPI_setMnemonicPost(apiClient_t *apiClient ,set_mnemonic_request_t * set_mnemonic_request);


// Sign a message using the secret key at given index.
//
sign_message_response_t*
DefaultAPI_signMessagePost(apiClient_t *apiClient ,sign_message_request_t * sign_message_request);


// Sign a transaction with the hardware wallet.
//
http_success_response_t*
DefaultAPI_transactionSignPost(apiClient_t *apiClient ,transaction_sign_request_t * transaction_sign_request);


// Returns daemon version information.
//
version_response_t*
DefaultAPI_versionGet(apiClient_t *apiClient);


// clean all the configurations.
//
http_success_response_t*
DefaultAPI_wipeDelete(apiClient_t *apiClient);


