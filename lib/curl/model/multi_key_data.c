#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_key_data.h"



multi_key_data_t *multi_key_data_create(
    char *key1,
    multi_key_data_key2_t *key2
    ) {
	multi_key_data_t *multi_key_data_local_var = malloc(sizeof(multi_key_data_t));
    if (!multi_key_data_local_var) {
        return NULL;
    }
	multi_key_data_local_var->key1 = key1;
	multi_key_data_local_var->key2 = key2;

	return multi_key_data_local_var;
}


void multi_key_data_free(multi_key_data_t *multi_key_data) {
    listEntry_t *listEntry;
    free(multi_key_data->key1);
    multi_key_data_key2_free(multi_key_data->key2);
	free(multi_key_data);
}

cJSON *multi_key_data_convertToJSON(multi_key_data_t *multi_key_data) {
	cJSON *item = cJSON_CreateObject();

	// multi_key_data->key1
    if(multi_key_data->key1) { 
    if(cJSON_AddStringToObject(item, "key1", multi_key_data->key1) == NULL) {
    goto fail; //String
    }
     } 


	// multi_key_data->key2
    if(multi_key_data->key2) { 
    cJSON *key2_local_JSON = multi_key_data_key2_convertToJSON(multi_key_data->key2);
    if(key2_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "key2", key2_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

multi_key_data_t *multi_key_data_parseFromJSON(cJSON *multi_key_dataJSON){

    multi_key_data_t *multi_key_data_local_var = NULL;

    // multi_key_data->key1
    cJSON *key1 = cJSON_GetObjectItemCaseSensitive(multi_key_dataJSON, "key1");
    if (key1) { 
    if(!cJSON_IsString(key1))
    {
    goto end; //String
    }
    }

    // multi_key_data->key2
    cJSON *key2 = cJSON_GetObjectItemCaseSensitive(multi_key_dataJSON, "key2");
    multi_key_data_key2_t *key2_local_nonprim = NULL;
    if (key2) { 
    key2_local_nonprim = multi_key_data_key2_parseFromJSON(key2); //nonprimitive
    }


    multi_key_data_local_var = multi_key_data_create (
        key1 ? strdup(key1->valuestring) : NULL,
        key2 ? key2_local_nonprim : NULL
        );

    return multi_key_data_local_var;
end:
    return NULL;

}
