#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1pending_txsverbose_transaction.h"
#include "apiv1exploreraddress_outputs.h"
#include "apiv1pending_txsverbose_transaction_inputs.h"
#include "list.h"


apiv1pending_txsverbose_transaction_t *apiv1pending_txsverbose_transaction_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    int fee,
    list_t *sigs,
    int length,
    int type,
    char *hash
    ) {
	apiv1pending_txsverbose_transaction_t *apiv1pending_txsverbose_transaction = malloc(sizeof(apiv1pending_txsverbose_transaction_t));
	apiv1pending_txsverbose_transaction->outputs = outputs;
	apiv1pending_txsverbose_transaction->inner_hash = inner_hash;
	apiv1pending_txsverbose_transaction->inputs = inputs;
	apiv1pending_txsverbose_transaction->fee = fee;
	apiv1pending_txsverbose_transaction->sigs = sigs;
	apiv1pending_txsverbose_transaction->length = length;
	apiv1pending_txsverbose_transaction->type = type;
	apiv1pending_txsverbose_transaction->hash = hash;

	return apiv1pending_txsverbose_transaction;
}


void apiv1pending_txsverbose_transaction_free(apiv1pending_txsverbose_transaction_t *apiv1pending_txsverbose_transaction) {
    listEntry_t *listEntry;
		list_ForEach(listEntry, apiv1pending_txsverbose_transaction->outputs) {
		apiv1exploreraddress_outputs_free(listEntry->data);
	}
	list_free(apiv1pending_txsverbose_transaction->outputs);
    free(apiv1pending_txsverbose_transaction->inner_hash);
		list_ForEach(listEntry, apiv1pending_txsverbose_transaction->inputs) {
		apiv1pending_txsverbose_transaction_inputs_free(listEntry->data);
	}
	list_free(apiv1pending_txsverbose_transaction->inputs);
	list_ForEach(listEntry, apiv1pending_txsverbose_transaction->sigs) {
		free(listEntry->data);
	}
	list_free(apiv1pending_txsverbose_transaction->sigs);
    free(apiv1pending_txsverbose_transaction->hash);

	free(apiv1pending_txsverbose_transaction);
}

cJSON *apiv1pending_txsverbose_transaction_convertToJSON(apiv1pending_txsverbose_transaction_t *apiv1pending_txsverbose_transaction) {
	cJSON *item = cJSON_CreateObject();
	// apiv1pending_txsverbose_transaction->outputs
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
	if(outputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *outputsListEntry;
	list_ForEach(outputsListEntry, apiv1pending_txsverbose_transaction->outputs) {
		cJSON *item = apiv1exploreraddress_outputs_convertToJSON(outputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(outputs, item);
	}

	// apiv1pending_txsverbose_transaction->inner_hash
    if(cJSON_AddStringToObject(item, "inner_hash", apiv1pending_txsverbose_transaction->inner_hash) == NULL) {
    goto fail; //String
    }

	// apiv1pending_txsverbose_transaction->inputs
    cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *inputsListEntry;
	list_ForEach(inputsListEntry, apiv1pending_txsverbose_transaction->inputs) {
		cJSON *item = apiv1pending_txsverbose_transaction_inputs_convertToJSON(inputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(inputs, item);
	}

	// apiv1pending_txsverbose_transaction->fee
    if(cJSON_AddNumberToObject(item, "fee", apiv1pending_txsverbose_transaction->fee) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txsverbose_transaction->sigs
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, apiv1pending_txsverbose_transaction->sigs) {
        if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
        {
            goto fail;
        }
    }

	// apiv1pending_txsverbose_transaction->length
    if(cJSON_AddNumberToObject(item, "length", apiv1pending_txsverbose_transaction->length) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txsverbose_transaction->type
    if(cJSON_AddNumberToObject(item, "type", apiv1pending_txsverbose_transaction->type) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txsverbose_transaction->hash
    if(cJSON_AddStringToObject(item, "hash", apiv1pending_txsverbose_transaction->hash) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1pending_txsverbose_transaction_t *apiv1pending_txsverbose_transaction_parseFromJSON(char *jsonString){

    apiv1pending_txsverbose_transaction_t *apiv1pending_txsverbose_transaction = NULL;
    cJSON *apiv1pending_txsverbose_transactionJSON = cJSON_Parse(jsonString);
    if(apiv1pending_txsverbose_transactionJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1pending_txsverbose_transaction->outputs
    cJSON *outputs;
    cJSON *outputsJSON = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON,"outputs");
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

    // apiv1pending_txsverbose_transaction->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON, "inner_hash");
    if(!cJSON_IsString(inner_hash) || (inner_hash->valuestring == NULL)){
    goto end; //String
    }

    // apiv1pending_txsverbose_transaction->inputs
    cJSON *inputs;
    cJSON *inputsJSON = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON,"inputs");
    if(!cJSON_IsArray(inputsJSON)){
        goto end; //nonprimitive container
    }

    list_t *inputsList = list_create();

    cJSON_ArrayForEach(inputs,inputsJSON )
    {
        if(!cJSON_IsObject(inputs)){
            goto end;
        }
		char *JSONData = cJSON_Print(inputs);
        apiv1pending_txsverbose_transaction_inputs_t *inputsItem = apiv1pending_txsverbose_transaction_inputs_parseFromJSON(JSONData);

        list_addElement(inputsList, inputsItem);
        free(JSONData);
    }

    // apiv1pending_txsverbose_transaction->fee
    cJSON *fee = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON, "fee");
    if(!cJSON_IsNumber(fee))
    {
    goto end; //Numeric
    }

    // apiv1pending_txsverbose_transaction->sigs
    cJSON *sigs;
    cJSON *sigsJSON = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON, "sigs");
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

    // apiv1pending_txsverbose_transaction->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON, "length");
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }

    // apiv1pending_txsverbose_transaction->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON, "type");
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }

    // apiv1pending_txsverbose_transaction->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transactionJSON, "hash");
    if(!cJSON_IsString(hash) || (hash->valuestring == NULL)){
    goto end; //String
    }


    apiv1pending_txsverbose_transaction = apiv1pending_txsverbose_transaction_create (
        outputsList,
        strdup(inner_hash->valuestring),
        inputsList,
        fee->valuedouble,
        sigsList,
        length->valuedouble,
        type->valuedouble,
        strdup(hash->valuestring)
        );
 cJSON_Delete(apiv1pending_txsverbose_transactionJSON);
    return apiv1pending_txsverbose_transaction;
end:
    cJSON_Delete(apiv1pending_txsverbose_transactionJSON);
    return NULL;

}

