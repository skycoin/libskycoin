#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "csrf_response.h"



csrf_response_t *csrf_response_create(
    char *data
    ) {
	csrf_response_t *csrf_response_local_var = malloc(sizeof(csrf_response_t));
    if (!csrf_response_local_var) {
        return NULL;
    }
	csrf_response_local_var->data = data;

	return csrf_response_local_var;
}


void csrf_response_free(csrf_response_t *csrf_response) {
    listEntry_t *listEntry;
    free(csrf_response->data);
	free(csrf_response);
}

cJSON *csrf_response_convertToJSON(csrf_response_t *csrf_response) {
	cJSON *item = cJSON_CreateObject();

	// csrf_response->data
    if(csrf_response->data) { 
    if(cJSON_AddStringToObject(item, "data", csrf_response->data) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

csrf_response_t *csrf_response_parseFromJSON(cJSON *csrf_responseJSON){

    csrf_response_t *csrf_response_local_var = NULL;

    // csrf_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(csrf_responseJSON, "data");
    if (data) { 
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }
    }


    csrf_response_local_var = csrf_response_create (
        data ? strdup(data->valuestring) : NULL
        );

    return csrf_response_local_var;
end:
    return NULL;

}
