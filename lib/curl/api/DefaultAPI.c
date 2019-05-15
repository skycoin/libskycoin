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

// Returns the total number of unique address that have coins.
//
object_t*
DefaultAPI_addressCount(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/addresscount")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/addresscount");



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
        printf("%s\n","This endpoint Returns the total number of unique address that have coins.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Returns the historical, spent outputs associated with an address
//
list_t*
DefaultAPI_addressUxouts(apiClient_t *apiClient ,char * address)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/address_uxouts")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/address_uxouts");




    // query parameters
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }
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
        printf("%s\n","Return address uxouts");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_create();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    return elementToReturn;
end:
    return NULL;

}

// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_balanceGet(apiClient_t *apiClient ,char * addrs)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/balance")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/balance");




    // query parameters
    char *keyQuery_addrs;
    char * valueQuery_addrs;
    keyValuePair_t *keyPairQuery_addrs = 0;
    if (addrs)
    {
        keyQuery_addrs = strdup("addrs");
        valueQuery_addrs = strdup((addrs));
        keyPairQuery_addrs = keyValuePair_create(keyQuery_addrs, valueQuery_addrs);
        list_addElement(localVarQueryParameters,keyPairQuery_addrs);
    }
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
        printf("%s\n","Returns the balance of one or more addresses");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_addrs);
    free(valueQuery_addrs);
    keyValuePair_free(keyPairQuery_addrs);
    return elementToReturn;
end:
    return NULL;

}

// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_balancePost(apiClient_t *apiClient ,char * addrs)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/balance")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/balance");




    // query parameters
    char *keyQuery_addrs;
    char * valueQuery_addrs;
    keyValuePair_t *keyPairQuery_addrs = 0;
    if (addrs)
    {
        keyQuery_addrs = strdup("addrs");
        valueQuery_addrs = strdup((addrs));
        keyPairQuery_addrs = keyValuePair_create(keyQuery_addrs, valueQuery_addrs);
        list_addElement(localVarQueryParameters,keyPairQuery_addrs);
    }
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
        printf("%s\n","Returns the balance of one or more addresses");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_addrs);
    free(valueQuery_addrs);
    keyValuePair_free(keyPairQuery_addrs);
    return elementToReturn;
end:
    return NULL;

}

// Returns a block by hash or seq. Note: only one of hash or seq is allowed
//
object_t*
DefaultAPI_block(apiClient_t *apiClient ,char * hash ,int seq)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/block")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/block");




    // query parameters
    char *keyQuery_hash;
    char * valueQuery_hash;
    keyValuePair_t *keyPairQuery_hash = 0;
    if (hash)
    {
        keyQuery_hash = strdup("hash");
        valueQuery_hash = strdup((hash));
        keyPairQuery_hash = keyValuePair_create(keyQuery_hash, valueQuery_hash);
        list_addElement(localVarQueryParameters,keyPairQuery_hash);
    }

    // query parameters
    char *keyQuery_seq;
    int valueQuery_seq;
    keyValuePair_t *keyPairQuery_seq = 0;
    if (seq)
    {
        keyQuery_seq = strdup("seq");
        valueQuery_seq = (seq);
        keyPairQuery_seq = keyValuePair_create(keyQuery_seq, &valueQuery_seq);
        list_addElement(localVarQueryParameters,keyPairQuery_seq);
    }
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
        printf("%s\n","BlockVerbose represents a readable block with verbose data.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_hash);
    free(valueQuery_hash);
    keyValuePair_free(keyPairQuery_hash);
    free(keyQuery_seq);
    keyValuePair_free(keyPairQuery_seq);
    return elementToReturn;
end:
    return NULL;

}

// Returns the blockchain metadata.
//
object_t*
DefaultAPI_blockchainMetadata(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/blockchain/metadata")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/blockchain/metadata");



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
        printf("%s\n","This endpoint returns the blockchain metadata.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Returns the blockchain sync progress.
//
object_t*
DefaultAPI_blockchainProgress(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/blockchain/progress")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/blockchain/progress");



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
        printf("%s\n","This endpoint returns the blockchain sync progress");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// blocksHandler returns blocks between a start and end point,
//
// or an explicit list of sequences. If using start and end, the block sequences include both the start and end point. Explicit sequences cannot be combined with start and end. Without verbose.
//
object_t*
DefaultAPI_blocksGet(apiClient_t *apiClient ,int start ,int end ,list_t * seqs)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/blocks")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/blocks");




    // query parameters
    char *keyQuery_start;
    int valueQuery_start;
    keyValuePair_t *keyPairQuery_start = 0;
    if (start)
    {
        keyQuery_start = strdup("start");
        valueQuery_start = (start);
        keyPairQuery_start = keyValuePair_create(keyQuery_start, &valueQuery_start);
        list_addElement(localVarQueryParameters,keyPairQuery_start);
    }

    // query parameters
    char *keyQuery_end;
    int valueQuery_end;
    keyValuePair_t *keyPairQuery_end = 0;
    if (end)
    {
        keyQuery_end = strdup("end");
        valueQuery_end = (end);
        keyPairQuery_end = keyValuePair_create(keyQuery_end, &valueQuery_end);
        list_addElement(localVarQueryParameters,keyPairQuery_end);
    }

    // query parameters
    if (seqs)
    {
        list_addElement(localVarQueryParameters,seqs);
    }
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
        printf("%s\n","Returns blocks between a start and end point.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_start);
    keyValuePair_free(keyPairQuery_start);
    free(keyQuery_end);
    keyValuePair_free(keyPairQuery_end);
    return elementToReturn;
end:
    return NULL;

}

// blocksHandler returns blocks between a start and end point,
//
// or an explicit list of sequences. If using start and end, the block sequences include both the start and end point. Explicit sequences cannot be combined with start and end. Without verbose
//
object_t*
DefaultAPI_blocksPost(apiClient_t *apiClient ,int start ,int end ,list_t * seqs)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/blocks")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/blocks");




    // query parameters
    char *keyQuery_start;
    int valueQuery_start;
    keyValuePair_t *keyPairQuery_start = 0;
    if (start)
    {
        keyQuery_start = strdup("start");
        valueQuery_start = (start);
        keyPairQuery_start = keyValuePair_create(keyQuery_start, &valueQuery_start);
        list_addElement(localVarQueryParameters,keyPairQuery_start);
    }

    // query parameters
    char *keyQuery_end;
    int valueQuery_end;
    keyValuePair_t *keyPairQuery_end = 0;
    if (end)
    {
        keyQuery_end = strdup("end");
        valueQuery_end = (end);
        keyPairQuery_end = keyValuePair_create(keyQuery_end, &valueQuery_end);
        list_addElement(localVarQueryParameters,keyPairQuery_end);
    }

    // query parameters
    if (seqs)
    {
        list_addElement(localVarQueryParameters,seqs);
    }
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
        printf("%s\n","Returns blocks between a start and end point.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_start);
    keyValuePair_free(keyPairQuery_start);
    free(keyQuery_end);
    keyValuePair_free(keyPairQuery_end);
    return elementToReturn;
end:
    return NULL;

}

// coinSupplyHandler returns coin distribution supply stats
//
object_t*
DefaultAPI_coinSupply(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/coinSupply")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/coinSupply");



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
        printf("%s\n","CoinSupply records the coin supply info.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Creates a new CSRF token. Previous CSRF tokens are invalidated by this call.
//
inline_response_200_1_t*
DefaultAPI_csrf(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/csrf")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/csrf");



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
        printf("%s\n","Return a csrf Token.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_1_t *elementToReturn = inline_response_200_1_parseFromJSON(DefaultAPIlocalVarJSON);
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

// defaultConnectionsHandler returns the list of default hardcoded bootstrap addresses.\\n They are not necessarily connected to.
//
list_t*
DefaultAPI_defaultConnections(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/network/defaultConnections")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/network/defaultConnections");



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
        printf("%s\n","Array of string as Response");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //primitive reutrn type not simple
    cJSON *localVarJSON = cJSON_Parse(apiClient->dataReceived);
    cJSON *VarJSON;
    list_t *elementToReturn = list_create();
    cJSON_ArrayForEach(VarJSON, localVarJSON){
        keyValuePair_t *keyPair = keyValuePair_create(strdup(VarJSON->string), cJSON_Print(VarJSON));
        list_addElement(elementToReturn, keyPair);
    }
    cJSON_Delete(localVarJSON);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }



    list_free(localVarHeaderType);

    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// Returns all transactions (confirmed and unconfirmed) for an address
//
list_t*
DefaultAPI_explorerAddress(apiClient_t *apiClient ,char * address)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/explorer/address")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/explorer/address");




    // query parameters
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }
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
        printf("%s\n","Response explorer address");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_create();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    return elementToReturn;
end:
    return NULL;

}

// Returns node health data.
//
object_t*
DefaultAPI_health(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/health")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/health");



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
        printf("%s\n","This endpoint returns node health data.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Returns the most recent N blocks on the blockchain
//
object_t*
DefaultAPI_lastBlocks(apiClient_t *apiClient ,int num)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/last_blocks")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/last_blocks");




    // query parameters
    char *keyQuery_num;
    int valueQuery_num;
    keyValuePair_t *keyPairQuery_num = 0;
    if (num)
    {
        keyQuery_num = strdup("num");
        valueQuery_num = (num);
        keyPairQuery_num = keyValuePair_create(keyQuery_num, &valueQuery_num);
        list_addElement(localVarQueryParameters,keyPairQuery_num);
    }
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
        printf("%s\n","Returns the most recent N blocks on the blockchain.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_num);
    keyValuePair_free(keyPairQuery_num);
    return elementToReturn;
end:
    return NULL;

}

// This endpoint returns a specific connection.
//
inline_response_200_3_t*
DefaultAPI_networkConnection(apiClient_t *apiClient ,char * addr)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/network/connection")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/network/connection");




    // query parameters
    char *keyQuery_addr;
    char * valueQuery_addr;
    keyValuePair_t *keyPairQuery_addr = 0;
    if (addr)
    {
        keyQuery_addr = strdup("addr");
        valueQuery_addr = strdup((addr));
        keyPairQuery_addr = keyValuePair_create(keyQuery_addr, valueQuery_addr);
        list_addElement(localVarQueryParameters,keyPairQuery_addr);
    }
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
        printf("%s\n","This endpoint return a connection");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_3_t *elementToReturn = inline_response_200_3_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_addr);
    free(valueQuery_addr);
    keyValuePair_free(keyPairQuery_addr);
    return elementToReturn;
end:
    return NULL;

}

// This endpoint returns all outgoings connections.
//
list_t*
DefaultAPI_networkConnections(apiClient_t *apiClient, char* states, char* direction) {
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/network/connections")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/network/connections");




    // query parameters
    char *keyQuery_states;
    char *valueQuery_states;
    keyValuePair_t *keyPairQuery_states = 0;
    if (states)
    {
    //string
    keyQuery_states = strdup("states");
    valueQuery_states = strdup(states);
    keyPairQuery_states = keyValuePair_create(keyQuery_states, valueQuery_states);
    list_addElement(localVarQueryParameters,keyPairQuery_states);
    }

    // query parameters
    char *keyQuery_direction;
    char *valueQuery_direction;
    keyValuePair_t *keyPairQuery_direction = 0;
    if (direction)
    {
    //string
    keyQuery_direction = strdup("direction");
    valueQuery_direction = strdup(direction);
    keyPairQuery_direction = keyValuePair_create(keyQuery_direction, valueQuery_direction);
    list_addElement(localVarQueryParameters,keyPairQuery_direction);
    }
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
        printf("%s\n","This endpoint return an array of connections");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_create();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_states);
    free(valueQuery_states);
    keyValuePair_free(keyPairQuery_states);
    free(keyQuery_direction);
    free(valueQuery_direction);
    keyValuePair_free(keyPairQuery_direction);
    return elementToReturn;
end:
    return NULL;

}

// This endpoint disconnects a connection by ID or address
//
void
DefaultAPI_networkConnectionsDisconnect(apiClient_t *apiClient ,char * id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/network/connection/disconnect")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/network/connection/disconnect");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }
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
        printf("%s\n","This endpoint");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    free(keyQuery_id);
    keyValuePair_free(keyPairQuery_id);

}

// This endpoint returns all connections found through peer exchange
//
list_t*
DefaultAPI_networkConnectionsExchange(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/network/connections/exchange")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/network/connections/exchange");



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
        printf("%s\n","This endpoint return a list of all connections found through peer exchange.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //primitive reutrn type not simple
    cJSON *localVarJSON = cJSON_Parse(apiClient->dataReceived);
    cJSON *VarJSON;
    list_t *elementToReturn = list_create();
    cJSON_ArrayForEach(VarJSON, localVarJSON){
        keyValuePair_t *keyPair = keyValuePair_create(strdup(VarJSON->string), cJSON_Print(VarJSON));
        list_addElement(elementToReturn, keyPair);
    }
    cJSON_Delete(localVarJSON);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }



    list_free(localVarHeaderType);

    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// trustConnectionsHandler returns all trusted connections.\\n They are not necessarily connected to. In the default configuration, these will be a subset of the default hardcoded bootstrap addresses.
//
list_t*
DefaultAPI_networkConnectionsTrust(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/network/connections/trust")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/network/connections/trust");



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
        printf("%s\n","Array of string as Response");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //primitive reutrn type not simple
    cJSON *localVarJSON = cJSON_Parse(apiClient->dataReceived);
    cJSON *VarJSON;
    list_t *elementToReturn = list_create();
    cJSON_ArrayForEach(VarJSON, localVarJSON){
        keyValuePair_t *keyPair = keyValuePair_create(strdup(VarJSON->string), cJSON_Print(VarJSON));
        list_addElement(elementToReturn, keyPair);
    }
    cJSON_Delete(localVarJSON);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }



    list_free(localVarHeaderType);

    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// If neither addrs nor hashes are specificed, return all unspent outputs. If only one filter is specified, then return outputs match the filter. Both filters cannot be specified.
//
object_t*
DefaultAPI_outputsGet(apiClient_t *apiClient ,list_t * address ,list_t * hash)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/outputs")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/outputs");




    // query parameters
    if (address)
    {
        list_addElement(localVarQueryParameters,address);
    }

    // query parameters
    if (hash)
    {
        list_addElement(localVarQueryParameters,hash);
    }
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
        printf("%s\n","Response unspent outputs in different status.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

// If neither addrs nor hashes are specificed, return all unspent outputs. If only one filter is specified, then return outputs match the filter. Both filters cannot be specified.
//
object_t*
DefaultAPI_outputsPost(apiClient_t *apiClient ,char * address ,char * hash)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/outputs")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/outputs");




    // query parameters
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }

    // query parameters
    char *keyQuery_hash;
    char * valueQuery_hash;
    keyValuePair_t *keyPairQuery_hash = 0;
    if (hash)
    {
        keyQuery_hash = strdup("hash");
        valueQuery_hash = strdup((hash));
        keyPairQuery_hash = keyValuePair_create(keyQuery_hash, valueQuery_hash);
        list_addElement(localVarQueryParameters,keyPairQuery_hash);
    }
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
        printf("%s\n","Response unspent outputs in different status.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    free(keyQuery_hash);
    free(valueQuery_hash);
    keyValuePair_free(keyPairQuery_hash);
    return elementToReturn;
end:
    return NULL;

}

// Returns pending (unconfirmed) transactions without verbose
//
list_t*
DefaultAPI_pendingTxs(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/pendingTxs")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/pendingTxs");



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
        printf("%s\n","Returns pending txs");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_create();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
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

// Broadcasts all unconfirmed transactions from the unconfirmed transaction pool
//
void
DefaultAPI_resendUnconfirmedTxns(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/resendUnconfirmedTxns")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/resendUnconfirmedTxns");



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
        printf("%s\n","OK, Broadcasts all unconfirmed transactions from the unconfirmed transaction pool");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }



    list_free(localVarHeaderType);

    free(localVarPath);

}

// Returns the top skycoin holders.
//
object_t*
DefaultAPI_richlist(apiClient_t *apiClient ,int include_distribution ,char * n)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/richlist")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/richlist");




    // query parameters
    char *keyQuery_include_distribution;
    int valueQuery_include_distribution;
    keyValuePair_t *keyPairQuery_include_distribution = 0;
    if (include_distribution)
    {
        keyQuery_include_distribution = strdup("include_distribution");
        valueQuery_include_distribution = (include_distribution);
        keyPairQuery_include_distribution = keyValuePair_create(keyQuery_include_distribution, &valueQuery_include_distribution);
        list_addElement(localVarQueryParameters,keyPairQuery_include_distribution);
    }

    // query parameters
    char *keyQuery_n;
    char * valueQuery_n;
    keyValuePair_t *keyPairQuery_n = 0;
    if (n)
    {
        keyQuery_n = strdup("n");
        valueQuery_n = strdup((n));
        keyPairQuery_n = keyValuePair_create(keyQuery_n, valueQuery_n);
        list_addElement(localVarQueryParameters,keyPairQuery_n);
    }
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
        printf("%s\n","Response for richlist");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_include_distribution);
    keyValuePair_free(keyPairQuery_include_distribution);
    free(keyQuery_n);
    free(valueQuery_n);
    keyValuePair_free(keyPairQuery_n);
    return elementToReturn;
end:
    return NULL;

}

// Returns a transaction identi`fied by its txid hash with just id
//
object_t*
DefaultAPI_transaction(apiClient_t *apiClient ,char * txid ,int encoded)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/transaction")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/transaction");




    // query parameters
    char *keyQuery_txid;
    char * valueQuery_txid;
    keyValuePair_t *keyPairQuery_txid = 0;
    if (txid)
    {
        keyQuery_txid = strdup("txid");
        valueQuery_txid = strdup((txid));
        keyPairQuery_txid = keyValuePair_create(keyQuery_txid, valueQuery_txid);
        list_addElement(localVarQueryParameters,keyPairQuery_txid);
    }

    // query parameters
    char *keyQuery_encoded;
    int valueQuery_encoded;
    keyValuePair_t *keyPairQuery_encoded = 0;
    if (encoded)
    {
        keyQuery_encoded = strdup("encoded");
        valueQuery_encoded = (encoded);
        keyPairQuery_encoded = keyValuePair_create(keyQuery_encoded, &valueQuery_encoded);
        list_addElement(localVarQueryParameters,keyPairQuery_encoded);
    }
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
        printf("%s\n","Returns a transaction identified by its txid hash.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_txid);
    free(valueQuery_txid);
    keyValuePair_free(keyPairQuery_txid);
    free(keyQuery_encoded);
    keyValuePair_free(keyPairQuery_encoded);
    return elementToReturn;
end:
    return NULL;

}

// Broadcast a hex-encoded, serialized transaction to the network.
//
object_t*
DefaultAPI_transactionInject(apiClient_t *apiClient ,char * rawtx)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/transaction/inject")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/transaction/inject");




    // header parameters
    char *keyHeader_rawtx;
    char * valueHeader_rawtx;
    keyValuePair_t *keyPairHeader_rawtx = 0;
    if (rawtx) {
        keyHeader_rawtx = strdup("rawtx");
        valueHeader_rawtx = strdup((rawtx));
        keyPairHeader_rawtx = keyValuePair_create(keyHeader_rawtx, valueHeader_rawtx);
        list_addElement(localVarHeaderParameters,keyPairHeader_rawtx);
    }

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
        printf("%s\n","Returns the transaction.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_rawtx);
    free(valueHeader_rawtx);
    free(keyPairHeader_rawtx);
    return elementToReturn;
end:
    return NULL;

}

// Returns the hex-encoded byte serialization of a transaction. The transaction may be confirmed or unconfirmed.
//
object_t*
DefaultAPI_transactionRaw(apiClient_t *apiClient ,char * txid)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/transaction/raw")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/transaction/raw");




    // query parameters
    char *keyQuery_txid;
    char * valueQuery_txid;
    keyValuePair_t *keyPairQuery_txid = 0;
    if (txid)
    {
        keyQuery_txid = strdup("txid");
        valueQuery_txid = strdup((txid));
        keyPairQuery_txid = keyValuePair_create(keyQuery_txid, valueQuery_txid);
        list_addElement(localVarQueryParameters,keyPairQuery_txid);
    }
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
        printf("%s\n","Returns the hex-encoded byte serialization of a transaction");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_txid);
    free(valueQuery_txid);
    keyValuePair_free(keyPairQuery_txid);
    return elementToReturn;
end:
    return NULL;

}

// Decode and verify an encoded transaction
//
object_t*
DefaultAPI_transactionVerify(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/transaction/verify")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/transaction/verify");



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
        printf("%s\n","This endpoint return a ferificated transaction");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Returns transactions that match the filters.
//
object_t*
DefaultAPI_transactionsGet(apiClient_t *apiClient ,char * addrs ,char * confirmed)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/transactions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/transactions");




    // query parameters
    char *keyQuery_addrs;
    char * valueQuery_addrs;
    keyValuePair_t *keyPairQuery_addrs = 0;
    if (addrs)
    {
        keyQuery_addrs = strdup("addrs");
        valueQuery_addrs = strdup((addrs));
        keyPairQuery_addrs = keyValuePair_create(keyQuery_addrs, valueQuery_addrs);
        list_addElement(localVarQueryParameters,keyPairQuery_addrs);
    }

    // query parameters
    char *keyQuery_confirmed;
    char * valueQuery_confirmed;
    keyValuePair_t *keyPairQuery_confirmed = 0;
    if (confirmed)
    {
        keyQuery_confirmed = strdup("confirmed");
        valueQuery_confirmed = strdup((confirmed));
        keyPairQuery_confirmed = keyValuePair_create(keyQuery_confirmed, valueQuery_confirmed);
        list_addElement(localVarQueryParameters,keyPairQuery_confirmed);
    }
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
        printf("%s\n","Returns transactions that match the filters.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_addrs);
    free(valueQuery_addrs);
    keyValuePair_free(keyPairQuery_addrs);
    free(keyQuery_confirmed);
    free(valueQuery_confirmed);
    keyValuePair_free(keyPairQuery_confirmed);
    return elementToReturn;
end:
    return NULL;

}

// Returns transactions that match the filters.
//
object_t*
DefaultAPI_transactionsPost(apiClient_t *apiClient ,char * addrs ,char * confirmed)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/transactions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/transactions");




    // query parameters
    char *keyQuery_addrs;
    char * valueQuery_addrs;
    keyValuePair_t *keyPairQuery_addrs = 0;
    if (addrs)
    {
        keyQuery_addrs = strdup("addrs");
        valueQuery_addrs = strdup((addrs));
        keyPairQuery_addrs = keyValuePair_create(keyQuery_addrs, valueQuery_addrs);
        list_addElement(localVarQueryParameters,keyPairQuery_addrs);
    }

    // query parameters
    char *keyQuery_confirmed;
    char * valueQuery_confirmed;
    keyValuePair_t *keyPairQuery_confirmed = 0;
    if (confirmed)
    {
        keyQuery_confirmed = strdup("confirmed");
        valueQuery_confirmed = strdup((confirmed));
        keyPairQuery_confirmed = keyValuePair_create(keyQuery_confirmed, valueQuery_confirmed);
        list_addElement(localVarQueryParameters,keyPairQuery_confirmed);
    }
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
        printf("%s\n","Returns transactions that match the filters.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_addrs);
    free(valueQuery_addrs);
    keyValuePair_free(keyPairQuery_addrs);
    free(keyQuery_confirmed);
    free(valueQuery_confirmed);
    keyValuePair_free(keyPairQuery_confirmed);
    return elementToReturn;
end:
    return NULL;

}

// Returns an unspent output by ID.
//
object_t*
DefaultAPI_uxout(apiClient_t *apiClient ,char * uxid)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/uxout")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/uxout");




    // query parameters
    char *keyQuery_uxid;
    char * valueQuery_uxid;
    keyValuePair_t *keyPairQuery_uxid = 0;
    if (uxid)
    {
        keyQuery_uxid = strdup("uxid");
        valueQuery_uxid = strdup((uxid));
        keyPairQuery_uxid = keyValuePair_create(keyQuery_uxid, valueQuery_uxid);
        list_addElement(localVarQueryParameters,keyPairQuery_uxid);
    }
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
        printf("%s\n","Response an uxout");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_uxid);
    free(valueQuery_uxid);
    keyValuePair_free(keyPairQuery_uxid);
    return elementToReturn;
end:
    return NULL;

}

// Verifies a Skycoin address.
//
inline_response_200_7_t*
DefaultAPI_verifyAddress(apiClient_t *apiClient ,char * address)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/address/verify")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/address/verify");




    // query parameters
    char *keyQuery_address;
    char * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = strdup((address));
        keyPairQuery_address = keyValuePair_create(keyQuery_address, valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }
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
        printf("%s\n","Response verifies a Skycoin address");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_7_t *elementToReturn = inline_response_200_7_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_address);
    free(valueQuery_address);
    keyValuePair_free(keyPairQuery_address);
    return elementToReturn;
end:
    return NULL;

}

// versionHandler returns the application version info
//
object_t*
DefaultAPI_version(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/version")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/version");



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
        printf("%s\n","BuildInfo represents the build info");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Returns a wallet by id.
//
object_t*
DefaultAPI_wallet(apiClient_t *apiClient ,char * id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }
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
        printf("%s\n","Response a wallet");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    return elementToReturn;
end:
    return NULL;

}

// Returns the wallet's balance, both confirmed and predicted.  The predicted balance is the confirmed balance minus the pending spends.
//
object_t*
DefaultAPI_walletBalance(apiClient_t *apiClient ,char * id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/balance")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/balance");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }
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
        printf("%s\n","Returns the wallets balance");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    return elementToReturn;
end:
    return NULL;

}

// Loads wallet from seed, will scan ahead N address and load addresses till the last one that have coins.
//
object_t*
DefaultAPI_walletCreate(apiClient_t *apiClient ,char * seed ,char * label ,int scan ,int encrypt ,char * password)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/create")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/create");




    // header parameters
    char *keyHeader_seed;
    char * valueHeader_seed;
    keyValuePair_t *keyPairHeader_seed = 0;
    if (seed) {
        keyHeader_seed = strdup("seed");
        valueHeader_seed = strdup((seed));
        keyPairHeader_seed = keyValuePair_create(keyHeader_seed, valueHeader_seed);
        list_addElement(localVarHeaderParameters,keyPairHeader_seed);
    }


    // header parameters
    char *keyHeader_label;
    char * valueHeader_label;
    keyValuePair_t *keyPairHeader_label = 0;
    if (label) {
        keyHeader_label = strdup("label");
        valueHeader_label = strdup((label));
        keyPairHeader_label = keyValuePair_create(keyHeader_label, valueHeader_label);
        list_addElement(localVarHeaderParameters,keyPairHeader_label);
    }


    // header parameters
    char *keyHeader_scan;
    int valueHeader_scan;
    keyValuePair_t *keyPairHeader_scan = 0;
    if (scan) {
        keyHeader_scan = strdup("scan");
        valueHeader_scan = (scan);
        keyPairHeader_scan = keyValuePair_create(keyHeader_scan, &valueHeader_scan);
        list_addElement(localVarHeaderParameters,keyPairHeader_scan);
    }


    // header parameters
    char *keyHeader_encrypt;
    int valueHeader_encrypt;
    keyValuePair_t *keyPairHeader_encrypt = 0;
    if (encrypt) {
        keyHeader_encrypt = strdup("encrypt");
        valueHeader_encrypt = (encrypt);
        keyPairHeader_encrypt = keyValuePair_create(keyHeader_encrypt, &valueHeader_encrypt);
        list_addElement(localVarHeaderParameters,keyPairHeader_encrypt);
    }


    // header parameters
    char *keyHeader_password;
    char * valueHeader_password;
    keyValuePair_t *keyPairHeader_password = 0;
    if (password) {
        keyHeader_password = strdup("password");
        valueHeader_password = strdup((password));
        keyPairHeader_password = keyValuePair_create(keyHeader_password, valueHeader_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_password);
    }

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
        printf("%s\n","This endpoint loads wallets from seed");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_seed);
    free(valueHeader_seed);
    free(keyPairHeader_seed);
    free(keyHeader_label);
    free(valueHeader_label);
    free(keyPairHeader_label);
    free(keyHeader_scan);
    free(keyPairHeader_scan);
    free(keyHeader_encrypt);
    free(keyPairHeader_encrypt);
    free(keyHeader_password);
    free(valueHeader_password);
    free(keyPairHeader_password);
    return elementToReturn;
end:
    return NULL;

}

// Decrypts wallet.
//
object_t*
DefaultAPI_walletDecrypt(apiClient_t *apiClient ,char * id ,char * password)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/decrypt")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/decrypt");




    // header parameters
    char *keyHeader_id;
    char * valueHeader_id;
    keyValuePair_t *keyPairHeader_id = 0;
    if (id) {
        keyHeader_id = strdup("id");
        valueHeader_id = strdup((id));
        keyPairHeader_id = keyValuePair_create(keyHeader_id, valueHeader_id);
        list_addElement(localVarHeaderParameters,keyPairHeader_id);
    }


    // header parameters
    char *keyHeader_password;
    char * valueHeader_password;
    keyValuePair_t *keyPairHeader_password = 0;
    if (password) {
        keyHeader_password = strdup("password");
        valueHeader_password = strdup((password));
        keyPairHeader_password = keyValuePair_create(keyHeader_password, valueHeader_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_password);
    }

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
        printf("%s\n","This endpoint decrypts wallets.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_id);
    free(valueHeader_id);
    free(keyPairHeader_id);
    free(keyHeader_password);
    free(valueHeader_password);
    free(keyPairHeader_password);
    return elementToReturn;
end:
    return NULL;

}

// Encrypt wallet.
//
object_t*
DefaultAPI_walletEncrypt(apiClient_t *apiClient ,char * id ,char * password)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/encrypt")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/encrypt");




    // header parameters
    char *keyHeader_id;
    char * valueHeader_id;
    keyValuePair_t *keyPairHeader_id = 0;
    if (id) {
        keyHeader_id = strdup("id");
        valueHeader_id = strdup((id));
        keyPairHeader_id = keyValuePair_create(keyHeader_id, valueHeader_id);
        list_addElement(localVarHeaderParameters,keyPairHeader_id);
    }


    // header parameters
    char *keyHeader_password;
    char * valueHeader_password;
    keyValuePair_t *keyPairHeader_password = 0;
    if (password) {
        keyHeader_password = strdup("password");
        valueHeader_password = strdup((password));
        keyPairHeader_password = keyValuePair_create(keyHeader_password, valueHeader_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_password);
    }

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
        printf("%s\n","This endpoint encrypt wallets.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_id);
    free(valueHeader_id);
    free(keyPairHeader_id);
    free(keyHeader_password);
    free(valueHeader_password);
    free(keyPairHeader_password);
    return elementToReturn;
end:
    return NULL;

}

// Returns the wallet directory path
//
inline_response_200_6_t*
DefaultAPI_walletFolder(apiClient_t *apiClient ,char * addr)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallets/folderName")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallets/folderName");




    // query parameters
    char *keyQuery_addr;
    char * valueQuery_addr;
    keyValuePair_t *keyPairQuery_addr = 0;
    if (addr)
    {
        keyQuery_addr = strdup("addr");
        valueQuery_addr = strdup((addr));
        keyPairQuery_addr = keyValuePair_create(keyQuery_addr, valueQuery_addr);
        list_addElement(localVarQueryParameters,keyPairQuery_addr);
    }
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
        printf("%s\n","This endpoint return the wallet directory path");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_6_t *elementToReturn = inline_response_200_6_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_addr);
    free(valueQuery_addr);
    keyValuePair_free(keyPairQuery_addr);
    return elementToReturn;
end:
    return NULL;

}

// Generates new addresses
//
object_t*
DefaultAPI_walletNewAddress(apiClient_t *apiClient ,char * id ,char * num ,char * password)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/newAddress")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/newAddress");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }

    // query parameters
    char *keyQuery_num;
    char * valueQuery_num;
    keyValuePair_t *keyPairQuery_num = 0;
    if (num)
    {
        keyQuery_num = strdup("num");
        valueQuery_num = strdup((num));
        keyPairQuery_num = keyValuePair_create(keyQuery_num, valueQuery_num);
        list_addElement(localVarQueryParameters,keyPairQuery_num);
    }

    // query parameters
    char *keyQuery_password;
    char * valueQuery_password;
    keyValuePair_t *keyPairQuery_password = 0;
    if (password)
    {
        keyQuery_password = strdup("password");
        valueQuery_password = strdup((password));
        keyPairQuery_password = keyValuePair_create(keyQuery_password, valueQuery_password);
        list_addElement(localVarQueryParameters,keyPairQuery_password);
    }
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
        printf("%s\n","This endpoint generate new addresses");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    free(keyQuery_num);
    free(valueQuery_num);
    keyValuePair_free(keyPairQuery_num);
    free(keyQuery_password);
    free(valueQuery_password);
    keyValuePair_free(keyPairQuery_password);
    return elementToReturn;
end:
    return NULL;

}

// Returns the wallet directory path
//
object_t*
DefaultAPI_walletNewSeed(apiClient_t *apiClient, char* entropy) {
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/newSeed")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/newSeed");




    // query parameters
    char *keyQuery_entropy;
    char *valueQuery_entropy;
    keyValuePair_t *keyPairQuery_entropy = 0;
    if (entropy)
    {
        keyQuery_entropy = strdup("entropy");
        valueQuery_entropy = (entropy);
        keyPairQuery_entropy = keyValuePair_create(keyQuery_entropy, (void *)valueQuery_entropy);
        list_addElement(localVarQueryParameters,keyPairQuery_entropy);
    }
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
        printf("%s\n","Generates wallet seed");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_entropy);
    free(valueQuery_entropy);
    keyValuePair_free(keyPairQuery_entropy);
    return elementToReturn;
end:
    return NULL;

}

// Recovers an encrypted wallet by providing the seed. The first address will be generated from seed and compared to the first address of the specified wallet. If they match, the wallet will be regenerated with an optional password. If the wallet is not encrypted, an error is returned.
//
object_t*
DefaultAPI_walletRecover(apiClient_t *apiClient ,char * id ,char * seed ,char * password)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/wallet/recover")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/wallet/recover");




    // header parameters
    char *keyHeader_id;
    char * valueHeader_id;
    keyValuePair_t *keyPairHeader_id = 0;
    if (id) {
        keyHeader_id = strdup("id");
        valueHeader_id = strdup((id));
        keyPairHeader_id = keyValuePair_create(keyHeader_id, valueHeader_id);
        list_addElement(localVarHeaderParameters,keyPairHeader_id);
    }


    // header parameters
    char *keyHeader_seed;
    char * valueHeader_seed;
    keyValuePair_t *keyPairHeader_seed = 0;
    if (seed) {
        keyHeader_seed = strdup("seed");
        valueHeader_seed = strdup((seed));
        keyPairHeader_seed = keyValuePair_create(keyHeader_seed, valueHeader_seed);
        list_addElement(localVarHeaderParameters,keyPairHeader_seed);
    }


    // header parameters
    char *keyHeader_password;
    char * valueHeader_password;
    keyValuePair_t *keyPairHeader_password = 0;
    if (password) {
        keyHeader_password = strdup("password");
        valueHeader_password = strdup((password));
        keyPairHeader_password = keyValuePair_create(keyHeader_password, valueHeader_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_password);
    }

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
        printf("%s\n","This endpoint recover wallets.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_id);
    free(valueHeader_id);
    free(keyPairHeader_id);
    free(keyHeader_seed);
    free(valueHeader_seed);
    free(keyPairHeader_seed);
    free(keyHeader_password);
    free(valueHeader_password);
    free(keyPairHeader_password);
    return elementToReturn;
end:
    return NULL;

}

// This endpoint only works for encrypted wallets. If the wallet is unencrypted, The seed will be not returned.
//
object_t*
DefaultAPI_walletSeed(apiClient_t *apiClient ,char * id ,char * password)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/seed")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/seed");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }

    // query parameters
    char *keyQuery_password;
    char * valueQuery_password;
    keyValuePair_t *keyPairQuery_password = 0;
    if (password)
    {
        keyQuery_password = strdup("password");
        valueQuery_password = strdup((password));
        keyPairQuery_password = keyValuePair_create(keyQuery_password, valueQuery_password);
        list_addElement(localVarQueryParameters,keyPairQuery_password);
    }
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
        printf("%s\n","This endpoint Returns seed of wallet of given id");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    free(keyQuery_password);
    free(valueQuery_password);
    keyValuePair_free(keyPairQuery_password);
    return elementToReturn;
end:
    return NULL;

}

// Verifies a wallet seed.
//
object_t*
DefaultAPI_walletSeedVerify(apiClient_t *apiClient ,char * seed)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/wallet/seed/verify")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/wallet/seed/verify");




    // header parameters
    char *keyHeader_seed;
    char * valueHeader_seed;
    keyValuePair_t *keyPairHeader_seed = 0;
    if (seed) {
        keyHeader_seed = strdup("seed");
        valueHeader_seed = strdup((seed));
        keyPairHeader_seed = keyValuePair_create(keyHeader_seed, valueHeader_seed);
        list_addElement(localVarHeaderParameters,keyPairHeader_seed);
    }

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
        printf("%s\n","Verifies a wallet seed.");
    }
    if (apiClient->response_code == 422) {
        printf("%s\n","Wrong Seed");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_seed);
    free(valueHeader_seed);
    free(keyPairHeader_seed);
    return elementToReturn;
end:
    return NULL;

}

// Creates and broadcasts a transaction sending money from one of our wallets to destination address.
//
object_t*
DefaultAPI_walletSpent(apiClient_t *apiClient ,char * id ,char * dst ,char * coins ,char * password)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/spend")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/spend");




    // header parameters
    char *keyHeader_id;
    char * valueHeader_id;
    keyValuePair_t *keyPairHeader_id = 0;
    if (id) {
        keyHeader_id = strdup("id");
        valueHeader_id = strdup((id));
        keyPairHeader_id = keyValuePair_create(keyHeader_id, valueHeader_id);
        list_addElement(localVarHeaderParameters,keyPairHeader_id);
    }


    // header parameters
    char *keyHeader_dst;
    char * valueHeader_dst;
    keyValuePair_t *keyPairHeader_dst = 0;
    if (dst) {
        keyHeader_dst = strdup("dst");
        valueHeader_dst = strdup((dst));
        keyPairHeader_dst = keyValuePair_create(keyHeader_dst, valueHeader_dst);
        list_addElement(localVarHeaderParameters,keyPairHeader_dst);
    }


    // header parameters
    char *keyHeader_coins;
    char * valueHeader_coins;
    keyValuePair_t *keyPairHeader_coins = 0;
    if (coins) {
        keyHeader_coins = strdup("coins");
        valueHeader_coins = strdup((coins));
        keyPairHeader_coins = keyValuePair_create(keyHeader_coins, valueHeader_coins);
        list_addElement(localVarHeaderParameters,keyPairHeader_coins);
    }


    // header parameters
    char *keyHeader_password;
    char * valueHeader_password;
    keyValuePair_t *keyPairHeader_password = 0;
    if (password) {
        keyHeader_password = strdup("password");
        valueHeader_password = strdup((password));
        keyPairHeader_password = keyValuePair_create(keyHeader_password, valueHeader_password);
        list_addElement(localVarHeaderParameters,keyPairHeader_password);
    }

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
        printf("%s\n","Creates and broadcasts a transaction sending money from one of our wallets to destination address.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_id);
    free(valueHeader_id);
    free(keyPairHeader_id);
    free(keyHeader_dst);
    free(valueHeader_dst);
    free(keyPairHeader_dst);
    free(keyHeader_coins);
    free(valueHeader_coins);
    free(keyPairHeader_coins);
    free(keyHeader_password);
    free(valueHeader_password);
    free(keyPairHeader_password);
    return elementToReturn;
end:
    return NULL;

}

// Creates a signed transaction
//
object_t*
DefaultAPI_walletTransaction(apiClient_t *apiClient ,inline_object_t * body)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/transaction")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/transaction");




    // Body Param
    cJSON *localVarSingleItemJSON_body;
    if (body != NULL)
    {
        //string
        localVarSingleItemJSON_body = inline_object_convertToJSON(body);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_body);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    list_addElement(localVarContentType,"application/xml"); //consumes
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
        printf("%s\n","Returns wallet transaction");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
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
    cJSON_Delete(localVarSingleItemJSON_body);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Returns returns all unconfirmed transactions for all addresses in a given wallet verbose
//
object_t*
DefaultAPI_walletTransactions(apiClient_t *apiClient ,char * id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/transactions")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/transactions");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }
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
        printf("%s\n","Returns wallet transactions");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    object_t *elementToReturn = object_parseFromJSON(DefaultAPIlocalVarJSON);
    cJSON_Delete(DefaultAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    return elementToReturn;
end:
    return NULL;

}

// Unloads wallet from the wallet service.
//
void
DefaultAPI_walletUnload(apiClient_t *apiClient ,char * id)
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/unload")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/unload");




    // query parameters
    char *keyQuery_id;
    char * valueQuery_id;
    keyValuePair_t *keyPairQuery_id = 0;
    if (id)
    {
        keyQuery_id = strdup("id");
        valueQuery_id = strdup((id));
        keyPairQuery_id = keyValuePair_create(keyQuery_id, valueQuery_id);
        list_addElement(localVarQueryParameters,keyPairQuery_id);
    }
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
        printf("%s\n","This endpoint returns nothing.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }
    list_free(localVarQueryParameters);


    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyQuery_id);
    free(valueQuery_id);
    keyValuePair_free(keyPairQuery_id);
    free(keyQuery_id);
    keyValuePair_free(keyPairQuery_id);

}

// Update the wallet.
//
void
DefaultAPI_walletUpdate(apiClient_t *apiClient ,char * id ,char * label)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallet/update")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallet/update");




    // header parameters
    char *keyHeader_id;
    char * valueHeader_id;
    keyValuePair_t *keyPairHeader_id = 0;
    if (id) {
        keyHeader_id = strdup("id");
        valueHeader_id = strdup((id));
        keyPairHeader_id = keyValuePair_create(keyHeader_id, valueHeader_id);
        list_addElement(localVarHeaderParameters,keyPairHeader_id);
    }


    // header parameters
    char *keyHeader_label;
    char * valueHeader_label;
    keyValuePair_t *keyPairHeader_label = 0;
    if (label) {
        keyHeader_label = strdup("label");
        valueHeader_label = strdup((label));
        keyPairHeader_label = keyValuePair_create(keyHeader_label, valueHeader_label);
        list_addElement(localVarHeaderParameters,keyPairHeader_label);
    }

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
        printf("%s\n","This endpoint Returns the label the wallet will be updated to .");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_id);
    free(valueHeader_id);
    free(keyPairHeader_id);
    free(keyHeader_label);
    free(valueHeader_label);
    free(keyPairHeader_label);

}

// Returns all loaded wallets
//
list_t*
DefaultAPI_wallets(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/wallets")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/wallets");



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
        printf("%s\n","This endpoint return all loaded wallets");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    if(!cJSON_IsArray(DefaultAPIlocalVarJSON)) {
        return 0;//nonprimitive container
    }
    list_t *elementToReturn = list_create();
    cJSON *VarJSON;
    cJSON_ArrayForEach(VarJSON, DefaultAPIlocalVarJSON)
    {
        if(!cJSON_IsObject(VarJSON))
        {
           // return 0;
        }
        char *localVarJSONToChar = cJSON_Print(VarJSON);
        list_addElement(elementToReturn , localVarJSONToChar);
    }

    cJSON_Delete( DefaultAPIlocalVarJSON);
    cJSON_Delete( VarJSON);
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

