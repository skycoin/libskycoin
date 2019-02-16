#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1transactions_txn.h"
#include "apiv1exploreraddress_outputs.h"
#include "apiv1pending_txs_transaction_inputs.h"
#include "apiv1transactions_txn_status.h"
#include "list.h"


apiv1transactions_txn_t *apiv1transactions_txn_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    int fee,
    list_t *sigs,
    int length,
    int type,
    char *hash,
    apiv1transactions_txn_status_t *status,
    long timestamp
    ) {
	apiv1transactions_txn_t *apiv1transactions_txn = malloc(sizeof(apiv1transactions_txn_t));
	apiv1transactions_txn->outputs = outputs;
	apiv1transactions_txn->inner_hash = inner_hash;
	apiv1transactions_txn->inputs = inputs;
	apiv1transactions_txn->fee = fee;
	apiv1transactions_txn->sigs = sigs;
	apiv1transactions_txn->length = length;
	apiv1transactions_txn->type = type;
	apiv1transactions_txn->hash = hash;
	apiv1transactions_txn->status = status;
	apiv1transactions_txn->timestamp = timestamp;

	return apiv1transactions_txn;
}


void apiv1transactions_txn_free(apiv1transactions_txn_t *apiv1transactions_txn) {
    listEntry_t *listEntry;
		list_ForEach(listEntry, apiv1transactions_txn->outputs) {
		apiv1exploreraddress_outputs_free(listEntry->data);
	}
	list_free(apiv1transactions_txn->outputs);
    free(apiv1transactions_txn->inner_hash);
		list_ForEach(listEntry, apiv1transactions_txn->inputs) {
		apiv1pending_txs_transaction_inputs_free(listEntry->data);
	}
	list_free(apiv1transactions_txn->inputs);
	list_ForEach(listEntry, apiv1transactions_txn->sigs) {
		free(listEntry->data);
	}
	list_free(apiv1transactions_txn->sigs);
    free(apiv1transactions_txn->hash);
	apiv1transactions_txn_status_free(apiv1transactions_txn->status);

	free(apiv1transactions_txn);
}

cJSON *apiv1transactions_txn_convertToJSON(apiv1transactions_txn_t *apiv1transactions_txn) {
	cJSON *item = cJSON_CreateObject();
	// apiv1transactions_txn->outputs
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
	if(outputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *outputsListEntry;
	list_ForEach(outputsListEntry, apiv1transactions_txn->outputs) {
		cJSON *item = apiv1exploreraddress_outputs_convertToJSON(outputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(outputs, item);
	}

	// apiv1transactions_txn->inner_hash
    if(cJSON_AddStringToObject(item, "inner_hash", apiv1transactions_txn->inner_hash) == NULL) {
    goto fail; //String
    }

	// apiv1transactions_txn->inputs
    cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *inputsListEntry;
	list_ForEach(inputsListEntry, apiv1transactions_txn->inputs) {
		cJSON *item = apiv1pending_txs_transaction_inputs_convertToJSON(inputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(inputs, item);
	}

	// apiv1transactions_txn->fee
    if(cJSON_AddNumberToObject(item, "fee", apiv1transactions_txn->fee) == NULL) {
    goto fail; //Numeric
    }

	// apiv1transactions_txn->sigs
	cJSON *sigs = cJSON_AddArrayToObject(item, "sigs");
	if(sigs == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sigsListEntry;
    list_ForEach(sigsListEntry, apiv1transactions_txn->sigs) {
        if(cJSON_AddStringToObject(sigs, "", (char*)sigsListEntry->data) == NULL)
        {
            goto fail;
        }
    }

	// apiv1transactions_txn->length
    if(cJSON_AddNumberToObject(item, "length", apiv1transactions_txn->length) == NULL) {
    goto fail; //Numeric
    }

	// apiv1transactions_txn->type
    if(cJSON_AddNumberToObject(item, "type", apiv1transactions_txn->type) == NULL) {
    goto fail; //Numeric
    }

	// apiv1transactions_txn->hash
    if(cJSON_AddStringToObject(item, "hash", apiv1transactions_txn->hash) == NULL) {
    goto fail; //String
    }

	// apiv1transactions_txn->status
	cJSON *status = apiv1transactions_txn_status_convertToJSON(apiv1transactions_txn->status);
	if(status == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "status", status);
	if(item->child == NULL) {
		goto fail;
	}

	// apiv1transactions_txn->timestamp
    if(cJSON_AddNumberToObject(item, "timestamp", apiv1transactions_txn->timestamp) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1transactions_txn_t *apiv1transactions_txn_parseFromJSON(char *jsonString){

    apiv1transactions_txn_t *apiv1transactions_txn = NULL;
    cJSON *apiv1transactions_txnJSON = cJSON_Parse(jsonString);
    if(apiv1transactions_txnJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1transactions_txn->outputs
    cJSON *outputs;
    cJSON *outputsJSON = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON,"outputs");
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

    // apiv1transactions_txn->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "inner_hash");
    if(!cJSON_IsString(inner_hash) || (inner_hash->valuestring == NULL)){
    goto end; //String
    }

    // apiv1transactions_txn->inputs
    cJSON *inputs;
    cJSON *inputsJSON = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON,"inputs");
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
        apiv1pending_txs_transaction_inputs_t *inputsItem = apiv1pending_txs_transaction_inputs_parseFromJSON(JSONData);

        list_addElement(inputsList, inputsItem);
        free(JSONData);
    }

    // apiv1transactions_txn->fee
    cJSON *fee = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "fee");
    if(!cJSON_IsNumber(fee))
    {
    goto end; //Numeric
    }

    // apiv1transactions_txn->sigs
    cJSON *sigs;
    cJSON *sigsJSON = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "sigs");
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

    // apiv1transactions_txn->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "length");
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }

    // apiv1transactions_txn->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "type");
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }

    // apiv1transactions_txn->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "hash");
    if(!cJSON_IsString(hash) || (hash->valuestring == NULL)){
    goto end; //String
    }

    // apiv1transactions_txn->status
    apiv1transactions_txn_status_t *status;
    cJSON *statusJSON = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "status");
    if(apiv1transactions_txnJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *statusJSONData = cJSON_Print(statusJSON);
    status = apiv1transactions_txn_status_parseFromJSON(statusJSONData);

    // apiv1transactions_txn->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txnJSON, "timestamp");
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }


    apiv1transactions_txn = apiv1transactions_txn_create (
        outputsList,
        strdup(inner_hash->valuestring),
        inputsList,
        fee->valuedouble,
        sigsList,
        length->valuedouble,
        type->valuedouble,
        strdup(hash->valuestring),
        status,
        timestamp->valuedouble
        );
        free(statusJSONData);
 cJSON_Delete(apiv1transactions_txnJSON);
    return apiv1transactions_txn;
end:
    cJSON_Delete(apiv1transactions_txnJSON);
    return NULL;

}

