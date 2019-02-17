#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_8_data.h"


inline_response_200_8_data_t *inline_response_200_8_data_create(
    long version
    ) {
	inline_response_200_8_data_t *inline_response_200_8_data = malloc(sizeof(inline_response_200_8_data_t));
	inline_response_200_8_data->version = version;

	return inline_response_200_8_data;
}


void inline_response_200_8_data_free(inline_response_200_8_data_t *inline_response_200_8_data) {
    listEntry_t *listEntry;

	free(inline_response_200_8_data);
}

cJSON *inline_response_200_8_data_convertToJSON(inline_response_200_8_data_t *inline_response_200_8_data) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_8_data->version
    if(cJSON_AddNumberToObject(item, "version", inline_response_200_8_data->version) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_8_data_t *inline_response_200_8_data_parseFromJSON(char *jsonString){

    inline_response_200_8_data_t *inline_response_200_8_data = NULL;
    cJSON *inline_response_200_8_dataJSON = cJSON_Parse(jsonString);
    if(inline_response_200_8_dataJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_8_data->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(inline_response_200_8_dataJSON, "version");
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }


    inline_response_200_8_data = inline_response_200_8_data_create (
        version->valuedouble
        );
 cJSON_Delete(inline_response_200_8_dataJSON);
    return inline_response_200_8_data;
end:
    cJSON_Delete(inline_response_200_8_dataJSON);
    return NULL;

}

