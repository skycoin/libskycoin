#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "address.h"



address_t *address_create(
    char *address
    ) {
	address_t *address_local_var = malloc(sizeof(address_t));
    if (!address_local_var) {
        return NULL;
    }
	address_local_var->address = address;

	return address_local_var;
}


void address_free(address_t *address) {
    listEntry_t *listEntry;
    free(address->address);
	free(address);
}

cJSON *address_convertToJSON(address_t *address) {
	cJSON *item = cJSON_CreateObject();

	// address->address
    if (!address->address) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "address", address->address) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

address_t *address_parseFromJSON(cJSON *addressJSON){

    address_t *address_local_var = NULL;

    // address->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(addressJSON, "address");
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }


    address_local_var = address_create (
        strdup(address->valuestring)
        );

    return address_local_var;
end:
    return NULL;

}
