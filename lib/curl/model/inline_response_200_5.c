#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_5.h"



inline_response_200_5_t *inline_response_200_5_create(
    char *branch,
    char *commit,
    char *version
    ) {
	inline_response_200_5_t *inline_response_200_5_local_var = malloc(sizeof(inline_response_200_5_t));
    if (!inline_response_200_5_local_var) {
        return NULL;
    }
	inline_response_200_5_local_var->branch = branch;
	inline_response_200_5_local_var->commit = commit;
	inline_response_200_5_local_var->version = version;

	return inline_response_200_5_local_var;
}


void inline_response_200_5_free(inline_response_200_5_t *inline_response_200_5) {
    listEntry_t *listEntry;
    free(inline_response_200_5->branch);
    free(inline_response_200_5->commit);
    free(inline_response_200_5->version);
	free(inline_response_200_5);
}

cJSON *inline_response_200_5_convertToJSON(inline_response_200_5_t *inline_response_200_5) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_5->branch
    if(inline_response_200_5->branch) { 
    if(cJSON_AddStringToObject(item, "branch", inline_response_200_5->branch) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_5->commit
    if(inline_response_200_5->commit) { 
    if(cJSON_AddStringToObject(item, "commit", inline_response_200_5->commit) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_5->version
    if(inline_response_200_5->version) { 
    if(cJSON_AddStringToObject(item, "version", inline_response_200_5->version) == NULL) {
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

inline_response_200_5_t *inline_response_200_5_parseFromJSON(cJSON *inline_response_200_5JSON){

    inline_response_200_5_t *inline_response_200_5_local_var = NULL;

    // inline_response_200_5->branch
    cJSON *branch = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "branch");
    if (branch) { 
    if(!cJSON_IsString(branch))
    {
    goto end; //String
    }
    }

    // inline_response_200_5->commit
    cJSON *commit = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "commit");
    if (commit) { 
    if(!cJSON_IsString(commit))
    {
    goto end; //String
    }
    }

    // inline_response_200_5->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }


    inline_response_200_5_local_var = inline_response_200_5_create (
        branch ? strdup(branch->valuestring) : NULL,
        commit ? strdup(commit->valuestring) : NULL,
        version ? strdup(version->valuestring) : NULL
        );

    return inline_response_200_5_local_var;
end:
    return NULL;

}
