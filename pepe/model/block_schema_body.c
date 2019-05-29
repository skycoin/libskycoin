#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "block_schema_body.h"



block_schema_body_t *block_schema_body_create(
    list_t *txns
    ) {
	block_schema_body_t *block_schema_body_local_var = malloc(sizeof(block_schema_body_t));
    if (!block_schema_body_local_var) {
        return NULL;
    }
	block_schema_body_local_var->txns = txns;

	return block_schema_body_local_var;
}


void block_schema_body_free(block_schema_body_t *block_schema_body) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, block_schema_body->txns) {
		object_free(listEntry->data);
	}
	list_free(block_schema_body->txns);
	free(block_schema_body);
}

cJSON *block_schema_body_convertToJSON(block_schema_body_t *block_schema_body) {
	cJSON *item = cJSON_CreateObject();

	// block_schema_body->txns
    if(block_schema_body->txns) { 
    cJSON *txns = cJSON_AddArrayToObject(item, "txns");
    if(txns == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *txnsListEntry;
    if (block_schema_body->txns) {
    list_ForEach(txnsListEntry, block_schema_body->txns) {
    cJSON *itemLocal = object_convertToJSON(txnsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(txns, itemLocal);
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

block_schema_body_t *block_schema_body_parseFromJSON(cJSON *block_schema_bodyJSON){

    block_schema_body_t *block_schema_body_local_var = NULL;

    // block_schema_body->txns
    cJSON *txns = cJSON_GetObjectItemCaseSensitive(block_schema_bodyJSON, "txns");
    list_t *txnsList;
    if (txns) { 
    cJSON *txns_local_nonprimitive;
    if(!cJSON_IsArray(txns)){
        goto end; //nonprimitive container
    }

    txnsList = list_create();

    cJSON_ArrayForEach(txns_local_nonprimitive,txns )
    {
        if(!cJSON_IsObject(txns_local_nonprimitive)){
            goto end;
        }
        object_t *txnsItem = object_parseFromJSON(txns_local_nonprimitive);

        list_addElement(txnsList, txnsItem);
    }
    }


    block_schema_body_local_var = block_schema_body_create (
        txns ? txnsList : NULL
        );

    return block_schema_body_local_var;
end:
    return NULL;

}
