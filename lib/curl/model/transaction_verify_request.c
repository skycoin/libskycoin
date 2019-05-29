#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transaction_verify_request.h"



transaction_verify_request_t *transaction_verify_request_create(
    int unsigned_,
    char *encoded_transaction
    ) {
	transaction_verify_request_t *transaction_verify_request_local_var = malloc(sizeof(transaction_verify_request_t));
    if (!transaction_verify_request_local_var) {
        return NULL;
    }
	transaction_verify_request_local_var->unsigned_ = unsigned_;
	transaction_verify_request_local_var->encoded_transaction = encoded_transaction;

	return transaction_verify_request_local_var;
}


void transaction_verify_request_free(transaction_verify_request_t *transaction_verify_request) {
    listEntry_t *listEntry;
    free(transaction_verify_request->encoded_transaction);
	free(transaction_verify_request);
}

cJSON *transaction_verify_request_convertToJSON(transaction_verify_request_t *transaction_verify_request) {
	cJSON *item = cJSON_CreateObject();

	// transaction_verify_request->unsigned
    if(transaction_verify_request->unsigned_) {
    if(cJSON_AddBoolToObject(item, "unsigned", transaction_verify_request->unsigned_) == NULL) {
    goto fail; //Bool
    }
     }


	// transaction_verify_request->encoded_transaction
    if(transaction_verify_request->encoded_transaction) {
    if(cJSON_AddStringToObject(item, "encoded_transaction", transaction_verify_request->encoded_transaction) == NULL) {
    goto fail; //String
    }
     }

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

transaction_verify_request_t *transaction_verify_request_parseFromJSON(cJSON *transaction_verify_requestJSON){

    transaction_verify_request_t *transaction_verify_request_local_var = NULL;

    // transaction_verify_request->unsigned
    cJSON *unsigned_ = cJSON_GetObjectItemCaseSensitive(transaction_verify_requestJSON, "unsigned");
    if (unsigned_) {
    if(!cJSON_IsBool(unsigned_))
    {
    goto end; //Bool
    }
    }

    // transaction_verify_request->encoded_transaction
    cJSON *encoded_transaction = cJSON_GetObjectItemCaseSensitive(transaction_verify_requestJSON, "encoded_transaction");
    if (encoded_transaction) {
    if(!cJSON_IsString(encoded_transaction))
    {
    goto end; //String
    }
    }


    transaction_verify_request_local_var = transaction_verify_request_create (
        unsigned_ ? unsigned_->valueint : 0,
        encoded_transaction ? strdup(encoded_transaction->valuestring) : NULL
        );

    return transaction_verify_request_local_var;
end:
    return NULL;

}
