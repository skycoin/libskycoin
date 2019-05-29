#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "single_key.h"



single_key_t *single_key_create(
    char *data
    ) {
	single_key_t *single_key_local_var = malloc(sizeof(single_key_t));
    if (!single_key_local_var) {
        return NULL;
    }
	single_key_local_var->data = data;

	return single_key_local_var;
}


void single_key_free(single_key_t *single_key) {
    listEntry_t *listEntry;
    free(single_key->data);
	free(single_key);
}

cJSON *single_key_convertToJSON(single_key_t *single_key) {
	cJSON *item = cJSON_CreateObject();

	// single_key->data
    if(single_key->data) { 
    if(cJSON_AddStringToObject(item, "data", single_key->data) == NULL) {
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

single_key_t *single_key_parseFromJSON(cJSON *single_keyJSON){

    single_key_t *single_key_local_var = NULL;

    // single_key->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(single_keyJSON, "data");
    if (data) { 
    if(!cJSON_IsString(data))
    {
    goto end; //String
    }
    }


    single_key_local_var = single_key_create (
        data ? strdup(data->valuestring) : NULL
        );

    return single_key_local_var;
end:
    return NULL;

}
