#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1pending_txs_transaction.h"
#include "apiv1exploreraddress_outputs.h"
#include "list.h"


apiv1pending_txs_transaction_t *apiv1pending_txs_transaction_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    list_t *sigs,
    int length,
    char *txid,
    int type,
    int timestamp
    ) {
	apiv1pending_txs_transaction_t *apiv1pending_txs_transaction = malloc(sizeof(apiv1pending_txs_transaction_t));
	apiv1pending_txs_transaction->outputs = outputs;
	apiv1pending_txs_transaction->inner_hash = inner_hash;
	apiv1pending_txs_transaction->inputs = inputs;
	apiv1pending_txs_transaction->sigs = sigs;
	apiv1pending_txs_transaction->length = length;
	apiv1pending_txs_transaction->txid = txid;
	apiv1pending_txs_transaction->type = type;
	apiv1pending_txs_transaction->timestamp = timestamp;

	return apiv1pending_txs_transaction;
}


void apiv1pending_txs_transaction_free(apiv1pending_txs_transaction_t *apiv1pending_txs_transaction) {
    listEntry_t *listEntry;
		list_ForEach(listEntry, apiv1pending_txs_transaction->outputs) {
		apiv1exploreraddress_outputs_free(listEntry->data);
	}
	list_free(apiv1pending_txs_transaction->outputs);
    free(apiv1pending_txs_transaction->inner_hash);
	list_ForEach(listEntry, apiv1pending_txs_transaction->inputs) {
		free(listEntry->data);
	}
	list_free(apiv1pending_txs_transaction->inputs);
	list_ForEach(listEntry, apiv1pending_txs_transaction->sigs) {
		free(listEntry->data);
	}
	list_free(apiv1pending_txs_transaction->sigs);
    free(apiv1pending_txs_transaction->txid);

	free(apiv1pending_txs_transaction);
}

cJSON *apiv1pending_txs_transaction_convertToJSON(apiv1pending_txs_transaction_t *apiv1pending_txs_transaction) {
	cJSON *item = cJSON_CreateObject();
	// apiv1pending_txs_transaction->outputs
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
	if(outputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *outputsListEntry;
	list_ForEach(outputsListEntry, apiv1pending_txs_transaction->outputs) {
		cJSON *item = apiv1exploreraddress_outputs_convertToJSON(outputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(outputs, item);
	}

	// apiv1pending_txs_transaction->inner_hash
    if(cJSON_AddStringToObject(item, "inner_hash", apiv1pending_txs_transaction->inner_hash) == NULL) {
    goto fail; //String
    }

	// apiv1pending_txs_transaction->inputs
	cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *inputsListEntry;
    list_ForEach(inputsListEntry, apiv1pending_txs_transaction->inputs) {
        if(cJSON_AddStringToObject(inputs, "", (char*)inputsListEntry->data) == NULL)
        {
            goto fail;
        }
    }

	// apiv1pending_txs_transaction->sigs
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, apiv1pending_txs_transaction->sigs) {
        if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
        {
            goto fail;
        }
    }

	// apiv1pending_txs_transaction->length
    if(cJSON_AddNumberToObject(item, "length", apiv1pending_txs_transaction->length) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txs_transaction->txid
    if(cJSON_AddStringToObject(item, "txid", apiv1pending_txs_transaction->txid) == NULL) {
    goto fail; //String
    }

	// apiv1pending_txs_transaction->type
    if(cJSON_AddNumberToObject(item, "type", apiv1pending_txs_transaction->type) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txs_transaction->timestamp
    if(cJSON_AddNumberToObject(item, "timestamp", apiv1pending_txs_transaction->timestamp) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1pending_txs_transaction_t *apiv1pending_txs_transaction_parseFromJSON(char *jsonString){

    apiv1pending_txs_transaction_t *apiv1pending_txs_transaction = NULL;
    cJSON *apiv1pending_txs_transactionJSON = cJSON_Parse(jsonString);
    if(apiv1pending_txs_transactionJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1pending_txs_transaction->outputs
    cJSON *outputs;
    cJSON *outputsJSON = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON,"outputs");
    if(!cJSON_IsArray(outputsJSON)){
        goto end; //nonprimitive container
    }

    list_t *outputsList = list_create();

    cJSON_ArrayForEach(outputs,outputsJSON )
    {
        if(!cJSON_IsObject(outputs)){
            goto end;
        }
		char *JSONData = cJSON_Print(outputs);
        apiv1exploreraddress_outputs_t *outputsItem = apiv1exploreraddress_outputs_parseFromJSON(JSONData);

        list_addElement(outputsList, outputsItem);
        free(JSONData);
    }

    // apiv1pending_txs_transaction->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "inner_hash");
    if(!cJSON_IsString(inner_hash) || (inner_hash->valuestring == NULL)){
    goto end; //String
    }

    // apiv1pending_txs_transaction->inputs
    cJSON *inputs;
    cJSON *inputsJSON = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "inputs");
    if(!cJSON_IsArray(inputsJSON)) {
        goto end;//primitive container
    }
    list_t *inputsList = list_create();

    cJSON_ArrayForEach(inputs, inputsJSON)
    {
        if(!cJSON_IsString(inputs))
        {
            goto end;
        }
        list_addElement(inputsList , strdup(inputs->valuestring));

    }

    // apiv1pending_txs_transaction->sigs
    cJSON *sigs;
    cJSON *sigsJSON = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "sigs");
    if(!cJSON_IsArray(sigsJSON)) {
        goto end;//primitive container
    }
    list_t *sigsList = list_create();

    cJSON_ArrayForEach(sigs, sigsJSON)
    {
        if(!cJSON_IsString(sigs))
        {
            goto end;
        }
        list_addElement(sigsList , strdup(sigs->valuestring));

    }

    // apiv1pending_txs_transaction->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "length");
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }

    // apiv1pending_txs_transaction->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "txid");
    if(!cJSON_IsString(txid) || (txid->valuestring == NULL)){
    goto end; //String
    }

    // apiv1pending_txs_transaction->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "type");
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }

    // apiv1pending_txs_transaction->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(apiv1pending_txs_transactionJSON, "timestamp");
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }


    apiv1pending_txs_transaction = apiv1pending_txs_transaction_create (
        outputsList,
        strdup(inner_hash->valuestring),
        inputsList,
        sigsList,
        length->valuedouble,
        strdup(txid->valuestring),
        type->valuedouble,
        timestamp->valuedouble
        );
 cJSON_Delete(apiv1pending_txs_transactionJSON);
    return apiv1pending_txs_transaction;
end:
    cJSON_Delete(apiv1pending_txs_transactionJSON);
    return NULL;

}

