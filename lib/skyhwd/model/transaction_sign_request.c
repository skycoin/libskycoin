#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_sign_request.h"



transaction_sign_request_t *transaction_sign_request_create(
    list_t *transaction_inputs,
    list_t *transaction_outputs
    ) {
	transaction_sign_request_t *transaction_sign_request_local_var = malloc(sizeof(transaction_sign_request_t));
    if (!transaction_sign_request_local_var) {
        return NULL;
    }
	transaction_sign_request_local_var->transaction_inputs = transaction_inputs;
	transaction_sign_request_local_var->transaction_outputs = transaction_outputs;

	return transaction_sign_request_local_var;
}


void transaction_sign_request_free(transaction_sign_request_t *transaction_sign_request) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, transaction_sign_request->transaction_inputs) {
		transaction_input_free(listEntry->data);
	}
	list_free(transaction_sign_request->transaction_inputs);
	list_ForEach(listEntry, transaction_sign_request->transaction_outputs) {
		transaction_output_free(listEntry->data);
	}
	list_free(transaction_sign_request->transaction_outputs);
	free(transaction_sign_request);
}

cJSON *transaction_sign_request_convertToJSON(transaction_sign_request_t *transaction_sign_request) {
	cJSON *item = cJSON_CreateObject();

	// transaction_sign_request->transaction_inputs
    if (!transaction_sign_request->transaction_inputs) {
        goto fail;
    }
    
    cJSON *transaction_inputs = cJSON_AddArrayToObject(item, "transaction_inputs");
    if(transaction_inputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transaction_inputsListEntry;
    if (transaction_sign_request->transaction_inputs) {
    list_ForEach(transaction_inputsListEntry, transaction_sign_request->transaction_inputs) {
    cJSON *itemLocal = transaction_input_convertToJSON(transaction_inputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transaction_inputs, itemLocal);
    }
    }


	// transaction_sign_request->transaction_outputs
    if (!transaction_sign_request->transaction_outputs) {
        goto fail;
    }
    
    cJSON *transaction_outputs = cJSON_AddArrayToObject(item, "transaction_outputs");
    if(transaction_outputs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transaction_outputsListEntry;
    if (transaction_sign_request->transaction_outputs) {
    list_ForEach(transaction_outputsListEntry, transaction_sign_request->transaction_outputs) {
    cJSON *itemLocal = transaction_output_convertToJSON(transaction_outputsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transaction_outputs, itemLocal);
    }
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_sign_request_t *transaction_sign_request_parseFromJSON(cJSON *transaction_sign_requestJSON){

    transaction_sign_request_t *transaction_sign_request_local_var = NULL;

    // transaction_sign_request->transaction_inputs
    cJSON *transaction_inputs = cJSON_GetObjectItemCaseSensitive(transaction_sign_requestJSON, "transaction_inputs");
    if (!transaction_inputs) {
        goto end;
    }

    list_t *transaction_inputsList;
    
    cJSON *transaction_inputs_local_nonprimitive;
    if(!cJSON_IsArray(transaction_inputs)){
        goto end; //nonprimitive container
    }

    transaction_inputsList = list_create();

    cJSON_ArrayForEach(transaction_inputs_local_nonprimitive,transaction_inputs )
    {
        if(!cJSON_IsObject(transaction_inputs_local_nonprimitive)){
            goto end;
        }
        transaction_input_t *transaction_inputsItem = transaction_input_parseFromJSON(transaction_inputs_local_nonprimitive);

        list_addElement(transaction_inputsList, transaction_inputsItem);
    }

    // transaction_sign_request->transaction_outputs
    cJSON *transaction_outputs = cJSON_GetObjectItemCaseSensitive(transaction_sign_requestJSON, "transaction_outputs");
    if (!transaction_outputs) {
        goto end;
    }

    list_t *transaction_outputsList;
    
    cJSON *transaction_outputs_local_nonprimitive;
    if(!cJSON_IsArray(transaction_outputs)){
        goto end; //nonprimitive container
    }

    transaction_outputsList = list_create();

    cJSON_ArrayForEach(transaction_outputs_local_nonprimitive,transaction_outputs )
    {
        if(!cJSON_IsObject(transaction_outputs_local_nonprimitive)){
            goto end;
        }
        transaction_output_t *transaction_outputsItem = transaction_output_parseFromJSON(transaction_outputs_local_nonprimitive);

        list_addElement(transaction_outputsList, transaction_outputsItem);
    }


    transaction_sign_request_local_var = transaction_sign_request_create (
        transaction_inputsList,
        transaction_outputsList
        );

    return transaction_sign_request_local_var;
end:
    return NULL;

}
