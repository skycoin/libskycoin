#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_pending_txs_transaction_outputs.h"



_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs_create(
    char *uxid,
    char *dst,
    char *coins,
    long hours
    ) {
	_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs_local_var = malloc(sizeof(_api_v1_pending_txs_transaction_outputs_t));
    if (!_api_v1_pending_txs_transaction_outputs_local_var) {
        return NULL;
    }
	_api_v1_pending_txs_transaction_outputs_local_var->uxid = uxid;
	_api_v1_pending_txs_transaction_outputs_local_var->dst = dst;
	_api_v1_pending_txs_transaction_outputs_local_var->coins = coins;
	_api_v1_pending_txs_transaction_outputs_local_var->hours = hours;

	return _api_v1_pending_txs_transaction_outputs_local_var;
}


void _api_v1_pending_txs_transaction_outputs_free(_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs) {
    listEntry_t *listEntry;
    free(_api_v1_pending_txs_transaction_outputs->uxid);
    free(_api_v1_pending_txs_transaction_outputs->dst);
    free(_api_v1_pending_txs_transaction_outputs->coins);
	free(_api_v1_pending_txs_transaction_outputs);
}

cJSON *_api_v1_pending_txs_transaction_outputs_convertToJSON(_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_pending_txs_transaction_outputs->uxid
    if(_api_v1_pending_txs_transaction_outputs->uxid) { 
    if(cJSON_AddStringToObject(item, "uxid", _api_v1_pending_txs_transaction_outputs->uxid) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_pending_txs_transaction_outputs->dst
    if(_api_v1_pending_txs_transaction_outputs->dst) { 
    if(cJSON_AddStringToObject(item, "dst", _api_v1_pending_txs_transaction_outputs->dst) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_pending_txs_transaction_outputs->coins
    if(_api_v1_pending_txs_transaction_outputs->coins) { 
    if(cJSON_AddStringToObject(item, "coins", _api_v1_pending_txs_transaction_outputs->coins) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_pending_txs_transaction_outputs->hours
    if(_api_v1_pending_txs_transaction_outputs->hours) { 
    if(cJSON_AddNumberToObject(item, "hours", _api_v1_pending_txs_transaction_outputs->hours) == NULL) {
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

_api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs_parseFromJSON(cJSON *_api_v1_pending_txs_transaction_outputsJSON){

    _api_v1_pending_txs_transaction_outputs_t *_api_v1_pending_txs_transaction_outputs_local_var = NULL;

    // _api_v1_pending_txs_transaction_outputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transaction_outputsJSON, "uxid");
    if (uxid) { 
    if(!cJSON_IsString(uxid))
    {
    goto end; //String
    }
    }

    // _api_v1_pending_txs_transaction_outputs->dst
    cJSON *dst = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transaction_outputsJSON, "dst");
    if (dst) { 
    if(!cJSON_IsString(dst))
    {
    goto end; //String
    }
    }

    // _api_v1_pending_txs_transaction_outputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transaction_outputsJSON, "coins");
    if (coins) { 
    if(!cJSON_IsString(coins))
    {
    goto end; //String
    }
    }

    // _api_v1_pending_txs_transaction_outputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transaction_outputsJSON, "hours");
    if (hours) { 
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }
    }


    _api_v1_pending_txs_transaction_outputs_local_var = _api_v1_pending_txs_transaction_outputs_create (
        uxid ? strdup(uxid->valuestring) : NULL,
        dst ? strdup(dst->valuestring) : NULL,
        coins ? strdup(coins->valuestring) : NULL,
        hours ? hours->valuedouble : 0
        );

    return _api_v1_pending_txs_transaction_outputs_local_var;
end:
    return NULL;

}
