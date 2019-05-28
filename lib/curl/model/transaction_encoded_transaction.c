#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_encoded_transaction.h"



transaction_encoded_transaction_t *transaction_encoded_transaction_create(
    long length,
    long type,
    char *txid,
    char *inner_hash,
    list_t *sigs,
    list_t *inputs,
    list_t *outputs
    ) {
	transaction_encoded_transaction_t *transaction_encoded_transaction_local_var = malloc(sizeof(transaction_encoded_transaction_t));
    if (!transaction_encoded_transaction_local_var) {
        return NULL;
    }
	transaction_encoded_transaction_local_var->length = length;
	transaction_encoded_transaction_local_var->type = type;
	transaction_encoded_transaction_local_var->txid = txid;
	transaction_encoded_transaction_local_var->inner_hash = inner_hash;
	transaction_encoded_transaction_local_var->sigs = sigs;
	transaction_encoded_transaction_local_var->inputs = inputs;
	transaction_encoded_transaction_local_var->outputs = outputs;

	return transaction_encoded_transaction_local_var;
}


void transaction_encoded_transaction_free(transaction_encoded_transaction_t *transaction_encoded_transaction) {
    listEntry_t *listEntry;
    free(transaction_encoded_transaction->txid);
    free(transaction_encoded_transaction->inner_hash);
	list_ForEach(listEntry, transaction_encoded_transaction->sigs) {
		free(listEntry->data);
	}
	list_free(transaction_encoded_transaction->sigs);
	list_ForEach(listEntry, transaction_encoded_transaction->inputs) {
		free(listEntry->data);
	}
	list_free(transaction_encoded_transaction->inputs);
	list_ForEach(listEntry, transaction_encoded_transaction->outputs) {
		transaction_encoded_transaction_outputs_free(listEntry->data);
	}
	list_free(transaction_encoded_transaction->outputs);
	free(transaction_encoded_transaction);
}

cJSON *transaction_encoded_transaction_convertToJSON(transaction_encoded_transaction_t *transaction_encoded_transaction) {
	cJSON *item = cJSON_CreateObject();

	// transaction_encoded_transaction->length
    if(transaction_encoded_transaction->length) { 
    if(cJSON_AddNumberToObject(item, "length", transaction_encoded_transaction->length) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_encoded_transaction->type
    if(transaction_encoded_transaction->type) { 
    if(cJSON_AddNumberToObject(item, "type", transaction_encoded_transaction->type) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_encoded_transaction->txid
    if(transaction_encoded_transaction->txid) { 
    if(cJSON_AddStringToObject(item, "txid", transaction_encoded_transaction->txid) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded_transaction->inner_hash
    if(transaction_encoded_transaction->inner_hash) { 
    if(cJSON_AddStringToObject(item, "inner_hash", transaction_encoded_transaction->inner_hash) == NULL) {
    goto fail; //String
    }
     } 


	// transaction_encoded_transaction->sigs
    if(transaction_encoded_transaction->sigs) { 
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, transaction_encoded_transaction->sigs) {
    if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// transaction_encoded_transaction->inputs
    if(transaction_encoded_transaction->inputs) { 
	cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *inputsListEntry;
    list_ForEach(inputsListEntry, transaction_encoded_transaction->inputs) {
    if(cJSON_AddStringToObject(inputs, "", (char*)inputsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// transaction_encoded_transaction->outputs
    if(transaction_encoded_transaction->outputs) { 
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
    if(outputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *outputsListEntry;
    if (transaction_encoded_transaction->outputs) {
    list_ForEach(outputsListEntry, transaction_encoded_transaction->outputs) {
    cJSON *itemLocal = transaction_encoded_transaction_outputs_convertToJSON(outputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(outputs, itemLocal);
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_encoded_transaction_t *transaction_encoded_transaction_parseFromJSON(cJSON *transaction_encoded_transactionJSON){

    transaction_encoded_transaction_t *transaction_encoded_transaction_local_var = NULL;

    // transaction_encoded_transaction->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "length");
    if (length) { 
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }
    }

    // transaction_encoded_transaction->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "type");
    if (type) { 
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }
    }

    // transaction_encoded_transaction->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "txid");
    if (txid) { 
    if(!cJSON_IsString(txid))
    {
    goto end; //String
    }
    }

    // transaction_encoded_transaction->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "inner_hash");
    if (inner_hash) { 
    if(!cJSON_IsString(inner_hash))
    {
    goto end; //String
    }
    }

    // transaction_encoded_transaction->sigs
    cJSON *sigs = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "sigs");
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

    // transaction_encoded_transaction->inputs
    cJSON *inputs = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "inputs");
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

    // transaction_encoded_transaction->outputs
    cJSON *outputs = cJSON_GetObjectItemCaseSensitive(transaction_encoded_transactionJSON, "outputs");
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
        transaction_encoded_transaction_outputs_t *outputsItem = transaction_encoded_transaction_outputs_parseFromJSON(outputs_local_nonprimitive);

        list_addElement(outputsList, outputsItem);
    }
    }


    transaction_encoded_transaction_local_var = transaction_encoded_transaction_create (
        length ? length->valuedouble : 0,
        type ? type->valuedouble : 0,
        txid ? strdup(txid->valuestring) : NULL,
        inner_hash ? strdup(inner_hash->valuestring) : NULL,
        sigs ? sigsList : NULL,
        inputs ? inputsList : NULL,
        outputs ? outputsList : NULL
        );

    return transaction_encoded_transaction_local_var;
end:
    return NULL;

}
