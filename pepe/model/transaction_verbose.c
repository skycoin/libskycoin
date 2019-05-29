#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_verbose.h"



transaction_verbose_t *transaction_verbose_create(
    long time,
    transaction_status_t *status,
    transaction_verbose_txn_t *txn
    ) {
	transaction_verbose_t *transaction_verbose_local_var = malloc(sizeof(transaction_verbose_t));
    if (!transaction_verbose_local_var) {
        return NULL;
    }
	transaction_verbose_local_var->time = time;
	transaction_verbose_local_var->status = status;
	transaction_verbose_local_var->txn = txn;

	return transaction_verbose_local_var;
}


void transaction_verbose_free(transaction_verbose_t *transaction_verbose) {
    listEntry_t *listEntry;
    transaction_status_free(transaction_verbose->status);
    transaction_verbose_txn_free(transaction_verbose->txn);
	free(transaction_verbose);
}

cJSON *transaction_verbose_convertToJSON(transaction_verbose_t *transaction_verbose) {
	cJSON *item = cJSON_CreateObject();

	// transaction_verbose->time
    if(transaction_verbose->time) { 
    if(cJSON_AddNumberToObject(item, "time", transaction_verbose->time) == NULL) {
    goto fail; //Numeric
    }
     } 


	// transaction_verbose->status
    if(transaction_verbose->status) { 
    cJSON *status_local_JSON = transaction_status_convertToJSON(transaction_verbose->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction_verbose->txn
    if(transaction_verbose->txn) { 
    cJSON *txn_local_JSON = transaction_verbose_txn_convertToJSON(transaction_verbose->txn);
    if(txn_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "txn", txn_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_verbose_t *transaction_verbose_parseFromJSON(cJSON *transaction_verboseJSON){

    transaction_verbose_t *transaction_verbose_local_var = NULL;

    // transaction_verbose->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(transaction_verboseJSON, "time");
    if (time) { 
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }
    }

    // transaction_verbose->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(transaction_verboseJSON, "status");
    transaction_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = transaction_status_parseFromJSON(status); //nonprimitive
    }

    // transaction_verbose->txn
    cJSON *txn = cJSON_GetObjectItemCaseSensitive(transaction_verboseJSON, "txn");
    transaction_verbose_txn_t *txn_local_nonprim = NULL;
    if (txn) { 
    txn_local_nonprim = transaction_verbose_txn_parseFromJSON(txn); //nonprimitive
    }


    transaction_verbose_local_var = transaction_verbose_create (
        time ? time->valuedouble : 0,
        status ? status_local_nonprim : NULL,
        txn ? txn_local_nonprim : NULL
        );

    return transaction_verbose_local_var;
end:
    return NULL;

}
