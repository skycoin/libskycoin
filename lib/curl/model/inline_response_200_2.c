#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_2.h"



inline_response_200_2_t *inline_response_200_2_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    int fee,
    list_t *sigs,
    long length,
    char *txid,
    int type,
    _api_v1_explorer_address_status_t *status,
    int timestamp
    ) {
	inline_response_200_2_t *inline_response_200_2_local_var = malloc(sizeof(inline_response_200_2_t));
    if (!inline_response_200_2_local_var) {
        return NULL;
    }
	inline_response_200_2_local_var->outputs = outputs;
	inline_response_200_2_local_var->inner_hash = inner_hash;
	inline_response_200_2_local_var->inputs = inputs;
	inline_response_200_2_local_var->fee = fee;
	inline_response_200_2_local_var->sigs = sigs;
	inline_response_200_2_local_var->length = length;
	inline_response_200_2_local_var->txid = txid;
	inline_response_200_2_local_var->type = type;
	inline_response_200_2_local_var->status = status;
	inline_response_200_2_local_var->timestamp = timestamp;

	return inline_response_200_2_local_var;
}


void inline_response_200_2_free(inline_response_200_2_t *inline_response_200_2) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200_2->outputs) {
		_api_v1_explorer_address_outputs_free(listEntry->data);
	}
	list_free(inline_response_200_2->outputs);
    free(inline_response_200_2->inner_hash);
	list_ForEach(listEntry, inline_response_200_2->inputs) {
		_api_v1_explorer_address_inputs_free(listEntry->data);
	}
	list_free(inline_response_200_2->inputs);
	list_ForEach(listEntry, inline_response_200_2->sigs) {
		free(listEntry->data);
	}
	list_free(inline_response_200_2->sigs);
    free(inline_response_200_2->txid);
    _api_v1_explorer_address_status_free(inline_response_200_2->status);
	free(inline_response_200_2);
}

cJSON *inline_response_200_2_convertToJSON(inline_response_200_2_t *inline_response_200_2) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_2->outputs
    if(inline_response_200_2->outputs) { 
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
    if(outputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *outputsListEntry;
    if (inline_response_200_2->outputs) {
    list_ForEach(outputsListEntry, inline_response_200_2->outputs) {
    cJSON *itemLocal = _api_v1_explorer_address_outputs_convertToJSON(outputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(outputs, itemLocal);
    }
    }
     } 


	// inline_response_200_2->inner_hash
    if(inline_response_200_2->inner_hash) { 
    if(cJSON_AddStringToObject(item, "inner_hash", inline_response_200_2->inner_hash) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->inputs
    if(inline_response_200_2->inputs) { 
    cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
    if(inputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *inputsListEntry;
    if (inline_response_200_2->inputs) {
    list_ForEach(inputsListEntry, inline_response_200_2->inputs) {
    cJSON *itemLocal = _api_v1_explorer_address_inputs_convertToJSON(inputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(inputs, itemLocal);
    }
    }
     } 


	// inline_response_200_2->fee
    if(inline_response_200_2->fee) { 
    if(cJSON_AddNumberToObject(item, "fee", inline_response_200_2->fee) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_2->sigs
    if(inline_response_200_2->sigs) { 
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, inline_response_200_2->sigs) {
    if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// inline_response_200_2->length
    if(inline_response_200_2->length) { 
    if(cJSON_AddNumberToObject(item, "length", inline_response_200_2->length) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_2->txid
    if(inline_response_200_2->txid) { 
    if(cJSON_AddStringToObject(item, "txid", inline_response_200_2->txid) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->type
    if(inline_response_200_2->type) { 
    if(cJSON_AddNumberToObject(item, "type", inline_response_200_2->type) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_2->status
    if(inline_response_200_2->status) { 
    cJSON *status_local_JSON = _api_v1_explorer_address_status_convertToJSON(inline_response_200_2->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// inline_response_200_2->timestamp
    if(inline_response_200_2->timestamp) { 
    if(cJSON_AddNumberToObject(item, "timestamp", inline_response_200_2->timestamp) == NULL) {
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

inline_response_200_2_t *inline_response_200_2_parseFromJSON(cJSON *inline_response_200_2JSON){

    inline_response_200_2_t *inline_response_200_2_local_var = NULL;

    // inline_response_200_2->outputs
    cJSON *outputs = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "outputs");
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

    // inline_response_200_2->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "inner_hash");
    if (inner_hash) { 
    if(!cJSON_IsString(inner_hash))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->inputs
    cJSON *inputs = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "inputs");
    list_t *inputsList;
    if (inputs) { 
    cJSON *inputs_local_nonprimitive;
    if(!cJSON_IsArray(inputs)){
        goto end; //nonprimitive container
    }

    inputsList = list_create();

    cJSON_ArrayForEach(inputs_local_nonprimitive,inputs )
    {
        if(!cJSON_IsObject(inputs_local_nonprimitive)){
            goto end;
        }
        _api_v1_explorer_address_inputs_t *inputsItem = _api_v1_explorer_address_inputs_parseFromJSON(inputs_local_nonprimitive);

        list_addElement(inputsList, inputsItem);
    }
    }

    // inline_response_200_2->fee
    cJSON *fee = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "fee");
    if (fee) { 
    if(!cJSON_IsNumber(fee))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_2->sigs
    cJSON *sigs = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "sigs");
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

    // inline_response_200_2->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "length");
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_2->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "txid");
    if (txid) { 
    if(!cJSON_IsString(txid))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "type");
    if (type) { 
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_2->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "status");
    _api_v1_explorer_address_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = _api_v1_explorer_address_status_parseFromJSON(status); //nonprimitive
    }

    // inline_response_200_2->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "timestamp");
    if (timestamp) { 
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }
    }


    inline_response_200_2_local_var = inline_response_200_2_create (
        outputs ? outputsList : NULL,
        inner_hash ? strdup(inner_hash->valuestring) : NULL,
        inputs ? inputsList : NULL,
        fee ? fee->valuedouble : 0,
        sigs ? sigsList : NULL,
        length ? length->valuedouble : 0,
        txid ? strdup(txid->valuestring) : NULL,
        type ? type->valuedouble : 0,
        status ? status_local_nonprim : NULL,
        timestamp ? timestamp->valuedouble : 0
        );

    return inline_response_200_2_local_var;
end:
    return NULL;

}
