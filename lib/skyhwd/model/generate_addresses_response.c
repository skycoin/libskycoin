#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generate_addresses_response.h"



generate_addresses_response_t *generate_addresses_response_create(
    list_t *data
    ) {
	generate_addresses_response_t *generate_addresses_response_local_var = malloc(sizeof(generate_addresses_response_t));
    if (!generate_addresses_response_local_var) {
        return NULL;
    }
	generate_addresses_response_local_var->data = data;

	return generate_addresses_response_local_var;
}


void generate_addresses_response_free(generate_addresses_response_t *generate_addresses_response) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, generate_addresses_response->data) {
		free(listEntry->data);
	}
	list_free(generate_addresses_response->data);
	free(generate_addresses_response);
}

cJSON *generate_addresses_response_convertToJSON(generate_addresses_response_t *generate_addresses_response) {
	cJSON *item = cJSON_CreateObject();

	// generate_addresses_response->data
    if(generate_addresses_response->data) { 
	cJSON *data = cJSON_AddArrayToObject(item, "data");
	if(data == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *dataListEntry;
    list_ForEach(dataListEntry, generate_addresses_response->data) {
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

generate_addresses_response_t *generate_addresses_response_parseFromJSON(cJSON *generate_addresses_responseJSON){

    generate_addresses_response_t *generate_addresses_response_local_var = NULL;

    // generate_addresses_response->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(generate_addresses_responseJSON, "data");
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


    generate_addresses_response_local_var = generate_addresses_response_create (
        data ? dataList : NULL
        );

    return generate_addresses_response_local_var;
end:
    return NULL;

}
