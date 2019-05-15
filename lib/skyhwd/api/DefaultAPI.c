#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "DefaultAPI.h"


#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)

// Apply hardware wallet settings.
//
http_success_response_t*
DefaultAPI_applySettingsPost(apiClient_t *apiClient ,apply_settings_request_t * ApplySettingsRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/apply_settings")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/apply_settings");




    // Body Param
    cJSON *localVarSingleItemJSON_ApplySettingsRequest;
    if (ApplySettingsRequest != NULL)
    {
        //string
        localVarSingleItemJSON_ApplySettingsRequest = apply_settings_request_convertToJSON(ApplySettingsRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_ApplySettingsRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_ApplySettingsRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// check whether a skywallet is connected to the machine.
//
inline_response_200_t*
DefaultAPI_availableGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/available")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/available");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_t *elementToReturn = inline_response_200_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Start seed backup procedure.
//
http_success_response_t*
DefaultAPI_backupPost(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/backup")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/backup");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Cancels the current operation.
//
http_success_response_t*
DefaultAPI_cancelPut(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/cancel")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/cancel");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Check a message signature matches the given address.
//
http_success_response_t*
DefaultAPI_checkMessageSignaturePost(apiClient_t *apiClient ,check_message_signature_request_t * CheckMessageSignatureRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/check_message_signature")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/check_message_signature");




    // Body Param
    cJSON *localVarSingleItemJSON_CheckMessageSignatureRequest;
    if (CheckMessageSignatureRequest != NULL)
    {
        //string
        localVarSingleItemJSON_CheckMessageSignatureRequest = check_message_signature_request_convertToJSON(CheckMessageSignatureRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_CheckMessageSignatureRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_CheckMessageSignatureRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Configure a pin code on the device.
//
http_success_response_t*
DefaultAPI_configurePinCodePost(apiClient_t *apiClient ,int remove_pin)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = list_create();
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/configure_pin_code")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/configure_pin_code");




    // form parameters
    char *keyForm_remove_pin;
    int valueForm_remove_pin;
    keyValuePair_t *keyPairForm_remove_pin = 0;
    if (remove_pin != NULL)
    {
        keyForm_remove_pin = strdup("remove_pin");
        valueForm_remove_pin = (remove_pin);
        keyPairForm_remove_pin = keyValuePair_create(keyForm_remove_pin,&valueForm_remove_pin);
        list_addElement(localVarFormParameters,keyPairForm_remove_pin);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/x-www-form-urlencoded"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    list_free(localVarFormParameters);
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    free(keyForm_remove_pin);
    free(keyPairForm_remove_pin);
    return elementToReturn;
end:
    return NULL;

}

// Returns csrf token
//
csrf_response_t*
DefaultAPI_csrfGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/csrf")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/csrf");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","successful operation");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    csrf_response_t *elementToReturn = csrf_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Returns device information.
//
features_response_t*
DefaultAPI_featuresGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/features")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/features");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","successful operation");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    features_response_t *elementToReturn = features_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Update firmware
//
http_success_response_t*
DefaultAPI_firmwareUpdatePut(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/firmware_update")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/firmware_update");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "PUT");

    if (apiClient->response_code == 200) {
        printf("%s\n","successful operation");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Generate addresses for the hardware wallet seed.
//
generate_addresses_response_t*
DefaultAPI_generateAddressesPost(apiClient_t *apiClient ,generate_addresses_request_t * GenerateAddressesRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/generate_addresses")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/generate_addresses");




    // Body Param
    cJSON *localVarSingleItemJSON_GenerateAddressesRequest;
    if (GenerateAddressesRequest != NULL)
    {
        //string
        localVarSingleItemJSON_GenerateAddressesRequest = generate_addresses_request_convertToJSON(GenerateAddressesRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_GenerateAddressesRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    generate_addresses_response_t *elementToReturn = generate_addresses_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_GenerateAddressesRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Generate mnemonic can be used to initialize the device with a random seed.
//
http_success_response_t*
DefaultAPI_generateMnemonicPost(apiClient_t *apiClient ,generate_mnemonic_request_t * GenerateMnemonicRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/generate_mnemonic")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/generate_mnemonic");




    // Body Param
    cJSON *localVarSingleItemJSON_GenerateMnemonicRequest;
    if (GenerateMnemonicRequest != NULL)
    {
        //string
        localVarSingleItemJSON_GenerateMnemonicRequest = generate_mnemonic_request_convertToJSON(GenerateMnemonicRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_GenerateMnemonicRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","successful operation");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_GenerateMnemonicRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// passphrase ack request.
//
http_success_response_t*
DefaultAPI_intermediatePassphrasePost(apiClient_t *apiClient ,passphrase_request_t * PassphraseRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/intermediate/passphrase")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/intermediate/passphrase");




    // Body Param
    cJSON *localVarSingleItemJSON_PassphraseRequest;
    if (PassphraseRequest != NULL)
    {
        //string
        localVarSingleItemJSON_PassphraseRequest = passphrase_request_convertToJSON(PassphraseRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_PassphraseRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_PassphraseRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// pin matrix ack request.
//
http_success_response_t*
DefaultAPI_intermediatePinMatrixPost(apiClient_t *apiClient ,pin_matrix_request_t * PinMatrixRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/intermediate/pin_matrix")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/intermediate/pin_matrix");




    // Body Param
    cJSON *localVarSingleItemJSON_PinMatrixRequest;
    if (PinMatrixRequest != NULL)
    {
        //string
        localVarSingleItemJSON_PinMatrixRequest = pin_matrix_request_convertToJSON(PinMatrixRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_PinMatrixRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_PinMatrixRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// word ack request.
//
http_success_response_t*
DefaultAPI_intermediateWordPost(apiClient_t *apiClient ,word_request_t * WordRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/intermediate/word")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/intermediate/word");




    // Body Param
    cJSON *localVarSingleItemJSON_WordRequest;
    if (WordRequest != NULL)
    {
        //string
        localVarSingleItemJSON_WordRequest = word_request_convertToJSON(WordRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_WordRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_WordRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Recover existing wallet using seed.
//
http_success_response_t*
DefaultAPI_recoveryPost(apiClient_t *apiClient ,recovery_request_t * RecoveryRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/recovery")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/recovery");




    // Body Param
    cJSON *localVarSingleItemJSON_RecoveryRequest;
    if (RecoveryRequest != NULL)
    {
        //string
        localVarSingleItemJSON_RecoveryRequest = recovery_request_convertToJSON(RecoveryRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_RecoveryRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","intermediate response");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_RecoveryRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Set mnemonic can be used to initialize the device with your own seed.
//
http_success_response_t*
DefaultAPI_setMnemonicPost(apiClient_t *apiClient ,set_mnemonic_request_t * SetMnemonicRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/set_mnemonic")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/set_mnemonic");




    // Body Param
    cJSON *localVarSingleItemJSON_SetMnemonicRequest;
    if (SetMnemonicRequest != NULL)
    {
        //string
        localVarSingleItemJSON_SetMnemonicRequest = set_mnemonic_request_convertToJSON(SetMnemonicRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_SetMnemonicRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_SetMnemonicRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Sign a message using the secret key at given index.
//
sign_message_response_t*
DefaultAPI_signMessagePost(apiClient_t *apiClient ,sign_message_request_t * SignMessageRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/sign_message")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/sign_message");




    // Body Param
    cJSON *localVarSingleItemJSON_SignMessageRequest;
    if (SignMessageRequest != NULL)
    {
        //string
        localVarSingleItemJSON_SignMessageRequest = sign_message_request_convertToJSON(SignMessageRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_SignMessageRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","successful operation");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    sign_message_response_t *elementToReturn = sign_message_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_SignMessageRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Sign a transaction with the hardware wallet.
//
transaction_sign_response_t*
DefaultAPI_transactionSignPost(apiClient_t *apiClient ,transaction_sign_request_t * TransactionSignRequest)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/transaction_sign")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/transaction_sign");




    // Body Param
    cJSON *localVarSingleItemJSON_TransactionSignRequest;
    if (TransactionSignRequest != NULL)
    {
        //string
        localVarSingleItemJSON_TransactionSignRequest = transaction_sign_request_convertToJSON(TransactionSignRequest);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_TransactionSignRequest);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    transaction_sign_response_t *elementToReturn = transaction_sign_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_TransactionSignRequest);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// clean all the configurations.
//
http_success_response_t*
DefaultAPI_wipeDelete(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/wipe")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/wipe");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "DELETE");

    if (apiClient->response_code == 200) {
        printf("%s\n","success");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","error");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    http_success_response_t *elementToReturn = http_success_response_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    
    
    
    list_free(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

