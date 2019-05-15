#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_wallet_transaction_to.h"



_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to_create(
    long hours,
    char *address,
    long coins
    ) {
	_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to_local_var = malloc(sizeof(_api_v1_wallet_transaction_to_t));
    if (!_api_v1_wallet_transaction_to_local_var) {
        return NULL;
    }
	_api_v1_wallet_transaction_to_local_var->hours = hours;
	_api_v1_wallet_transaction_to_local_var->address = address;
	_api_v1_wallet_transaction_to_local_var->coins = coins;

	return _api_v1_wallet_transaction_to_local_var;
}


void _api_v1_wallet_transaction_to_free(_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to) {
    listEntry_t *listEntry;
    free(_api_v1_wallet_transaction_to->address);
	free(_api_v1_wallet_transaction_to);
}

cJSON *_api_v1_wallet_transaction_to_convertToJSON(_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_wallet_transaction_to->hours
    if(_api_v1_wallet_transaction_to->hours) { 
    if(cJSON_AddNumberToObject(item, "hours", _api_v1_wallet_transaction_to->hours) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_wallet_transaction_to->address
    if(_api_v1_wallet_transaction_to->address) { 
    if(cJSON_AddStringToObject(item, "address", _api_v1_wallet_transaction_to->address) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallet_transaction_to->coins
    if(_api_v1_wallet_transaction_to->coins) { 
    if(cJSON_AddNumberToObject(item, "coins", _api_v1_wallet_transaction_to->coins) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

_api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to_parseFromJSON(cJSON *_api_v1_wallet_transaction_toJSON){

    _api_v1_wallet_transaction_to_t *_api_v1_wallet_transaction_to_local_var = NULL;

    // _api_v1_wallet_transaction_to->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_toJSON, "hours");
    if (hours) { 
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_wallet_transaction_to->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_toJSON, "address");
    if (address) { 
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }
    }

    // _api_v1_wallet_transaction_to->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(_api_v1_wallet_transaction_toJSON, "coins");
    if (coins) { 
    if(!cJSON_IsNumber(coins))
    {
    goto end; //Numeric
    }
    }


    _api_v1_wallet_transaction_to_local_var = _api_v1_wallet_transaction_to_create (
        hours ? hours->valuedouble : 0,
        address ? strdup(address->valuestring) : NULL,
        coins ? coins->valuedouble : 0
        );

    return _api_v1_wallet_transaction_to_local_var;
end:
    return NULL;

}
