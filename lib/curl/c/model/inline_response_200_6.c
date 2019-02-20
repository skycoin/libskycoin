#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_6.h"
#include "apiv1transactionsverbose_txn.h"
#include "apiv1transactionsverbose_txn_status.h"


inline_response_200_6_t *inline_response_200_6_create(
    long time,
    apiv1transactionsverbose_txn_t *txn,
    apiv1transactionsverbose_txn_status_t *status
    ) {
	inline_response_200_6_t *inline_response_200_6 = malloc(sizeof(inline_response_200_6_t));
	inline_response_200_6->time = time;
	inline_response_200_6->txn = txn;
	inline_response_200_6->status = status;

	return inline_response_200_6;
}


void inline_response_200_6_free(inline_response_200_6_t *inline_response_200_6) {
    listEntry_t *listEntry;
	apiv1transactionsverbose_txn_free(inline_response_200_6->txn);
	apiv1transactionsverbose_txn_status_free(inline_response_200_6->status);

	free(inline_response_200_6);
}

cJSON *inline_response_200_6_convertToJSON(inline_response_200_6_t *inline_response_200_6) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_6->time
    if(cJSON_AddNumberToObject(item, "time", inline_response_200_6->time) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_6->txn
	cJSON *txn = apiv1transactionsverbose_txn_convertToJSON(inline_response_200_6->txn);
	if(txn == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "txn", txn);
	if(item->child == NULL) {
		goto fail;
	}

	// inline_response_200_6->status
	cJSON *status = apiv1transactionsverbose_txn_status_convertToJSON(inline_response_200_6->status);
	if(status == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "status", status);
	if(item->child == NULL) {
		goto fail;
	}

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_6_t *inline_response_200_6_parseFromJSON(char *jsonString){

    inline_response_200_6_t *inline_response_200_6 = NULL;
    cJSON *inline_response_200_6JSON = cJSON_Parse(jsonString);
    if(inline_response_200_6JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_6->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(inline_response_200_6JSON, "time");
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }

    // inline_response_200_6->txn
    apiv1transactionsverbose_txn_t *txn;
    cJSON *txnJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_6JSON, "txn");
    if(inline_response_200_6JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *txnJSONData = cJSON_Print(txnJSON);
    txn = apiv1transactionsverbose_txn_parseFromJSON(txnJSONData);

    // inline_response_200_6->status
    apiv1transactionsverbose_txn_status_t *status;
    cJSON *statusJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_6JSON, "status");
    if(inline_response_200_6JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *statusJSONData = cJSON_Print(statusJSON);
    status = apiv1transactionsverbose_txn_status_parseFromJSON(statusJSONData);


    inline_response_200_6 = inline_response_200_6_create (
        time->valuedouble,
        txn,
        status
        );
        free(txnJSONData);
        free(statusJSONData);
 cJSON_Delete(inline_response_200_6JSON);
    return inline_response_200_6;
end:
    cJSON_Delete(inline_response_200_6JSON);
    return NULL;

}

