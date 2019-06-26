#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_1.h"



inline_response_200_1_t *inline_response_200_1_create(
    list_t *blocks
    ) {
	inline_response_200_1_t *inline_response_200_1_local_var = malloc(sizeof(inline_response_200_1_t));
    if (!inline_response_200_1_local_var) {
        return NULL;
    }
	inline_response_200_1_local_var->blocks = blocks;

	return inline_response_200_1_local_var;
}


void inline_response_200_1_free(inline_response_200_1_t *inline_response_200_1) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200_1->blocks) {
		block_schema_free(listEntry->data);
	}
	list_free(inline_response_200_1->blocks);
	free(inline_response_200_1);
}

cJSON *inline_response_200_1_convertToJSON(inline_response_200_1_t *inline_response_200_1) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_1->blocks
    if(inline_response_200_1->blocks) { 
    cJSON *blocks = cJSON_AddArrayToObject(item, "blocks");
    if(blocks == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *blocksListEntry;
    if (inline_response_200_1->blocks) {
    list_ForEach(blocksListEntry, inline_response_200_1->blocks) {
    cJSON *itemLocal = block_schema_convertToJSON(blocksListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(blocks, itemLocal);
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

inline_response_200_1_t *inline_response_200_1_parseFromJSON(cJSON *inline_response_200_1JSON){

    inline_response_200_1_t *inline_response_200_1_local_var = NULL;

    // inline_response_200_1->blocks
    cJSON *blocks = cJSON_GetObjectItemCaseSensitive(inline_response_200_1JSON, "blocks");
    list_t *blocksList;
    if (blocks) { 
    cJSON *blocks_local_nonprimitive;
    if(!cJSON_IsArray(blocks)){
        goto end; //nonprimitive container
    }

    blocksList = list_create();

    cJSON_ArrayForEach(blocks_local_nonprimitive,blocks )
    {
        if(!cJSON_IsObject(blocks_local_nonprimitive)){
            goto end;
        }
        block_schema_t *blocksItem = block_schema_parseFromJSON(blocks_local_nonprimitive);

        list_addElement(blocksList, blocksItem);
    }
    }


    inline_response_200_1_local_var = inline_response_200_1_create (
        blocks ? blocksList : NULL
        );

    return inline_response_200_1_local_var;
end:
    return NULL;

}
