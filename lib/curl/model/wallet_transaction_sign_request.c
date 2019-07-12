#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wallet_transaction_sign_request.h"



wallet_transaction_sign_request_t *wallet_transaction_sign_request_create(
    char *wallet_id,
    char *password,
    char *encoded_transaction,
    list_t *sign_indexes
    ) {
	wallet_transaction_sign_request_t *wallet_transaction_sign_request_local_var = malloc(sizeof(wallet_transaction_sign_request_t));
    if (!wallet_transaction_sign_request_local_var) {
        return NULL;
    }
	wallet_transaction_sign_request_local_var->wallet_id = wallet_id;
	wallet_transaction_sign_request_local_var->password = password;
	wallet_transaction_sign_request_local_var->encoded_transaction = encoded_transaction;
	wallet_transaction_sign_request_local_var->sign_indexes = sign_indexes;

	return wallet_transaction_sign_request_local_var;
}


void wallet_transaction_sign_request_free(wallet_transaction_sign_request_t *wallet_transaction_sign_request) {
    listEntry_t *listEntry;
    free(wallet_transaction_sign_request->wallet_id);
    free(wallet_transaction_sign_request->password);
    free(wallet_transaction_sign_request->encoded_transaction);
	list_ForEach(listEntry, wallet_transaction_sign_request->sign_indexes) {
		free(listEntry->data);
	}
	list_free(wallet_transaction_sign_request->sign_indexes);
	free(wallet_transaction_sign_request);
}

cJSON *wallet_transaction_sign_request_convertToJSON(wallet_transaction_sign_request_t *wallet_transaction_sign_request) {
	cJSON *item = cJSON_CreateObject();

	// wallet_transaction_sign_request->wallet_id
    if(wallet_transaction_sign_request->wallet_id) { 
    if(cJSON_AddStringToObject(item, "wallet_id", wallet_transaction_sign_request->wallet_id) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_sign_request->password
    if(wallet_transaction_sign_request->password) { 
    if(cJSON_AddStringToObject(item, "password", wallet_transaction_sign_request->password) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_sign_request->encoded_transaction
    if(wallet_transaction_sign_request->encoded_transaction) { 
    if(cJSON_AddStringToObject(item, "encoded_transaction", wallet_transaction_sign_request->encoded_transaction) == NULL) {
    goto fail; //String
    }
     } 


	// wallet_transaction_sign_request->sign_indexes
    if(wallet_transaction_sign_request->sign_indexes) { 
	cJSON *sign_indexes = cJSON_AddArrayToObject(item, "sign_indexes");
	if(sign_indexes == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *sign_indexesListEntry;
    list_ForEach(sign_indexesListEntry, wallet_transaction_sign_request->sign_indexes) {
    if(cJSON_AddNumberToObject(sign_indexes, "", *(double *)sign_indexesListEntry->data) == NULL)
    {
        goto fail;
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

wallet_transaction_sign_request_t *wallet_transaction_sign_request_parseFromJSON(cJSON *wallet_transaction_sign_requestJSON){

    wallet_transaction_sign_request_t *wallet_transaction_sign_request_local_var = NULL;

    // wallet_transaction_sign_request->wallet_id
    cJSON *wallet_id = cJSON_GetObjectItemCaseSensitive(wallet_transaction_sign_requestJSON, "wallet_id");
    if (wallet_id) { 
    if(!cJSON_IsString(wallet_id))
    {
    goto end; //String
    }
    }

    // wallet_transaction_sign_request->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(wallet_transaction_sign_requestJSON, "password");
    if (password) { 
    if(!cJSON_IsString(password))
    {
    goto end; //String
    }
    }

    // wallet_transaction_sign_request->encoded_transaction
    cJSON *encoded_transaction = cJSON_GetObjectItemCaseSensitive(wallet_transaction_sign_requestJSON, "encoded_transaction");
    if (encoded_transaction) { 
    if(!cJSON_IsString(encoded_transaction))
    {
    goto end; //String
    }
    }

    // wallet_transaction_sign_request->sign_indexes
    cJSON *sign_indexes = cJSON_GetObjectItemCaseSensitive(wallet_transaction_sign_requestJSON, "sign_indexes");
    list_t *sign_indexesList;
    if (sign_indexes) { 
    cJSON *sign_indexes_local;
    if(!cJSON_IsArray(sign_indexes)) {
        goto end;//primitive container
    }
    sign_indexesList = list_create();

    cJSON_ArrayForEach(sign_indexes_local, sign_indexes)
    {
        if(!cJSON_IsNumber(sign_indexes_local))
        {
            goto end;
        }
        list_addElement(sign_indexesList , &sign_indexes_local->valuedouble);
    }
    }


    wallet_transaction_sign_request_local_var = wallet_transaction_sign_request_create (
        wallet_id ? strdup(wallet_id->valuestring) : NULL,
        password ? strdup(password->valuestring) : NULL,
        encoded_transaction ? strdup(encoded_transaction->valuestring) : NULL,
        sign_indexes ? sign_indexesList : NULL
        );

    return wallet_transaction_sign_request_local_var;
end:
    return NULL;

}
