#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "generate_mnemonic_request.h"



generate_mnemonic_request_t *generate_mnemonic_request_create(
    int word_count,
    int use_passphrase
    ) {
	generate_mnemonic_request_t *generate_mnemonic_request_local_var = malloc(sizeof(generate_mnemonic_request_t));
    if (!generate_mnemonic_request_local_var) {
        return NULL;
    }
	generate_mnemonic_request_local_var->word_count = word_count;
	generate_mnemonic_request_local_var->use_passphrase = use_passphrase;

	return generate_mnemonic_request_local_var;
}


void generate_mnemonic_request_free(generate_mnemonic_request_t *generate_mnemonic_request) {
    listEntry_t *listEntry;
	free(generate_mnemonic_request);
}

cJSON *generate_mnemonic_request_convertToJSON(generate_mnemonic_request_t *generate_mnemonic_request) {
	cJSON *item = cJSON_CreateObject();

	// generate_mnemonic_request->word_count
    if (!generate_mnemonic_request->word_count) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "word_count", generate_mnemonic_request->word_count) == NULL) {
    goto fail; //Numeric
    }


	// generate_mnemonic_request->use_passphrase
    if(generate_mnemonic_request->use_passphrase) { 
    if(cJSON_AddBoolToObject(item, "use_passphrase", generate_mnemonic_request->use_passphrase) == NULL) {
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

generate_mnemonic_request_t *generate_mnemonic_request_parseFromJSON(cJSON *generate_mnemonic_requestJSON){

    generate_mnemonic_request_t *generate_mnemonic_request_local_var = NULL;

    // generate_mnemonic_request->word_count
    cJSON *word_count = cJSON_GetObjectItemCaseSensitive(generate_mnemonic_requestJSON, "word_count");
    if (!word_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(word_count))
    {
    goto end; //Numeric
    }

    // generate_mnemonic_request->use_passphrase
    cJSON *use_passphrase = cJSON_GetObjectItemCaseSensitive(generate_mnemonic_requestJSON, "use_passphrase");
    if (use_passphrase) { 
    if(!cJSON_IsBool(use_passphrase))
    {
    goto end; //Bool
    }
    }


    generate_mnemonic_request_local_var = generate_mnemonic_request_create (
        word_count->valuedouble,
        use_passphrase ? use_passphrase->valueint : 0
        );

    return generate_mnemonic_request_local_var;
end:
    return NULL;

}
