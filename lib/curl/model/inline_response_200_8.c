#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_8.h"



inline_response_200_8_t *inline_response_200_8_create(
    list_t *transactions
    ) {
	inline_response_200_8_t *inline_response_200_8_local_var = malloc(sizeof(inline_response_200_8_t));
    if (!inline_response_200_8_local_var) {
        return NULL;
    }
	inline_response_200_8_local_var->transactions = transactions;

	return inline_response_200_8_local_var;
}


void inline_response_200_8_free(inline_response_200_8_t *inline_response_200_8) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200_8->transactions) {
		object_free(listEntry->data);
	}
	list_free(inline_response_200_8->transactions);
	free(inline_response_200_8);
}

cJSON *inline_response_200_8_convertToJSON(inline_response_200_8_t *inline_response_200_8) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_8->transactions
    if(inline_response_200_8->transactions) { 
    cJSON *transactions = cJSON_AddArrayToObject(item, "transactions");
    if(transactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transactionsListEntry;
    if (inline_response_200_8->transactions) {
    list_ForEach(transactionsListEntry, inline_response_200_8->transactions) {
    cJSON *itemLocal = object_convertToJSON(transactionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(transactions, itemLocal);
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

inline_response_200_8_t *inline_response_200_8_parseFromJSON(cJSON *inline_response_200_8JSON){

    inline_response_200_8_t *inline_response_200_8_local_var = NULL;

    // inline_response_200_8->transactions
    cJSON *transactions = cJSON_GetObjectItemCaseSensitive(inline_response_200_8JSON, "transactions");
    list_t *transactionsList;
    if (transactions) { 
    cJSON *transactions_local_nonprimitive;
    if(!cJSON_IsArray(transactions)){
        goto end; //nonprimitive container
    }

    transactionsList = list_create();

    cJSON_ArrayForEach(transactions_local_nonprimitive,transactions )
    {
        if(!cJSON_IsObject(transactions_local_nonprimitive)){
            goto end;
        }
        object_t *transactionsItem = object_parseFromJSON(transactions_local_nonprimitive);

        list_addElement(transactionsList, transactionsItem);
    }
    }


    inline_response_200_8_local_var = inline_response_200_8_create (
        transactions ? transactionsList : NULL
        );

    return inline_response_200_8_local_var;
end:
    return NULL;

}
