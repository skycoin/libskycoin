#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_txn.h"



transaction_txn_t *transaction_txn_create(
    char *inner_hash,
    list_t *inputs,
    int length,
    list_t *outputs,
    list_t *sigs,
    long timestamp,
    char *txid,
    int type
    ) {
	transaction_txn_t *transaction_txn_local_var = malloc(sizeof(transaction_txn_t));
    if (!transaction_txn_local_var) {
        return NULL;
    }
	transaction_txn_local_var->inner_hash = inner_hash;
	transaction_txn_local_var->inputs = inputs;
	transaction_txn_local_var->length = length;
	transaction_txn_local_var->outputs = outputs;
	transaction_txn_local_var->sigs = sigs;
	transaction_txn_local_var->timestamp = timestamp;
	transaction_txn_local_var->txid = txid;
	transaction_txn_local_var->type = type;

	return transaction_txn_local_var;
}


void transaction_txn_free(transaction_txn_t *transaction_txn) {
    listEntry_t *listEntry;
    free(transaction_txn->inner_hash);
	list_ForEach(listEntry, transaction_txn->inputs) {
		free(listEntry->data);
	}
	list_free(transaction_txn->inputs);
	list_ForEach(listEntry, transaction_txn->outputs) {
		object_free(listEntry->data);
	}
	list_free(transaction_txn->outputs);
	list_ForEach(listEntry, transaction_txn->sigs) {
		free(listEntry->data);
	}
	list_free(transaction_txn->sigs);
    free(transaction_txn->txid);
	free(transaction_txn);
}

cJSON *transaction_txn_convertToJSON(transaction_txn_t *transaction_txn) {
	cJSON *item = cJSON_CreateObject();

	// transaction_txn->inner_hash
    if(transaction_txn->inner_hash) { 
    if(cJSON_AddStringToObject(item, "inner_hash", transaction_txn->inner_hash) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_txn->inputs
    if(transaction_txn->inputs) { 
	cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *inputsListEntry;
    list_ForEach(inputsListEntry, transaction_txn->inputs) {
    if(cJSON_AddStringToObject(inputs, "", (char*)inputsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// transaction_txn->length
    if(transaction_txn->length) { 
    if(cJSON_AddNumberToObject(item, "length", transaction_txn->length) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_txn->outputs
    if(transaction_txn->outputs) { 
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
    if(outputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *outputsListEntry;
    if (transaction_txn->outputs) {
    list_ForEach(outputsListEntry, transaction_txn->outputs) {
    cJSON *itemLocal = object_convertToJSON(outputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(outputs, itemLocal);
    }
    }
     } 


	// transaction_txn->sigs
    if(transaction_txn->sigs) { 
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, transaction_txn->sigs) {
    if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// transaction_txn->timestamp
    if(transaction_txn->timestamp) { 
    if(cJSON_AddNumberToObject(item, "timestamp", transaction_txn->timestamp) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_txn->txid
    if(transaction_txn->txid) { 
    if(cJSON_AddStringToObject(item, "txid", transaction_txn->txid) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_txn->type
    if(transaction_txn->type) { 
    if(cJSON_AddNumberToObject(item, "type", transaction_txn->type) == NULL) {
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

transaction_txn_t *transaction_txn_parseFromJSON(cJSON *transaction_txnJSON){

    transaction_txn_t *transaction_txn_local_var = NULL;

    // transaction_txn->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "inner_hash");
    if (inner_hash) { 
    if(!cJSON_IsString(inner_hash))
    {
    goto end; //String
    }
    }

    // transaction_txn->inputs
    cJSON *inputs = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "inputs");
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

    // transaction_txn->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "length");
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // transaction_txn->outputs
    cJSON *outputs = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "outputs");
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
        object_t *outputsItem = object_parseFromJSON(outputs_local_nonprimitive);

        list_addElement(outputsList, outputsItem);
    }
    }

    // transaction_txn->sigs
    cJSON *sigs = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "sigs");
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

    // transaction_txn->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "timestamp");
    if (timestamp) { 
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }
    }

    // transaction_txn->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "txid");
    if (txid) { 
    if(!cJSON_IsString(txid))
    {
    goto end; //String
    }
    }

    // transaction_txn->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_txnJSON, "type");
    if (type) { 
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }
    }


    transaction_txn_local_var = transaction_txn_create (
        inner_hash ? strdup(inner_hash->valuestring) : NULL,
        inputs ? inputsList : NULL,
        length ? length->valuedouble : 0,
        outputs ? outputsList : NULL,
        sigs ? sigsList : NULL,
        timestamp ? timestamp->valuedouble : 0,
        txid ? strdup(txid->valuestring) : NULL,
        type ? type->valuedouble : 0
        );

    return transaction_txn_local_var;
end:
    return NULL;

}
