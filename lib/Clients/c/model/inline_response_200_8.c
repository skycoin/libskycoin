#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_8.h"
#include "inline_response_200_8_data.h"
#include "object.h"


inline_response_200_8_t *inline_response_200_8_create(
    inline_response_200_8_data_t *data,
    object_t *error
    ) {
	inline_response_200_8_t *inline_response_200_8 = malloc(sizeof(inline_response_200_8_t));
	inline_response_200_8->data = data;
	inline_response_200_8->error = error;

	return inline_response_200_8;
}


void inline_response_200_8_free(inline_response_200_8_t *inline_response_200_8) {
    listEntry_t *listEntry;
	inline_response_200_8_data_free(inline_response_200_8->data);
	_free(inline_response_200_8->error);

	free(inline_response_200_8);
}

cJSON *inline_response_200_8_convertToJSON(inline_response_200_8_t *inline_response_200_8) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_8->data
	cJSON *data = inline_response_200_8_data_convertToJSON(inline_response_200_8->data);
	if(data == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "data", data);
	if(item->child == NULL) {
		goto fail;
	}

	// inline_response_200_8->error
	cJSON *error = _convertToJSON(inline_response_200_8->error);
	if(error == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "error", error);
	if(item->child == NULL) {
		goto fail;
	}

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_8_t *inline_response_200_8_parseFromJSON(char *jsonString){

    inline_response_200_8_t *inline_response_200_8 = NULL;
    cJSON *inline_response_200_8JSON = cJSON_Parse(jsonString);
    if(inline_response_200_8JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_8->data
    inline_response_200_8_data_t *data;
    cJSON *dataJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_8JSON, "data");
    if(inline_response_200_8JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *dataJSONData = cJSON_Print(dataJSON);
    data = inline_response_200_8_data_parseFromJSON(dataJSONData);

    // inline_response_200_8->error
    _t *error;
    cJSON *errorJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_8JSON, "error");
    if(inline_response_200_8JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *errorJSONData = cJSON_Print(errorJSON);
    error = _parseFromJSON(errorJSONData);


    inline_response_200_8 = inline_response_200_8_create (
        data,
        error
        );
        free(dataJSONData);
        free(errorJSONData);
 cJSON_Delete(inline_response_200_8JSON);
    return inline_response_200_8;
end:
    cJSON_Delete(inline_response_200_8JSON);
    return NULL;

}

