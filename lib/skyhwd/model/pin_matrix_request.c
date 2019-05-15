#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pin_matrix_request.h"



pin_matrix_request_t *pin_matrix_request_create(
    char *pin
    ) {
	pin_matrix_request_t *pin_matrix_request_local_var = malloc(sizeof(pin_matrix_request_t));
    if (!pin_matrix_request_local_var) {
        return NULL;
    }
	pin_matrix_request_local_var->pin = pin;

	return pin_matrix_request_local_var;
}


void pin_matrix_request_free(pin_matrix_request_t *pin_matrix_request) {
    listEntry_t *listEntry;
    free(pin_matrix_request->pin);
	free(pin_matrix_request);
}

cJSON *pin_matrix_request_convertToJSON(pin_matrix_request_t *pin_matrix_request) {
	cJSON *item = cJSON_CreateObject();

	// pin_matrix_request->pin
    if (!pin_matrix_request->pin) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "pin", pin_matrix_request->pin) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

pin_matrix_request_t *pin_matrix_request_parseFromJSON(cJSON *pin_matrix_requestJSON){

    pin_matrix_request_t *pin_matrix_request_local_var = NULL;

    // pin_matrix_request->pin
    cJSON *pin = cJSON_GetObjectItemCaseSensitive(pin_matrix_requestJSON, "pin");
    if (!pin) {
        goto end;
    }

    
    if(!cJSON_IsString(pin))
    {
    goto end; //String
    }


    pin_matrix_request_local_var = pin_matrix_request_create (
        strdup(pin->valuestring)
        );

    return pin_matrix_request_local_var;
end:
    return NULL;

}
