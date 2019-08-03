#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_input.h"



transaction_input_t *transaction_input_create(
    int index,
    char *hash
    ) {
	transaction_input_t *transaction_input_local_var = malloc(sizeof(transaction_input_t));
    if (!transaction_input_local_var) {
        return NULL;
    }
	transaction_input_local_var->index = index;
	transaction_input_local_var->hash = hash;

	return transaction_input_local_var;
}


void transaction_input_free(transaction_input_t *transaction_input) {
    listEntry_t *listEntry;
    free(transaction_input->hash);
	free(transaction_input);
}

cJSON *transaction_input_convertToJSON(transaction_input_t *transaction_input) {
	cJSON *item = cJSON_CreateObject();

	// transaction_input->index
    if (!transaction_input->index) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "index", transaction_input->index) == NULL) {
    goto fail; //Numeric
    }


	// transaction_input->hash
    if (!transaction_input->hash) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "hash", transaction_input->hash) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_input_t *transaction_input_parseFromJSON(cJSON *transaction_inputJSON){

    transaction_input_t *transaction_input_local_var = NULL;

    // transaction_input->index
    cJSON *index = cJSON_GetObjectItemCaseSensitive(transaction_inputJSON, "index");
    if (!index) {
        goto end;
    }

    
    if(!cJSON_IsNumber(index))
    {
    goto end; //Numeric
    }

    // transaction_input->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(transaction_inputJSON, "hash");
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }


    transaction_input_local_var = transaction_input_create (
        index->valuedouble,
        strdup(hash->valuestring)
        );

    return transaction_input_local_var;
end:
    return NULL;

}
