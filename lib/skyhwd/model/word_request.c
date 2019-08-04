#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "word_request.h"



word_request_t *word_request_create(
    char *word
    ) {
	word_request_t *word_request_local_var = malloc(sizeof(word_request_t));
    if (!word_request_local_var) {
        return NULL;
    }
	word_request_local_var->word = word;

	return word_request_local_var;
}


void word_request_free(word_request_t *word_request) {
    listEntry_t *listEntry;
    free(word_request->word);
	free(word_request);
}

cJSON *word_request_convertToJSON(word_request_t *word_request) {
	cJSON *item = cJSON_CreateObject();

	// word_request->word
    if (!word_request->word) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "word", word_request->word) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

word_request_t *word_request_parseFromJSON(cJSON *word_requestJSON){

    word_request_t *word_request_local_var = NULL;

    // word_request->word
    cJSON *word = cJSON_GetObjectItemCaseSensitive(word_requestJSON, "word");
    if (!word) {
        goto end;
    }

    
    if(!cJSON_IsString(word))
    {
    goto end; //String
    }


    word_request_local_var = word_request_create (
        strdup(word->valuestring)
        );

    return word_request_local_var;
end:
    return NULL;

}
