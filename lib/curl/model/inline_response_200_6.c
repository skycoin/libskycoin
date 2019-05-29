#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_6.h"



inline_response_200_6_t *inline_response_200_6_create(
    char *branch,
    char *commit,
    char *version
    ) {
	inline_response_200_6_t *inline_response_200_6_local_var = malloc(sizeof(inline_response_200_6_t));
    if (!inline_response_200_6_local_var) {
        return NULL;
    }
	inline_response_200_6_local_var->branch = branch;
	inline_response_200_6_local_var->commit = commit;
	inline_response_200_6_local_var->version = version;

	return inline_response_200_6_local_var;
}


void inline_response_200_6_free(inline_response_200_6_t *inline_response_200_6) {
    listEntry_t *listEntry;
    free(inline_response_200_6->branch);
    free(inline_response_200_6->commit);
    free(inline_response_200_6->version);
	free(inline_response_200_6);
}

cJSON *inline_response_200_6_convertToJSON(inline_response_200_6_t *inline_response_200_6) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_6->branch
    if(inline_response_200_6->branch) { 
    if(cJSON_AddStringToObject(item, "branch", inline_response_200_6->branch) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_6->commit
    if(inline_response_200_6->commit) { 
    if(cJSON_AddStringToObject(item, "commit", inline_response_200_6->commit) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_6->version
    if(inline_response_200_6->version) { 
    if(cJSON_AddStringToObject(item, "version", inline_response_200_6->version) == NULL) {
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

inline_response_200_6_t *inline_response_200_6_parseFromJSON(cJSON *inline_response_200_6JSON){

    inline_response_200_6_t *inline_response_200_6_local_var = NULL;

    // inline_response_200_6->branch
    cJSON *branch = cJSON_GetObjectItemCaseSensitive(inline_response_200_6JSON, "branch");
    if (branch) { 
    if(!cJSON_IsString(branch))
    {
    goto end; //String
    }
    }

    // inline_response_200_6->commit
    cJSON *commit = cJSON_GetObjectItemCaseSensitive(inline_response_200_6JSON, "commit");
    if (commit) { 
    if(!cJSON_IsString(commit))
    {
    goto end; //String
    }
    }

    // inline_response_200_6->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(inline_response_200_6JSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }


    inline_response_200_6_local_var = inline_response_200_6_create (
        branch ? strdup(branch->valuestring) : NULL,
        commit ? strdup(commit->valuestring) : NULL,
        version ? strdup(version->valuestring) : NULL
        );

    return inline_response_200_6_local_var;
end:
    return NULL;

}
