#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_4.h"



inline_response_200_4_t *inline_response_200_4_create(
    char *branch,
    char *commit,
    char *version
    ) {
	inline_response_200_4_t *inline_response_200_4_local_var = malloc(sizeof(inline_response_200_4_t));
    if (!inline_response_200_4_local_var) {
        return NULL;
    }
	inline_response_200_4_local_var->branch = branch;
	inline_response_200_4_local_var->commit = commit;
	inline_response_200_4_local_var->version = version;

	return inline_response_200_4_local_var;
}


void inline_response_200_4_free(inline_response_200_4_t *inline_response_200_4) {
    listEntry_t *listEntry;
    free(inline_response_200_4->branch);
    free(inline_response_200_4->commit);
    free(inline_response_200_4->version);
	free(inline_response_200_4);
}

cJSON *inline_response_200_4_convertToJSON(inline_response_200_4_t *inline_response_200_4) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_4->branch
    if(inline_response_200_4->branch) { 
    if(cJSON_AddStringToObject(item, "branch", inline_response_200_4->branch) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_4->commit
    if(inline_response_200_4->commit) { 
    if(cJSON_AddStringToObject(item, "commit", inline_response_200_4->commit) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_4->version
    if(inline_response_200_4->version) { 
    if(cJSON_AddStringToObject(item, "version", inline_response_200_4->version) == NULL) {
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

inline_response_200_4_t *inline_response_200_4_parseFromJSON(cJSON *inline_response_200_4JSON){

    inline_response_200_4_t *inline_response_200_4_local_var = NULL;

    // inline_response_200_4->branch
    cJSON *branch = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "branch");
    if (branch) { 
    if(!cJSON_IsString(branch))
    {
    goto end; //String
    }
    }

    // inline_response_200_4->commit
    cJSON *commit = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "commit");
    if (commit) { 
    if(!cJSON_IsString(commit))
    {
    goto end; //String
    }
    }

    // inline_response_200_4->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(inline_response_200_4JSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }


    inline_response_200_4_local_var = inline_response_200_4_create (
        branch ? strdup(branch->valuestring) : NULL,
        commit ? strdup(commit->valuestring) : NULL,
        version ? strdup(version->valuestring) : NULL
        );

    return inline_response_200_4_local_var;
end:
    return NULL;

}
