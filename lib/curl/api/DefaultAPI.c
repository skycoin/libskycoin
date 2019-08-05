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
inline_response_200_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","addressCount response object");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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

char*
DefaultAPI_apiV1RawtxGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/rawtx")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/rawtx");



    list_addElement(localVarHeaderType,"text/plain"); //produces
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
        printf("%s\n","Response is araw transaction by id");
    }
    //primitive reutrn type simple
    char* elementToReturn =  strdup((char*)apiClient->dataReceived);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }



    list_free(localVarHeaderType);

    free(localVarPath);
    return elementToReturn;
end:
    return NULL;

}

char*
DefaultAPI_apiV2MetricsGet(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/metrics")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/metrics");



    list_addElement(localVarHeaderType,"text/plain"); //produces
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
        printf("%s\n","Metrics");
    }
    //primitive reutrn type simple
    char* elementToReturn =  strdup((char*)apiClient->dataReceived);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }



    list_free(localVarHeaderType);

    free(localVarPath);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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

// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
list_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Return block Array");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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

// Returns the balance of one or more addresses, both confirmed and predicted. The predicted balance is the confirmed balance minus the pending spends.
//
inline_response_200_1_t*
DefaultAPI_blocks(apiClient_t *apiClient ,int start ,int end ,list_t * seq)
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
    if (seq)
    {
        list_addElement(localVarQueryParameters,seq);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Get blocks in specific range");
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
inline_response_200_2_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    inline_response_200_2_t *elementToReturn = inline_response_200_2_parseFromJSON(DefaultAPIlocalVarJSON);
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
inline_response_200_3_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    inline_response_200_3_t *elementToReturn = inline_response_200_3_parseFromJSON(DefaultAPIlocalVarJSON);
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

void
DefaultAPI_dataDELETE(apiClient_t *apiClient ,char * type ,char * key)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/data")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/data");




    // header parameters
    char *keyHeader_type;
    char * valueHeader_type;
    keyValuePair_t *keyPairHeader_type = 0;
    if (type) {
        keyHeader_type = strdup("type");
        valueHeader_type = strdup((type));
        keyPairHeader_type = keyValuePair_create(keyHeader_type, valueHeader_type);
        list_addElement(localVarHeaderParameters,keyPairHeader_type);
    }


    // header parameters
    char *keyHeader_key;
    char * valueHeader_key;
    keyValuePair_t *keyPairHeader_key = 0;
    if (key) {
        keyHeader_key = strdup("key");
        valueHeader_key = strdup((key));
        keyPairHeader_key = keyValuePair_create(keyHeader_key, valueHeader_key);
        list_addElement(localVarHeaderParameters,keyPairHeader_key);
    }

    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint returns empty json");
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
    free(keyHeader_type);
    free(valueHeader_type);
    free(keyPairHeader_type);
    free(keyHeader_key);
    free(valueHeader_key);
    free(keyPairHeader_key);

}

object_t*
DefaultAPI_dataGET(apiClient_t *apiClient ,char * type ,char * key)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/data")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/data");




    // header parameters
    char *keyHeader_type;
    char * valueHeader_type;
    keyValuePair_t *keyPairHeader_type = 0;
    if (type) {
        keyHeader_type = strdup("type");
        valueHeader_type = strdup((type));
        keyPairHeader_type = keyValuePair_create(keyHeader_type, valueHeader_type);
        list_addElement(localVarHeaderParameters,keyPairHeader_type);
    }


    // header parameters
    char *keyHeader_key;
    char * valueHeader_key;
    keyValuePair_t *keyPairHeader_key = 0;
    if (key) {
        keyHeader_key = strdup("key");
        valueHeader_key = strdup((key));
        keyPairHeader_key = keyValuePair_create(keyHeader_key, valueHeader_key);
        list_addElement(localVarHeaderParameters,keyPairHeader_key);
    }

    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Return multiKey");
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
    free(keyHeader_type);
    free(valueHeader_type);
    free(keyPairHeader_type);
    free(keyHeader_key);
    free(valueHeader_key);
    free(keyPairHeader_key);
    return elementToReturn;
end:
    return NULL;

}

void
DefaultAPI_dataPOST(apiClient_t *apiClient ,char * type ,char * key ,char * val)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/data")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/data");




    // header parameters
    char *keyHeader_type;
    char * valueHeader_type;
    keyValuePair_t *keyPairHeader_type = 0;
    if (type) {
        keyHeader_type = strdup("type");
        valueHeader_type = strdup((type));
        keyPairHeader_type = keyValuePair_create(keyHeader_type, valueHeader_type);
        list_addElement(localVarHeaderParameters,keyPairHeader_type);
    }


    // header parameters
    char *keyHeader_key;
    char * valueHeader_key;
    keyValuePair_t *keyPairHeader_key = 0;
    if (key) {
        keyHeader_key = strdup("key");
        valueHeader_key = strdup((key));
        keyPairHeader_key = keyValuePair_create(keyHeader_key, valueHeader_key);
        list_addElement(localVarHeaderParameters,keyPairHeader_key);
    }


    // header parameters
    char *keyHeader_val;
    char * valueHeader_val;
    keyValuePair_t *keyPairHeader_val = 0;
    if (val) {
        keyHeader_val = strdup("val");
        valueHeader_val = strdup((val));
        keyPairHeader_val = keyValuePair_create(keyHeader_val, valueHeader_val);
        list_addElement(localVarHeaderParameters,keyPairHeader_val);
    }

    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint returns empty json");
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
    free(keyHeader_type);
    free(valueHeader_type);
    free(keyPairHeader_type);
    free(keyHeader_key);
    free(valueHeader_key);
    free(keyPairHeader_key);
    free(keyHeader_val);
    free(valueHeader_val);
    free(keyPairHeader_val);

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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint return an list of default connections.");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Returns the most recent N blocks on the blockchain");
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
network_connection_schema_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint return a connection struct");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    network_connection_schema_t *elementToReturn = network_connection_schema_parseFromJSON(DefaultAPIlocalVarJSON);
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
inline_response_200_4_t*
DefaultAPI_networkConnections(apiClient_t *apiClient, char* states, char* direction)
{
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
        keyQuery_states = strdup("states");
        valueQuery_states = (states);
        keyPairQuery_states = keyValuePair_create(keyQuery_states, (void *)valueQuery_states);
        list_addElement(localVarQueryParameters,keyPairQuery_states);
    }

    // query parameters
    char *keyQuery_direction;
    char *valueQuery_direction;
    keyValuePair_t *keyPairQuery_direction = 0;
    if (direction)
    {
        keyQuery_direction = strdup("direction");
        valueQuery_direction = (direction);
        keyPairQuery_direction = keyValuePair_create(keyQuery_direction, (void *)valueQuery_direction);
        list_addElement(localVarQueryParameters,keyPairQuery_direction);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint return networks connections");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_4_t *elementToReturn = inline_response_200_4_parseFromJSON(DefaultAPIlocalVarJSON);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint return a list of trusted connections.");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","UnspentOutputsSummary records unspent outputs in different status.");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","UnspentOutputsSummary records unspent outputs in different status.");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Transaction inputs include the owner address, coins, hours and calculated hours.");
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
object_t*
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



    list_addElement(localVarHeaderType,"application-json"); //produces
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Represent richlist response");
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

// Returns a transaction identified by its txid hash with just id
//
transaction_t*
DefaultAPI_transaction(apiClient_t *apiClient ,char * txid)
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
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    transaction_t *elementToReturn = transaction_parseFromJSON(DefaultAPIlocalVarJSON);
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

// Broadcast a hex-encoded, serialized transaction to the network.
//
char*
DefaultAPI_transactionInject(apiClient_t *apiClient ,char * rawtx ,int no_broadcast)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = list_create();
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v1/injectTransaction")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v1/injectTransaction");




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


    // header parameters
    char *keyHeader_no_broadcast;
    int valueHeader_no_broadcast;
    keyValuePair_t *keyPairHeader_no_broadcast = 0;
    if (no_broadcast) {
        keyHeader_no_broadcast = strdup("no_broadcast");
        valueHeader_no_broadcast = (no_broadcast);
        keyPairHeader_no_broadcast = keyValuePair_create(keyHeader_no_broadcast, &valueHeader_no_broadcast);
        list_addElement(localVarHeaderParameters,keyPairHeader_no_broadcast);
    }

    list_addElement(localVarHeaderType,"text/plain"); //produces
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Broadcasts a hex-encoded, serialized transaction to the network");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //primitive reutrn type simple
    char* elementToReturn =  strdup((char*)apiClient->dataReceived);

    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
    }

    list_free(localVarHeaderParameters);

    list_free(localVarHeaderType);

    free(localVarPath);
    free(keyHeader_rawtx);
    free(valueHeader_rawtx);
    free(keyPairHeader_rawtx);
    free(keyHeader_no_broadcast);
    free(keyPairHeader_no_broadcast);
    return elementToReturn;
end:
    return NULL;

}

inline_response_200_8_t*
DefaultAPI_transactionPost(apiClient_t *apiClient ,transaction_v2_params_address_t * transaction_v2_params_address)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/transaction")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/transaction");




    // Body Param
    cJSON *localVarSingleItemJSON_transaction_v2_params_address;
    if (transaction_v2_params_address != NULL)
    {
        //string
        localVarSingleItemJSON_transaction_v2_params_address = transaction_v2_params_address_convertToJSON(transaction_v2_params_address);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_transaction_v2_params_address);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Response is a transaction");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_8_t *elementToReturn = inline_response_200_8_parseFromJSON(DefaultAPIlocalVarJSON);
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
    cJSON_Delete(localVarSingleItemJSON_transaction_v2_params_address);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

inline_response_200_8_t*
DefaultAPI_transactionPostUnspent(apiClient_t *apiClient ,transaction_v2_params_unspent_t * transaction_v2_params_unspent)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/transaction/unspent")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/transaction/unspent");




    // Body Param
    cJSON *localVarSingleItemJSON_transaction_v2_params_unspent;
    if (transaction_v2_params_unspent != NULL)
    {
        //string
        localVarSingleItemJSON_transaction_v2_params_unspent = transaction_v2_params_unspent_convertToJSON(transaction_v2_params_unspent);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_transaction_v2_params_unspent);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Response is a transaction");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_8_t *elementToReturn = inline_response_200_8_parseFromJSON(DefaultAPIlocalVarJSON);
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
    cJSON_Delete(localVarSingleItemJSON_transaction_v2_params_unspent);
    free(localVarBodyParameters);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
DefaultAPI_transactionVerify(apiClient_t *apiClient ,transaction_verify_request_t * transaction_verify_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/transaction/verify")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/transaction/verify");




    // Body Param
    cJSON *localVarSingleItemJSON_transaction_verify_request;
    if (transaction_verify_request != NULL)
    {
        //string
        localVarSingleItemJSON_transaction_verify_request = transaction_verify_request_convertToJSON(transaction_verify_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_transaction_verify_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Responses ok");
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
    cJSON_Delete(localVarSingleItemJSON_transaction_verify_request);
    free(localVarBodyParameters);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Response for endpoint /api/v1/uxout");
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
object_t*
DefaultAPI_verifyAddress(apiClient_t *apiClient ,object_t * address)
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
    object_t * valueQuery_address;
    keyValuePair_t *keyPairQuery_address = 0;
    if (address)
    {
        keyQuery_address = strdup("address");
        valueQuery_address = (address);
        keyPairQuery_address = keyValuePair_create(keyQuery_address, &valueQuery_address);
        list_addElement(localVarQueryParameters,keyPairQuery_address);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","");
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
    keyValuePair_free(keyPairQuery_address);
    return elementToReturn;
end:
    return NULL;

}

// versionHandler returns the application version info
//
inline_response_200_5_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    inline_response_200_5_t *elementToReturn = inline_response_200_5_parseFromJSON(DefaultAPIlocalVarJSON);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Response for endpoint /api/v1/wallet");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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

// Create a wallet
//
object_t*
DefaultAPI_walletCreate(apiClient_t *apiClient ,char * type ,char * seed ,char * label ,char * seed_passphrase ,char * bip44_coin ,char * xpub ,int scan ,int encrypt ,char * password)
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
    char *keyHeader_seed_passphrase;
    char * valueHeader_seed_passphrase;
    keyValuePair_t *keyPairHeader_seed_passphrase = 0;
    if (seed_passphrase) {
        keyHeader_seed_passphrase = strdup("seed_passphrase");
        valueHeader_seed_passphrase = strdup((seed_passphrase));
        keyPairHeader_seed_passphrase = keyValuePair_create(keyHeader_seed_passphrase, valueHeader_seed_passphrase);
        list_addElement(localVarHeaderParameters,keyPairHeader_seed_passphrase);
    }


    // header parameters
    char *keyHeader_type;
    char * valueHeader_type;
    keyValuePair_t *keyPairHeader_type = 0;
    if (type) {
        keyHeader_type = strdup("type");
        valueHeader_type = strdup((type));
        keyPairHeader_type = keyValuePair_create(keyHeader_type, valueHeader_type);
        list_addElement(localVarHeaderParameters,keyPairHeader_type);
    }


    // header parameters
    char *keyHeader_bip44_coin;
    char * valueHeader_bip44_coin;
    keyValuePair_t *keyPairHeader_bip44_coin = 0;
    if (bip44_coin) {
        keyHeader_bip44_coin = strdup("bip44_coin");
        valueHeader_bip44_coin = strdup((bip44_coin));
        keyPairHeader_bip44_coin = keyValuePair_create(keyHeader_bip44_coin, valueHeader_bip44_coin);
        list_addElement(localVarHeaderParameters,keyPairHeader_bip44_coin);
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
    char *keyHeader_xpub;
    char * valueHeader_xpub;
    keyValuePair_t *keyPairHeader_xpub = 0;
    if (xpub) {
        keyHeader_xpub = strdup("xpub");
        valueHeader_xpub = strdup((xpub));
        keyPairHeader_xpub = keyValuePair_create(keyHeader_xpub, valueHeader_xpub);
        list_addElement(localVarHeaderParameters,keyPairHeader_xpub);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Response for endpoint /api/v1/wallet");
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
    free(keyHeader_seed_passphrase);
    free(valueHeader_seed_passphrase);
    free(keyPairHeader_seed_passphrase);
    free(keyHeader_type);
    free(valueHeader_type);
    free(keyPairHeader_type);
    free(keyHeader_bip44_coin);
    free(valueHeader_bip44_coin);
    free(keyPairHeader_bip44_coin);
    free(keyHeader_seed);
    free(valueHeader_seed);
    free(keyPairHeader_seed);
    free(keyHeader_xpub);
    free(valueHeader_xpub);
    free(keyPairHeader_xpub);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
inline_response_200_7_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
// Recovers an encrypted wallet by providing the wallet seed and optional seed passphrase
//
object_t*
DefaultAPI_walletRecover(apiClient_t *apiClient ,char * id ,char * seed ,char * seed_passphrase ,char * password)
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
    char *keyHeader_seed_passphrase;
    char * valueHeader_seed_passphrase;
    keyValuePair_t *keyPairHeader_seed_passphrase = 0;
    if (seed_passphrase) {
        keyHeader_seed_passphrase = strdup("seed_passphrase");
        valueHeader_seed_passphrase = strdup((seed_passphrase));
        keyPairHeader_seed_passphrase = keyValuePair_create(keyHeader_seed_passphrase, valueHeader_seed_passphrase);
        list_addElement(localVarHeaderParameters,keyPairHeader_seed_passphrase);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    free(keyHeader_seed_passphrase);
    free(valueHeader_seed_passphrase);
    free(keyPairHeader_seed_passphrase);
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
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

// Creates a signed transaction
//
object_t*
DefaultAPI_walletTransaction(apiClient_t *apiClient ,wallet_transaction_request_t * wallet_transaction_request)
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
    cJSON *localVarSingleItemJSON_wallet_transaction_request;
    if (wallet_transaction_request != NULL)
    {
        //string
        localVarSingleItemJSON_wallet_transaction_request = wallet_transaction_request_convertToJSON(wallet_transaction_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_wallet_transaction_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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



    list_free(localVarHeaderType);
    list_free(localVarContentType);
    free(localVarPath);
    cJSON_Delete(localVarSingleItemJSON_wallet_transaction_request);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

// Creates a signed transaction
//
inline_response_200_9_t*
DefaultAPI_walletTransactionSign(apiClient_t *apiClient ,wallet_transaction_sign_request_t * wallet_transaction_sign_request)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_create();
    list_t *localVarContentType = list_create();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/api/v2/wallet/transaction/sign")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/api/v2/wallet/transaction/sign");




    // Body Param
    cJSON *localVarSingleItemJSON_wallet_transaction_sign_request;
    if (wallet_transaction_sign_request != NULL)
    {
        //string
        localVarSingleItemJSON_wallet_transaction_sign_request = wallet_transaction_sign_request_convertToJSON(wallet_transaction_sign_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_wallet_transaction_sign_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","Signs an unsigned transaction, returning the transaction with updated signatures and the encoded, serialized transaction.");
    }
    if (apiClient->response_code == 0) {
        printf("%s\n","A GenericError is the default error message that is generated. For certain status codes there are more appropriate error structures.");
    }
    //nonprimitive not container
    cJSON *DefaultAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    inline_response_200_9_t *elementToReturn = inline_response_200_9_parseFromJSON(DefaultAPIlocalVarJSON);
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
    cJSON_Delete(localVarSingleItemJSON_wallet_transaction_sign_request);
    free(localVarBodyParameters);
    return elementToReturn;
end:
    return NULL;

}

inline_response_200_6_t*
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
        printf("%s\n","This endpoint returns all unconfirmed transactions for all addresses in a given wallet.");
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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
char*
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

    list_addElement(localVarHeaderType,"text/plain"); //produces
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarHeaderType,"application/xml"); //produces
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
    //primitive reutrn type simple
    char* elementToReturn =  strdup((char*)apiClient->dataReceived);

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
    return elementToReturn;
end:
    return NULL;

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
    list_addElement(localVarHeaderType,"application/xml"); //produces
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

