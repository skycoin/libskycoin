#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_7_data.h"


inline_response_200_7_data_t *inline_response_200_7_data_create(
    long version
    ) {
	inline_response_200_7_data_t *inline_response_200_7_data = malloc(sizeof(inline_response_200_7_data_t));
	inline_response_200_7_data->version = version;

	return inline_response_200_7_data;
}


void inline_response_200_7_data_free(inline_response_200_7_data_t *inline_response_200_7_data) {
    listEntry_t *listEntry;

	free(inline_response_200_7_data);
}

cJSON *inline_response_200_7_data_convertToJSON(inline_response_200_7_data_t *inline_response_200_7_data) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_7_data->version
    if(cJSON_AddNumberToObject(item, "version", inline_response_200_7_data->version) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_7_data_t *inline_response_200_7_data_parseFromJSON(char *jsonString){

    inline_response_200_7_data_t *inline_response_200_7_data = NULL;
    cJSON *inline_response_200_7_dataJSON = cJSON_Parse(jsonString);
    if(inline_response_200_7_dataJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_7_data->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(inline_response_200_7_dataJSON, "version");
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }


    inline_response_200_7_data = inline_response_200_7_data_create (
        version->valuedouble
        );
 cJSON_Delete(inline_response_200_7_dataJSON);
    return inline_response_200_7_data;
end:
    cJSON_Delete(inline_response_200_7_dataJSON);
    return NULL;

}

