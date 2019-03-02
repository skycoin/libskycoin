#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_2.h"
#include "apiv1exploreraddress_inputs.h"
#include "apiv1exploreraddress_outputs.h"
#include "apiv1exploreraddress_status.h"
#include "list.h"


inline_response_200_2_t *inline_response_200_2_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    int fee,
    list_t *sigs,
    long length,
    char *txid,
    int type,
    apiv1exploreraddress_status_t *status,
    int timestamp
    ) {
	inline_response_200_2_t *inline_response_200_2 = malloc(sizeof(inline_response_200_2_t));
	inline_response_200_2->outputs = outputs;
	inline_response_200_2->inner_hash = inner_hash;
	inline_response_200_2->inputs = inputs;
	inline_response_200_2->fee = fee;
	inline_response_200_2->sigs = sigs;
	inline_response_200_2->length = length;
	inline_response_200_2->txid = txid;
	inline_response_200_2->type = type;
	inline_response_200_2->status = status;
	inline_response_200_2->timestamp = timestamp;

	return inline_response_200_2;
}


void inline_response_200_2_free(inline_response_200_2_t *inline_response_200_2) {
    listEntry_t *listEntry;
		list_ForEach(listEntry, inline_response_200_2->outputs) {
		apiv1exploreraddress_outputs_free(listEntry->data);
	}
	list_free(inline_response_200_2->outputs);
    free(inline_response_200_2->inner_hash);
		list_ForEach(listEntry, inline_response_200_2->inputs) {
		apiv1exploreraddress_inputs_free(listEntry->data);
	}
	list_free(inline_response_200_2->inputs);
	list_ForEach(listEntry, inline_response_200_2->sigs) {
		free(listEntry->data);
	}
	list_free(inline_response_200_2->sigs);
    free(inline_response_200_2->txid);
	apiv1exploreraddress_status_free(inline_response_200_2->status);

	free(inline_response_200_2);
}

cJSON *inline_response_200_2_convertToJSON(inline_response_200_2_t *inline_response_200_2) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_2->outputs
    cJSON *outputs = cJSON_AddArrayToObject(item, "outputs");
	if(outputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *outputsListEntry;
	list_ForEach(outputsListEntry, inline_response_200_2->outputs) {
		cJSON *item = apiv1exploreraddress_outputs_convertToJSON(outputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(outputs, item);
	}

	// inline_response_200_2->inner_hash
    if(cJSON_AddStringToObject(item, "inner_hash", inline_response_200_2->inner_hash) == NULL) {
    goto fail; //String
    }

	// inline_response_200_2->inputs
    cJSON *inputs = cJSON_AddArrayToObject(item, "inputs");
	if(inputs == NULL) {
		goto fail; //nonprimitive container
	}

	listEntry_t *inputsListEntry;
	list_ForEach(inputsListEntry, inline_response_200_2->inputs) {
		cJSON *item = apiv1exploreraddress_inputs_convertToJSON(inputsListEntry->data);
		if(item == NULL) {
			goto fail;
		}
		cJSON_AddItemToArray(inputs, item);
	}

	// inline_response_200_2->fee
    if(cJSON_AddNumberToObject(item, "fee", inline_response_200_2->fee) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_2->sigs
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

	// inline_response_200_2->length
    if(cJSON_AddNumberToObject(item, "length", inline_response_200_2->length) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_2->txid
    if(cJSON_AddStringToObject(item, "txid", inline_response_200_2->txid) == NULL) {
    goto fail; //String
    }

	// inline_response_200_2->type
    if(cJSON_AddNumberToObject(item, "type", inline_response_200_2->type) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_2->status
	cJSON *status = apiv1exploreraddress_status_convertToJSON(inline_response_200_2->status);
	if(status == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "status", status);
	if(item->child == NULL) {
		goto fail;
	}

	// inline_response_200_2->timestamp
    if(cJSON_AddNumberToObject(item, "timestamp", inline_response_200_2->timestamp) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_2_t *inline_response_200_2_parseFromJSON(char *jsonString){

    inline_response_200_2_t *inline_response_200_2 = NULL;
    cJSON *inline_response_200_2JSON = cJSON_Parse(jsonString);
    if(inline_response_200_2JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_2->outputs
    cJSON *outputs;
    cJSON *outputsJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON,"outputs");
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

    // inline_response_200_2->inner_hash
    cJSON *inner_hash = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "inner_hash");
    if(!cJSON_IsString(inner_hash) || (inner_hash->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_2->inputs
    cJSON *inputs;
    cJSON *inputsJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON,"inputs");
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
        apiv1exploreraddress_inputs_t *inputsItem = apiv1exploreraddress_inputs_parseFromJSON(JSONData);

        list_addElement(inputsList, inputsItem);
        free(JSONData);
    }

    // inline_response_200_2->fee
    cJSON *fee = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "fee");
    if(!cJSON_IsNumber(fee))
    {
    goto end; //Numeric
    }

    // inline_response_200_2->sigs
    cJSON *sigs;
    cJSON *sigsJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "sigs");
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

    // inline_response_200_2->length
    cJSON *length = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "length");
    if(!cJSON_IsNumber(length))
    {
    goto end; //Numeric
    }

    // inline_response_200_2->txid
    cJSON *txid = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "txid");
    if(!cJSON_IsString(txid) || (txid->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_2->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "type");
    if(!cJSON_IsNumber(type))
    {
    goto end; //Numeric
    }

    // inline_response_200_2->status
    apiv1exploreraddress_status_t *status;
    cJSON *statusJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "status");
    if(inline_response_200_2JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *statusJSONData = cJSON_Print(statusJSON);
    status = apiv1exploreraddress_status_parseFromJSON(statusJSONData);

    // inline_response_200_2->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "timestamp");
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }


    inline_response_200_2 = inline_response_200_2_create (
        outputsList,
        strdup(inner_hash->valuestring),
        inputsList,
        fee->valuedouble,
        sigsList,
        length->valuedouble,
        strdup(txid->valuestring),
        type->valuedouble,
        status,
        timestamp->valuedouble
        );
        free(statusJSONData);
 cJSON_Delete(inline_response_200_2JSON);
    return inline_response_200_2;
end:
    cJSON_Delete(inline_response_200_2JSON);
    return NULL;

}

