#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "multi_key.h"



multi_key_t *multi_key_create(
    multi_key_data_t *data
    ) {
	multi_key_t *multi_key_local_var = malloc(sizeof(multi_key_t));
    if (!multi_key_local_var) {
        return NULL;
    }
	multi_key_local_var->data = data;

	return multi_key_local_var;
}


void multi_key_free(multi_key_t *multi_key) {
    listEntry_t *listEntry;
    multi_key_data_free(multi_key->data);
	free(multi_key);
}

cJSON *multi_key_convertToJSON(multi_key_t *multi_key) {
	cJSON *item = cJSON_CreateObject();

	// multi_key->data
    if(multi_key->data) { 
    cJSON *data_local_JSON = multi_key_data_convertToJSON(multi_key->data);
    if(data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_local_JSON);
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

multi_key_t *multi_key_parseFromJSON(cJSON *multi_keyJSON){

    multi_key_t *multi_key_local_var = NULL;

    // multi_key->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(multi_keyJSON, "data");
    multi_key_data_t *data_local_nonprim = NULL;
    if (data) { 
    data_local_nonprim = multi_key_data_parseFromJSON(data); //nonprimitive
    }


    multi_key_local_var = multi_key_create (
        data ? data_local_nonprim : NULL
        );

    return multi_key_local_var;
end:
    return NULL;

}
