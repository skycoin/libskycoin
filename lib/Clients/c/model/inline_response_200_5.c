#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_5.h"
#include "apiv1transactions_txn.h"
#include "apiv1transactions_txn_status.h"


inline_response_200_5_t *inline_response_200_5_create(
    long time,
    apiv1transactions_txn_t *txn,
    apiv1transactions_txn_status_t *status
    ) {
	inline_response_200_5_t *inline_response_200_5 = malloc(sizeof(inline_response_200_5_t));
	inline_response_200_5->time = time;
	inline_response_200_5->txn = txn;
	inline_response_200_5->status = status;

	return inline_response_200_5;
}


void inline_response_200_5_free(inline_response_200_5_t *inline_response_200_5) {
    listEntry_t *listEntry;
	apiv1transactions_txn_free(inline_response_200_5->txn);
	apiv1transactions_txn_status_free(inline_response_200_5->status);

	free(inline_response_200_5);
}

cJSON *inline_response_200_5_convertToJSON(inline_response_200_5_t *inline_response_200_5) {
	cJSON *item = cJSON_CreateObject();
	// inline_response_200_5->time
    if(cJSON_AddNumberToObject(item, "time", inline_response_200_5->time) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_5->txn
	cJSON *txn = apiv1transactions_txn_convertToJSON(inline_response_200_5->txn);
	if(txn == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "txn", txn);
	if(item->child == NULL) {
		goto fail;
	}

	// inline_response_200_5->status
	cJSON *status = apiv1transactions_txn_status_convertToJSON(inline_response_200_5->status);
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

inline_response_200_5_t *inline_response_200_5_parseFromJSON(char *jsonString){

    inline_response_200_5_t *inline_response_200_5 = NULL;
    cJSON *inline_response_200_5JSON = cJSON_Parse(jsonString);
    if(inline_response_200_5JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_5->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "time");
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }

    // inline_response_200_5->txn
    apiv1transactions_txn_t *txn;
    cJSON *txnJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "txn");
    if(inline_response_200_5JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *txnJSONData = cJSON_Print(txnJSON);
    txn = apiv1transactions_txn_parseFromJSON(txnJSONData);

    // inline_response_200_5->status
    apiv1transactions_txn_status_t *status;
    cJSON *statusJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_5JSON, "status");
    if(inline_response_200_5JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *statusJSONData = cJSON_Print(statusJSON);
    status = apiv1transactions_txn_status_parseFromJSON(statusJSONData);


    inline_response_200_5 = inline_response_200_5_create (
        time->valuedouble,
        txn,
        status
        );
        free(txnJSONData);
        free(statusJSONData);
 cJSON_Delete(inline_response_200_5JSON);
    return inline_response_200_5;
end:
    cJSON_Delete(inline_response_200_5JSON);
    return NULL;

}

