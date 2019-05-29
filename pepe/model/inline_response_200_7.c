#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_7.h"



inline_response_200_7_t *inline_response_200_7_create(
    list_t *transactions
    ) {
	inline_response_200_7_t *inline_response_200_7_local_var = malloc(sizeof(inline_response_200_7_t));
    if (!inline_response_200_7_local_var) {
        return NULL;
    }
	inline_response_200_7_local_var->transactions = transactions;

	return inline_response_200_7_local_var;
}


void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7) {
    listEntry_t *listEntry;
	list_ForEach(listEntry, inline_response_200_7->transactions) {
		transaction_encoded_free(listEntry->data);
	}
	list_free(inline_response_200_7->transactions);
	free(inline_response_200_7);
}

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_7->transactions
    if(inline_response_200_7->transactions) { 
    cJSON *transactions = cJSON_AddArrayToObject(item, "transactions");
    if(transactions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *transactionsListEntry;
    if (inline_response_200_7->transactions) {
    list_ForEach(transactionsListEntry, inline_response_200_7->transactions) {
    cJSON *itemLocal = transaction_encoded_convertToJSON(transactionsListEntry->data);
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

inline_response_200_7_t *inline_response_200_7_parseFromJSON(cJSON *inline_response_200_7JSON){

    inline_response_200_7_t *inline_response_200_7_local_var = NULL;

    // inline_response_200_7->transactions
    cJSON *transactions = cJSON_GetObjectItemCaseSensitive(inline_response_200_7JSON, "transactions");
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
        transaction_encoded_t *transactionsItem = transaction_encoded_parseFromJSON(transactions_local_nonprimitive);

        list_addElement(transactionsList, transactionsItem);
    }
    }


    inline_response_200_7_local_var = inline_response_200_7_create (
        transactions ? transactionsList : NULL
        );

    return inline_response_200_7_local_var;
end:
    return NULL;

}
