#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction.h"



transaction_t *transaction_create(
    transaction_status_t *status,
    transaction_txn_t *txn,
    long time
    ) {
	transaction_t *transaction_local_var = malloc(sizeof(transaction_t));
    if (!transaction_local_var) {
        return NULL;
    }
	transaction_local_var->status = status;
	transaction_local_var->txn = txn;
	transaction_local_var->time = time;

	return transaction_local_var;
}


void transaction_free(transaction_t *transaction) {
    listEntry_t *listEntry;
    transaction_status_free(transaction->status);
    transaction_txn_free(transaction->txn);
	free(transaction);
}

cJSON *transaction_convertToJSON(transaction_t *transaction) {
	cJSON *item = cJSON_CreateObject();

	// transaction->status
    if(transaction->status) { 
    cJSON *status_local_JSON = transaction_status_convertToJSON(transaction->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction->txn
    if(transaction->txn) { 
    cJSON *txn_local_JSON = transaction_txn_convertToJSON(transaction->txn);
    if(txn_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "txn", txn_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// transaction->time
    if(transaction->time) { 
    if(cJSON_AddNumberToObject(item, "time", transaction->time) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_t *transaction_parseFromJSON(cJSON *transactionJSON){

    transaction_t *transaction_local_var = NULL;

    // transaction->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(transactionJSON, "status");
    transaction_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = transaction_status_parseFromJSON(status); //nonprimitive
    }

    // transaction->txn
    cJSON *txn = cJSON_GetObjectItemCaseSensitive(transactionJSON, "txn");
    transaction_txn_t *txn_local_nonprim = NULL;
    if (txn) { 
    txn_local_nonprim = transaction_txn_parseFromJSON(txn); //nonprimitive
    }

    // transaction->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(transactionJSON, "time");
    if (time) { 
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }
    }


    transaction_local_var = transaction_create (
        status ? status_local_nonprim : NULL,
        txn ? txn_local_nonprim : NULL,
        time ? time->valuedouble : 0
        );

    return transaction_local_var;
end:
    return NULL;

}
