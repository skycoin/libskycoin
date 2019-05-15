#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generate_addresses_request.h"



generate_addresses_request_t *generate_addresses_request_create(
    int address_n,
    int start_index,
    int confirm_address
    ) {
	generate_addresses_request_t *generate_addresses_request_local_var = malloc(sizeof(generate_addresses_request_t));
    if (!generate_addresses_request_local_var) {
        return NULL;
    }
	generate_addresses_request_local_var->address_n = address_n;
	generate_addresses_request_local_var->start_index = start_index;
	generate_addresses_request_local_var->confirm_address = confirm_address;

	return generate_addresses_request_local_var;
}


void generate_addresses_request_free(generate_addresses_request_t *generate_addresses_request) {
    listEntry_t *listEntry;
	free(generate_addresses_request);
}

cJSON *generate_addresses_request_convertToJSON(generate_addresses_request_t *generate_addresses_request) {
	cJSON *item = cJSON_CreateObject();

	// generate_addresses_request->address_n
    if (!generate_addresses_request->address_n) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "address_n", generate_addresses_request->address_n) == NULL) {
    goto fail; //Numeric
    }


	// generate_addresses_request->start_index
    if(generate_addresses_request->start_index) { 
    if(cJSON_AddNumberToObject(item, "start_index", generate_addresses_request->start_index) == NULL) {
    goto fail; //Numeric
    }
     } 


	// generate_addresses_request->confirm_address
    if(generate_addresses_request->confirm_address) { 
    if(cJSON_AddBoolToObject(item, "confirm_address", generate_addresses_request->confirm_address) == NULL) {
    goto fail; //Bool
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

generate_addresses_request_t *generate_addresses_request_parseFromJSON(cJSON *generate_addresses_requestJSON){

    generate_addresses_request_t *generate_addresses_request_local_var = NULL;

    // generate_addresses_request->address_n
    cJSON *address_n = cJSON_GetObjectItemCaseSensitive(generate_addresses_requestJSON, "address_n");
    if (!address_n) {
        goto end;
    }

    
    if(!cJSON_IsNumber(address_n))
    {
    goto end; //Numeric
    }

    // generate_addresses_request->start_index
    cJSON *start_index = cJSON_GetObjectItemCaseSensitive(generate_addresses_requestJSON, "start_index");
    if (start_index) { 
    if(!cJSON_IsNumber(start_index))
    {
    goto end; //Numeric
    }
    }

    // generate_addresses_request->confirm_address
    cJSON *confirm_address = cJSON_GetObjectItemCaseSensitive(generate_addresses_requestJSON, "confirm_address");
    if (confirm_address) { 
    if(!cJSON_IsBool(confirm_address))
    {
    goto end; //Bool
    }
    }


    generate_addresses_request_local_var = generate_addresses_request_create (
        address_n->valuedouble,
        start_index ? start_index->valuedouble : 0,
        confirm_address ? confirm_address->valueint : 0
        );

    return generate_addresses_request_local_var;
end:
    return NULL;

}
