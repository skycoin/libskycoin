#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200.h"



inline_response_200_t *inline_response_200_create(
    list_t *data
    ) {
	inline_response_200_t *inline_response_200_local_var = malloc(sizeof(inline_response_200_t));
    if (!inline_response_200_local_var) {
        return NULL;
    }
	inline_response_200_local_var->data = data;

	return inline_response_200_local_var;
}


void inline_response_200_free(inline_response_200_t *inline_response_200) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200->data) {
		free(listEntry->data);
	}
	list_free(inline_response_200->data);
	free(inline_response_200);
}

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200->data
    if(inline_response_200->data) { 
	cJSON *data = cJSON_AddArrayToObject(item, "data");
	if(data == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *dataListEntry;
    list_ForEach(dataListEntry, inline_response_200->data) {
    if(cJSON_AddNumberToObject(data, "", *(double *)dataListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_t *inline_response_200_parseFromJSON(cJSON *inline_response_200JSON){

    inline_response_200_t *inline_response_200_local_var = NULL;

    // inline_response_200->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "data");
    list_t *dataList;
    if (data) { 
    cJSON *data_local;
    if(!cJSON_IsArray(data)) {
        goto end;//primitive container
    }
    dataList = list_create();

    cJSON_ArrayForEach(data_local, data)
    {
        if(!cJSON_IsNumber(data_local))
        {
            goto end;
        }
        list_addElement(dataList , &data_local->valuedouble);
    }
    }


    inline_response_200_local_var = inline_response_200_create (
        data ? dataList : NULL
        );

    return inline_response_200_local_var;
end:
    return NULL;

}
