#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "http_success_response.h"



http_success_response_t *http_success_response_create(
    list_t *data
    ) {
	http_success_response_t *http_success_response_local_var = malloc(sizeof(http_success_response_t));
    if (!http_success_response_local_var) {
        return NULL;
    }
	http_success_response_local_var->data = data;

	return http_success_response_local_var;
}


void http_success_response_free(http_success_response_t *http_success_response) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, http_success_response->data) {
		free(listEntry->data);
	}
	list_free(http_success_response->data);
	free(http_success_response);
}

cJSON *http_success_response_convertToJSON(http_success_response_t *http_success_response) {
	cJSON *item = cJSON_CreateObject();

	// http_success_response->data
    if(http_success_response->data) { 
	cJSON *data = cJSON_AddArrayToObject(item, "data");
	if(data == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *dataListEntry;
    list_ForEach(dataListEntry, http_success_response->data) {
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

http_success_response_t *http_success_response_parseFromJSON(cJSON *http_success_responseJSON){

    http_success_response_t *http_success_response_local_var = NULL;

    // http_success_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(http_success_responseJSON, "data");
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


    http_success_response_local_var = http_success_response_create (
        data ? dataList : NULL
        );

    return http_success_response_local_var;
end:
    return NULL;

}
