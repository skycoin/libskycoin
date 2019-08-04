#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "configure_pin_code_request.h"



configure_pin_code_request_t *configure_pin_code_request_create(
    int remove_pin
    ) {
	configure_pin_code_request_t *configure_pin_code_request_local_var = malloc(sizeof(configure_pin_code_request_t));
    if (!configure_pin_code_request_local_var) {
        return NULL;
    }
	configure_pin_code_request_local_var->remove_pin = remove_pin;

	return configure_pin_code_request_local_var;
}


void configure_pin_code_request_free(configure_pin_code_request_t *configure_pin_code_request) {
    listEntry_t *listEntry;
	free(configure_pin_code_request);
}

cJSON *configure_pin_code_request_convertToJSON(configure_pin_code_request_t *configure_pin_code_request) {
	cJSON *item = cJSON_CreateObject();

	// configure_pin_code_request->remove_pin
    if (!configure_pin_code_request->remove_pin) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "remove_pin", configure_pin_code_request->remove_pin) == NULL) {
    goto fail; //Bool
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

configure_pin_code_request_t *configure_pin_code_request_parseFromJSON(cJSON *configure_pin_code_requestJSON){

    configure_pin_code_request_t *configure_pin_code_request_local_var = NULL;

    // configure_pin_code_request->remove_pin
    cJSON *remove_pin = cJSON_GetObjectItemCaseSensitive(configure_pin_code_requestJSON, "remove_pin");
    if (!remove_pin) {
        goto end;
    }

    
    if(!cJSON_IsBool(remove_pin))
    {
    goto end; //Bool
    }


    configure_pin_code_request_local_var = configure_pin_code_request_create (
        remove_pin->valueint
        );

    return configure_pin_code_request_local_var;
end:
    return NULL;

}
