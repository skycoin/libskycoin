#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_key_data_key2.h"



multi_key_data_key2_t *multi_key_data_key2_create(
    char *key
    ) {
	multi_key_data_key2_t *multi_key_data_key2_local_var = malloc(sizeof(multi_key_data_key2_t));
    if (!multi_key_data_key2_local_var) {
        return NULL;
    }
	multi_key_data_key2_local_var->key = key;

	return multi_key_data_key2_local_var;
}


void multi_key_data_key2_free(multi_key_data_key2_t *multi_key_data_key2) {
    listEntry_t *listEntry;
    free(multi_key_data_key2->key);
	free(multi_key_data_key2);
}

cJSON *multi_key_data_key2_convertToJSON(multi_key_data_key2_t *multi_key_data_key2) {
	cJSON *item = cJSON_CreateObject();

	// multi_key_data_key2->key
    if(multi_key_data_key2->key) { 
    if(cJSON_AddStringToObject(item, "key", multi_key_data_key2->key) == NULL) {
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

multi_key_data_key2_t *multi_key_data_key2_parseFromJSON(cJSON *multi_key_data_key2JSON){

    multi_key_data_key2_t *multi_key_data_key2_local_var = NULL;

    // multi_key_data_key2->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(multi_key_data_key2JSON, "key");
    if (key) { 
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }
    }


    multi_key_data_key2_local_var = multi_key_data_key2_create (
        key ? strdup(key->valuestring) : NULL
        );

    return multi_key_data_key2_local_var;
end:
    return NULL;

}
