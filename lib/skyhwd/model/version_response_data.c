#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "version_response_data.h"



version_response_data_t *version_response_data_create(
    char *commit,
    char *version,
    char *branch
    ) {
	version_response_data_t *version_response_data_local_var = malloc(sizeof(version_response_data_t));
    if (!version_response_data_local_var) {
        return NULL;
    }
	version_response_data_local_var->commit = commit;
	version_response_data_local_var->version = version;
	version_response_data_local_var->branch = branch;

	return version_response_data_local_var;
}


void version_response_data_free(version_response_data_t *version_response_data) {
    listEntry_t *listEntry;
    free(version_response_data->commit);
    free(version_response_data->version);
    free(version_response_data->branch);
	free(version_response_data);
}

cJSON *version_response_data_convertToJSON(version_response_data_t *version_response_data) {
	cJSON *item = cJSON_CreateObject();

	// version_response_data->commit
    if(version_response_data->commit) { 
    if(cJSON_AddStringToObject(item, "commit", version_response_data->commit) == NULL) {
    goto fail; //String
    }
     } 


	// version_response_data->version
    if(version_response_data->version) { 
    if(cJSON_AddStringToObject(item, "version", version_response_data->version) == NULL) {
    goto fail; //String
    }
     } 


	// version_response_data->branch
    if(version_response_data->branch) { 
    if(cJSON_AddStringToObject(item, "branch", version_response_data->branch) == NULL) {
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

version_response_data_t *version_response_data_parseFromJSON(cJSON *version_response_dataJSON){

    version_response_data_t *version_response_data_local_var = NULL;

    // version_response_data->commit
    cJSON *commit = cJSON_GetObjectItemCaseSensitive(version_response_dataJSON, "commit");
    if (commit) { 
    if(!cJSON_IsString(commit))
    {
    goto end; //String
    }
    }

    // version_response_data->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(version_response_dataJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }

    // version_response_data->branch
    cJSON *branch = cJSON_GetObjectItemCaseSensitive(version_response_dataJSON, "branch");
    if (branch) { 
    if(!cJSON_IsString(branch))
    {
    goto end; //String
    }
    }


    version_response_data_local_var = version_response_data_create (
        commit ? strdup(commit->valuestring) : NULL,
        version ? strdup(version->valuestring) : NULL,
        branch ? strdup(branch->valuestring) : NULL
        );

    return version_response_data_local_var;
end:
    return NULL;

}
