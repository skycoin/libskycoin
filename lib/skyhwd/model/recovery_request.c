#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "recovery_request.h"



recovery_request_t *recovery_request_create(
    int word_count,
    int use_passphrase,
    int dry_run
    ) {
	recovery_request_t *recovery_request_local_var = malloc(sizeof(recovery_request_t));
    if (!recovery_request_local_var) {
        return NULL;
    }
	recovery_request_local_var->word_count = word_count;
	recovery_request_local_var->use_passphrase = use_passphrase;
	recovery_request_local_var->dry_run = dry_run;

	return recovery_request_local_var;
}


void recovery_request_free(recovery_request_t *recovery_request) {
    listEntry_t *listEntry;
	free(recovery_request);
}

cJSON *recovery_request_convertToJSON(recovery_request_t *recovery_request) {
	cJSON *item = cJSON_CreateObject();

	// recovery_request->word_count
    if (!recovery_request->word_count) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "word_count", recovery_request->word_count) == NULL) {
    goto fail; //Numeric
    }


	// recovery_request->use_passphrase
    if (!recovery_request->use_passphrase) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "use_passphrase", recovery_request->use_passphrase) == NULL) {
    goto fail; //Bool
    }


	// recovery_request->dry_run
    if(recovery_request->dry_run) { 
    if(cJSON_AddBoolToObject(item, "dry_run", recovery_request->dry_run) == NULL) {
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

recovery_request_t *recovery_request_parseFromJSON(cJSON *recovery_requestJSON){

    recovery_request_t *recovery_request_local_var = NULL;

    // recovery_request->word_count
    cJSON *word_count = cJSON_GetObjectItemCaseSensitive(recovery_requestJSON, "word_count");
    if (!word_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(word_count))
    {
    goto end; //Numeric
    }

    // recovery_request->use_passphrase
    cJSON *use_passphrase = cJSON_GetObjectItemCaseSensitive(recovery_requestJSON, "use_passphrase");
    if (!use_passphrase) {
        goto end;
    }

    
    if(!cJSON_IsBool(use_passphrase))
    {
    goto end; //Bool
    }

    // recovery_request->dry_run
    cJSON *dry_run = cJSON_GetObjectItemCaseSensitive(recovery_requestJSON, "dry_run");
    if (dry_run) { 
    if(!cJSON_IsBool(dry_run))
    {
    goto end; //Bool
    }
    }


    recovery_request_local_var = recovery_request_create (
        word_count->valuedouble,
        use_passphrase->valueint,
        dry_run ? dry_run->valueint : 0
        );

    return recovery_request_local_var;
end:
    return NULL;

}
