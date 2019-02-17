#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1transactions_txn_status.h"


apiv1transactions_txn_status_t *apiv1transactions_txn_status_create(
    bool unconfirmed,
    long block_seq,
    bool confirmed,
    long height
    ) {
	apiv1transactions_txn_status_t *apiv1transactions_txn_status = malloc(sizeof(apiv1transactions_txn_status_t));
	apiv1transactions_txn_status->unconfirmed = unconfirmed;
	apiv1transactions_txn_status->block_seq = block_seq;
	apiv1transactions_txn_status->confirmed = confirmed;
	apiv1transactions_txn_status->height = height;

	return apiv1transactions_txn_status;
}


void apiv1transactions_txn_status_free(apiv1transactions_txn_status_t *apiv1transactions_txn_status) {
    listEntry_t *listEntry;

	free(apiv1transactions_txn_status);
}

cJSON *apiv1transactions_txn_status_convertToJSON(apiv1transactions_txn_status_t *apiv1transactions_txn_status) {
	cJSON *item = cJSON_CreateObject();
	// apiv1transactions_txn_status->unconfirmed
    if(cJSON_AddBoolToObject(item, "unconfirmed", apiv1transactions_txn_status->unconfirmed) == NULL) {
    goto fail; //Numeric
    }

	// apiv1transactions_txn_status->block_seq
    if(cJSON_AddNumberToObject(item, "block_seq", apiv1transactions_txn_status->block_seq) == NULL) {
    goto fail; //Numeric
    }

	// apiv1transactions_txn_status->confirmed
    if(cJSON_AddBoolToObject(item, "confirmed", apiv1transactions_txn_status->confirmed) == NULL) {
    goto fail; //Numeric
    }

	// apiv1transactions_txn_status->height
    if(cJSON_AddNumberToObject(item, "height", apiv1transactions_txn_status->height) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1transactions_txn_status_t *apiv1transactions_txn_status_parseFromJSON(char *jsonString){

    apiv1transactions_txn_status_t *apiv1transactions_txn_status = NULL;
    cJSON *apiv1transactions_txn_statusJSON = cJSON_Parse(jsonString);
    if(apiv1transactions_txn_statusJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1transactions_txn_status->unconfirmed
    cJSON *unconfirmed = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txn_statusJSON, "unconfirmed");
    if(!cJSON_IsBool(unconfirmed))
    {
    goto end; //Numeric
    }

    // apiv1transactions_txn_status->block_seq
    cJSON *block_seq = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txn_statusJSON, "block_seq");
    if(!cJSON_IsNumber(block_seq))
    {
    goto end; //Numeric
    }

    // apiv1transactions_txn_status->confirmed
    cJSON *confirmed = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txn_statusJSON, "confirmed");
    if(!cJSON_IsBool(confirmed))
    {
    goto end; //Numeric
    }

    // apiv1transactions_txn_status->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(apiv1transactions_txn_statusJSON, "height");
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }


    apiv1transactions_txn_status = apiv1transactions_txn_status_create (
        unconfirmed->valueint,
        block_seq->valuedouble,
        confirmed->valueint,
        height->valuedouble
        );
 cJSON_Delete(apiv1transactions_txn_statusJSON);
    return apiv1transactions_txn_status;
end:
    cJSON_Delete(apiv1transactions_txn_statusJSON);
    return NULL;

}

