#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_verbose_txn.h"



transaction_verbose_txn_t *transaction_verbose_txn_create(
    transaction_status_t *status,
    long fee,
    char *inner_hash,
    list_t *inputs,
    int length,
    list_t *outputs,
    list_t *sigs,
    long timestamp,
    char *txid,
    int type
    ) {
	transaction_verbose_txn_t *transaction_verbose_txn_local_var = malloc(sizeof(transaction_verbose_txn_t));
    if (!transaction_verbose_txn_local_var) {
        return NULL;
    }
	transaction_verbose_txn_local_var->status = status;
	transaction_verbose_txn_local_var->fee = fee;
	transaction_verbose_txn_local_var->inner_hash = inner_hash;
	transaction_verbose_txn_local_var->inputs = inputs;
	transaction_verbose_txn_local_var->length = length;
	transaction_verbose_txn_local_var->outputs = outputs;
	transaction_verbose_txn_local_var->sigs = sigs;
	transaction_verbose_txn_local_var->timestamp = timestamp;
	transaction_verbose_txn_local_var->txid = txid;
	transaction_verbose_txn_local_var->type = type;

	return transaction_verbose_txn_local_var;
}


void transaction_verbose_txn_free(transaction_verbose_txn_t *transaction_verbose_txn) {
    listEntry_t *listEntry;
    transaction_status_free(transaction_verbose_txn->status);
    free(transaction_verbose_txn->inner_hash);
	list_ForEach(listEntry, transaction_verbose_txn->inputs) {
		transaction_verbose_txn_inputs_free(listEntry->data);
	}
	list_free(transaction_verbose_txn->inputs);
	list_ForEach(listEntry, transaction_verbose_txn->outputs) {
		object_free(listEntry->data);
	}
	list_free(transaction_verbose_txn->outputs);
	list_ForEach(listEntry, transaction_verbose_txn->sigs) {
		free(listEntry->data);
	}
	list_free(transaction_verbose_txn->sigs);
    free(transaction_verbose_txn->txid);
	free(transaction_verbose_txn);
}

cJSON *transaction_verbose_txn_convertToJSON(transaction_verbose_txn_t *transaction_verbose_txn) {
	cJSON *item = cJSON_CreateObject();

	// transaction_verbose_txn->status
    if(transaction_verbose_txn->status) { 
    cJSON *status_local_JSON = transaction_status_convertToJSON(transaction_verbose_txn->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction_verbose_txn->fee
    if(transaction_verbose_txn->fee) { 
    if(cJSON_AddNumberToObject(item, "fee", transaction_verbose_txn->fee) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_verbose_txn->inner_hash
    if(transaction_verbose_txn->inner_hash) { 
    if(cJSON_AddStringToObject(item, "inner_hash", transaction_verbose_txn->inner_hash) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_verbose_txn->inputs
    if(transaction_verbose_txn->inputs) { 
    cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
    if(inputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *inputsListEntry;
    if (transaction_verbose_txn->inputs) {
    list_ForEach(inputsListEntry, transaction_verbose_txn->inputs) {
    cJSON *itemLocal = transaction_verbose_txn_inputs_convertToJSON(inputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(inputs, itemLocal);
    }
    }
     } 


	// transaction_verbose_txn->length
    if(transaction_verbose_txn->length) { 
    if(cJSON_AddNumberToObject(item, "length", transaction_verbose_txn->length) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_verbose_txn->outputs
    if(transaction_verbose_txn->outputs) { 
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
    if(outputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *outputsListEntry;
    if (transaction_verbose_txn->outputs) {
    list_ForEach(outputsListEntry, transaction_verbose_txn->outputs) {
    cJSON *itemLocal = object_convertToJSON(outputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(outputs, itemLocal);
    }
    }
     } 


	// transaction_verbose_txn->sigs
    if(transaction_verbose_txn->sigs) { 
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, transaction_verbose_txn->sigs) {
    if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// transaction_verbose_txn->timestamp
    if(transaction_verbose_txn->timestamp) { 
    if(cJSON_AddNumberToObject(item, "timestamp", transaction_verbose_txn->timestamp) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_verbose_txn->txid
    if(transaction_verbose_txn->txid) { 
    if(cJSON_AddStringToObject(item, "txid", transaction_verbose_txn->txid) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_verbose_txn->type
    if(transaction_verbose_txn->type) { 
    if(cJSON_AddNumberToObject(item, "type", transaction_verbose_txn->type) == NULL) {
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

transaction_verbose_txn_t *transaction_verbose_txn_parseFromJSON(cJSON *transaction_verbose_txnJSON){

    transaction_verbose_txn_t *transaction_verbose_txn_local_var = NULL;

    // transaction_verbose_txn->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "status");
    transaction_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = transaction_status_parseFromJSON(status); //nonprimitive
    }

    // transaction_verbose_txn->fee
    cJSON *fee = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "fee");
    if (fee) { 
    if(!cJSON_IsNumber(fee))
    {
    goto end; //Numeric
    }
    }

    // transaction_verbose_txn->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "inner_hash");
    if (inner_hash) { 
    if(!cJSON_IsString(inner_hash))
    {
    goto end; //String
    }
    }

    // transaction_verbose_txn->inputs
    cJSON *inputs = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "inputs");
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
        transaction_verbose_txn_inputs_t *inputsItem = transaction_verbose_txn_inputs_parseFromJSON(inputs_local_nonprimitive);

        list_addElement(inputsList, inputsItem);
    }
    }

    // transaction_verbose_txn->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "length");
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // transaction_verbose_txn->outputs
    cJSON *outputs = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "outputs");
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

    // transaction_verbose_txn->sigs
    cJSON *sigs = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "sigs");
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

    // transaction_verbose_txn->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "timestamp");
    if (timestamp) { 
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }
    }

    // transaction_verbose_txn->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "txid");
    if (txid) { 
    if(!cJSON_IsString(txid))
    {
    goto end; //String
    }
    }

    // transaction_verbose_txn->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_verbose_txnJSON, "type");
    if (type) { 
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }
    }


    transaction_verbose_txn_local_var = transaction_verbose_txn_create (
        status ? status_local_nonprim : NULL,
        fee ? fee->valuedouble : 0,
        inner_hash ? strdup(inner_hash->valuestring) : NULL,
        inputs ? inputsList : NULL,
        length ? length->valuedouble : 0,
        outputs ? outputsList : NULL,
        sigs ? sigsList : NULL,
        timestamp ? timestamp->valuedouble : 0,
        txid ? strdup(txid->valuestring) : NULL,
        type ? type->valuedouble : 0
        );

    return transaction_verbose_txn_local_var;
end:
    return NULL;

}
