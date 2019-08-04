#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apply_settings_request.h"



apply_settings_request_t *apply_settings_request_create(
    char *label,
    int use_passphrase,
    char *language
    ) {
	apply_settings_request_t *apply_settings_request_local_var = malloc(sizeof(apply_settings_request_t));
    if (!apply_settings_request_local_var) {
        return NULL;
    }
	apply_settings_request_local_var->label = label;
	apply_settings_request_local_var->use_passphrase = use_passphrase;
	apply_settings_request_local_var->language = language;

	return apply_settings_request_local_var;
}


void apply_settings_request_free(apply_settings_request_t *apply_settings_request) {
    listEntry_t *listEntry;
    free(apply_settings_request->label);
    free(apply_settings_request->language);
	free(apply_settings_request);
}

cJSON *apply_settings_request_convertToJSON(apply_settings_request_t *apply_settings_request) {
	cJSON *item = cJSON_CreateObject();

	// apply_settings_request->label
    if(apply_settings_request->label) { 
    if(cJSON_AddStringToObject(item, "label", apply_settings_request->label) == NULL) {
    goto fail; //String
    }
     } 


	// apply_settings_request->use_passphrase
    if (!apply_settings_request->use_passphrase) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "use_passphrase", apply_settings_request->use_passphrase) == NULL) {
    goto fail; //Bool
    }


	// apply_settings_request->language
    if(apply_settings_request->language) { 
    if(cJSON_AddStringToObject(item, "language", apply_settings_request->language) == NULL) {
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

apply_settings_request_t *apply_settings_request_parseFromJSON(cJSON *apply_settings_requestJSON){

    apply_settings_request_t *apply_settings_request_local_var = NULL;

    // apply_settings_request->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(apply_settings_requestJSON, "label");
    if (label) { 
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }
    }

    // apply_settings_request->use_passphrase
    cJSON *use_passphrase = cJSON_GetObjectItemCaseSensitive(apply_settings_requestJSON, "use_passphrase");
    if (!use_passphrase) {
        goto end;
    }

    
    if(!cJSON_IsBool(use_passphrase))
    {
    goto end; //Bool
    }

    // apply_settings_request->language
    cJSON *language = cJSON_GetObjectItemCaseSensitive(apply_settings_requestJSON, "language");
    if (language) { 
    if(!cJSON_IsString(language))
    {
    goto end; //String
    }
    }


    apply_settings_request_local_var = apply_settings_request_create (
        label ? strdup(label->valuestring) : NULL,
        use_passphrase->valueint,
        language ? strdup(language->valuestring) : NULL
        );

    return apply_settings_request_local_var;
end:
    return NULL;

}
