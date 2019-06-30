#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_pending_txs_transaction.h"



_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    list_t *sigs,
    int length,
    char *txid,
    int type,
    int timestamp
    ) {
	_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_local_var = malloc(sizeof(_api_v1_pending_txs_transaction_t));
    if (!_api_v1_pending_txs_transaction_local_var) {
        return NULL;
    }
	_api_v1_pending_txs_transaction_local_var->outputs = outputs;
	_api_v1_pending_txs_transaction_local_var->inner_hash = inner_hash;
	_api_v1_pending_txs_transaction_local_var->inputs = inputs;
	_api_v1_pending_txs_transaction_local_var->sigs = sigs;
	_api_v1_pending_txs_transaction_local_var->length = length;
	_api_v1_pending_txs_transaction_local_var->txid = txid;
	_api_v1_pending_txs_transaction_local_var->type = type;
	_api_v1_pending_txs_transaction_local_var->timestamp = timestamp;

	return _api_v1_pending_txs_transaction_local_var;
}


void _api_v1_pending_txs_transaction_free(_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, _api_v1_pending_txs_transaction->outputs) {
		_api_v1_explorer_address_outputs_free(listEntry->data);
	}
	list_free(_api_v1_pending_txs_transaction->outputs);
    free(_api_v1_pending_txs_transaction->inner_hash);
	list_ForEach(listEntry, _api_v1_pending_txs_transaction->inputs) {
		free(listEntry->data);
	}
	list_free(_api_v1_pending_txs_transaction->inputs);
	list_ForEach(listEntry, _api_v1_pending_txs_transaction->sigs) {
		free(listEntry->data);
	}
	list_free(_api_v1_pending_txs_transaction->sigs);
    free(_api_v1_pending_txs_transaction->txid);
	free(_api_v1_pending_txs_transaction);
}

cJSON *_api_v1_pending_txs_transaction_convertToJSON(_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_pending_txs_transaction->outputs
    if(_api_v1_pending_txs_transaction->outputs) { 
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
    if(outputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *outputsListEntry;
    if (_api_v1_pending_txs_transaction->outputs) {
    list_ForEach(outputsListEntry, _api_v1_pending_txs_transaction->outputs) {
    cJSON *itemLocal = _api_v1_explorer_address_outputs_convertToJSON(outputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(outputs, itemLocal);
    }
    }
     } 


	// _api_v1_pending_txs_transaction->inner_hash
    if(_api_v1_pending_txs_transaction->inner_hash) { 
    if(cJSON_AddStringToObject(item, "inner_hash", _api_v1_pending_txs_transaction->inner_hash) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_pending_txs_transaction->inputs
    if(_api_v1_pending_txs_transaction->inputs) { 
	cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *inputsListEntry;
    list_ForEach(inputsListEntry, _api_v1_pending_txs_transaction->inputs) {
    if(cJSON_AddStringToObject(inputs, "", (char*)inputsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// _api_v1_pending_txs_transaction->sigs
    if(_api_v1_pending_txs_transaction->sigs) { 
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, _api_v1_pending_txs_transaction->sigs) {
    if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// _api_v1_pending_txs_transaction->length
    if(_api_v1_pending_txs_transaction->length) { 
    if(cJSON_AddNumberToObject(item, "length", _api_v1_pending_txs_transaction->length) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_pending_txs_transaction->txid
    if(_api_v1_pending_txs_transaction->txid) { 
    if(cJSON_AddStringToObject(item, "txid", _api_v1_pending_txs_transaction->txid) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_pending_txs_transaction->type
    if(_api_v1_pending_txs_transaction->type) { 
    if(cJSON_AddNumberToObject(item, "type", _api_v1_pending_txs_transaction->type) == NULL) {
    goto fail; //Numeric
    }
     } 


	// _api_v1_pending_txs_transaction->timestamp
    if(_api_v1_pending_txs_transaction->timestamp) { 
    if(cJSON_AddNumberToObject(item, "timestamp", _api_v1_pending_txs_transaction->timestamp) == NULL) {
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

_api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_parseFromJSON(cJSON *_api_v1_pending_txs_transactionJSON){

    _api_v1_pending_txs_transaction_t *_api_v1_pending_txs_transaction_local_var = NULL;

    // _api_v1_pending_txs_transaction->outputs
    cJSON *outputs = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "outputs");
    list_t *outputsList;
    if (outputs) { 
    cJSON *outputs_local_nonprimitive;
    if(!cJSON_IsArray(outputs)){
        goto end; //nonprimitive container
    }

    outputsList = list_create();

    cJSON_ArrayForEach(outputs_local_nonprimitive,outputs )
    {
        if(!cJSON_IsObject(outputs_local_nonprimitive)){
            goto end;
        }
        _api_v1_explorer_address_outputs_t *outputsItem = _api_v1_explorer_address_outputs_parseFromJSON(outputs_local_nonprimitive);

        list_addElement(outputsList, outputsItem);
    }
    }

    // _api_v1_pending_txs_transaction->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "inner_hash");
    if (inner_hash) { 
    if(!cJSON_IsString(inner_hash))
    {
    goto end; //String
    }
    }

    // _api_v1_pending_txs_transaction->inputs
    cJSON *inputs = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "inputs");
    list_t *inputsList;
    if (inputs) { 
    cJSON *inputs_local;
    if(!cJSON_IsArray(inputs)) {
        goto end;//primitive container
    }
    inputsList = list_create();

    cJSON_ArrayForEach(inputs_local, inputs)
    {
        if(!cJSON_IsString(inputs_local))
        {
            goto end;
        }
        list_addElement(inputsList , strdup(inputs_local->valuestring));
    }
    }

    // _api_v1_pending_txs_transaction->sigs
    cJSON *sigs = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "sigs");
    list_t *sigsList;
    if (sigs) { 
    cJSON *sigs_local;
    if(!cJSON_IsArray(sigs)) {
        goto end;//primitive container
    }
    sigsList = list_create();

    cJSON_ArrayForEach(sigs_local, sigs)
    {
        if(!cJSON_IsString(sigs_local))
        {
            goto end;
        }
        list_addElement(sigsList , strdup(sigs_local->valuestring));
    }
    }

    // _api_v1_pending_txs_transaction->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "length");
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_pending_txs_transaction->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "txid");
    if (txid) { 
    if(!cJSON_IsString(txid))
    {
    goto end; //String
    }
    }

    // _api_v1_pending_txs_transaction->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "type");
    if (type) { 
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }
    }

    // _api_v1_pending_txs_transaction->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(_api_v1_pending_txs_transactionJSON, "timestamp");
    if (timestamp) { 
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }
    }


    _api_v1_pending_txs_transaction_local_var = _api_v1_pending_txs_transaction_create (
        outputs ? outputsList : NULL,
        inner_hash ? strdup(inner_hash->valuestring) : NULL,
        inputs ? inputsList : NULL,
        sigs ? sigsList : NULL,
        length ? length->valuedouble : 0,
        txid ? strdup(txid->valuestring) : NULL,
        type ? type->valuedouble : 0,
        timestamp ? timestamp->valuedouble : 0
        );

    return _api_v1_pending_txs_transaction_local_var;
end:
    return NULL;

}
