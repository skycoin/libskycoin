#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_sign_response.h"



transaction_sign_response_t *transaction_sign_response_create(
    list_t *data
    ) {
	transaction_sign_response_t *transaction_sign_response_local_var = malloc(sizeof(transaction_sign_response_t));
    if (!transaction_sign_response_local_var) {
        return NULL;
    }
	transaction_sign_response_local_var->data = data;

	return transaction_sign_response_local_var;
}


void transaction_sign_response_free(transaction_sign_response_t *transaction_sign_response) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, transaction_sign_response->data) {
		free(listEntry->data);
	}
	list_free(transaction_sign_response->data);
	free(transaction_sign_response);
}

cJSON *transaction_sign_response_convertToJSON(transaction_sign_response_t *transaction_sign_response) {
	cJSON *item = cJSON_CreateObject();

	// transaction_sign_response->data
    if(transaction_sign_response->data) { 
	cJSON *data = cJSON_AddArrayToObject(item, "data");
	if(data == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *dataListEntry;
    list_ForEach(dataListEntry, transaction_sign_response->data) {
    if(cJSON_AddStringToObject(data, "", (char*)dataListEntry->data) == NULL)
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

transaction_sign_response_t *transaction_sign_response_parseFromJSON(cJSON *transaction_sign_responseJSON){

    transaction_sign_response_t *transaction_sign_response_local_var = NULL;

    // transaction_sign_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(transaction_sign_responseJSON, "data");
    list_t *dataList;
    if (data) { 
    cJSON *data_local;
    if(!cJSON_IsArray(data)) {
        goto end;//primitive container
    }
    dataList = list_create();

    cJSON_ArrayForEach(data_local, data)
    {
        if(!cJSON_IsString(data_local))
        {
            goto end;
        }
        list_addElement(dataList , strdup(data_local->valuestring));
    }
    }


    transaction_sign_response_local_var = transaction_sign_response_create (
        data ? dataList : NULL
        );

    return transaction_sign_response_local_var;
end:
    return NULL;

}
