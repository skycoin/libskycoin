#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1pending_txsverbose_transaction_inputs.h"


apiv1pending_txsverbose_transaction_inputs_t *apiv1pending_txsverbose_transaction_inputs_create(
    long hours,
    long calculated_hours,
    char *dst,
    char *coins,
    char *uxid
    ) {
	apiv1pending_txsverbose_transaction_inputs_t *apiv1pending_txsverbose_transaction_inputs = malloc(sizeof(apiv1pending_txsverbose_transaction_inputs_t));
	apiv1pending_txsverbose_transaction_inputs->hours = hours;
	apiv1pending_txsverbose_transaction_inputs->calculated_hours = calculated_hours;
	apiv1pending_txsverbose_transaction_inputs->dst = dst;
	apiv1pending_txsverbose_transaction_inputs->coins = coins;
	apiv1pending_txsverbose_transaction_inputs->uxid = uxid;

	return apiv1pending_txsverbose_transaction_inputs;
}


void apiv1pending_txsverbose_transaction_inputs_free(apiv1pending_txsverbose_transaction_inputs_t *apiv1pending_txsverbose_transaction_inputs) {
    listEntry_t *listEntry;
    free(apiv1pending_txsverbose_transaction_inputs->dst);
    free(apiv1pending_txsverbose_transaction_inputs->coins);
    free(apiv1pending_txsverbose_transaction_inputs->uxid);

	free(apiv1pending_txsverbose_transaction_inputs);
}

cJSON *apiv1pending_txsverbose_transaction_inputs_convertToJSON(apiv1pending_txsverbose_transaction_inputs_t *apiv1pending_txsverbose_transaction_inputs) {
	cJSON *item = cJSON_CreateObject();
	// apiv1pending_txsverbose_transaction_inputs->hours
    if(cJSON_AddNumberToObject(item, "hours", apiv1pending_txsverbose_transaction_inputs->hours) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txsverbose_transaction_inputs->calculated_hours
    if(cJSON_AddNumberToObject(item, "calculated_hours", apiv1pending_txsverbose_transaction_inputs->calculated_hours) == NULL) {
    goto fail; //Numeric
    }

	// apiv1pending_txsverbose_transaction_inputs->dst
    if(cJSON_AddStringToObject(item, "dst", apiv1pending_txsverbose_transaction_inputs->dst) == NULL) {
    goto fail; //String
    }

	// apiv1pending_txsverbose_transaction_inputs->coins
    if(cJSON_AddStringToObject(item, "coins", apiv1pending_txsverbose_transaction_inputs->coins) == NULL) {
    goto fail; //String
    }

	// apiv1pending_txsverbose_transaction_inputs->uxid
    if(cJSON_AddStringToObject(item, "uxid", apiv1pending_txsverbose_transaction_inputs->uxid) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1pending_txsverbose_transaction_inputs_t *apiv1pending_txsverbose_transaction_inputs_parseFromJSON(char *jsonString){

    apiv1pending_txsverbose_transaction_inputs_t *apiv1pending_txsverbose_transaction_inputs = NULL;
    cJSON *apiv1pending_txsverbose_transaction_inputsJSON = cJSON_Parse(jsonString);
    if(apiv1pending_txsverbose_transaction_inputsJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1pending_txsverbose_transaction_inputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transaction_inputsJSON, "hours");
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }

    // apiv1pending_txsverbose_transaction_inputs->calculated_hours
    cJSON *calculated_hours = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transaction_inputsJSON, "calculated_hours");
    if(!cJSON_IsNumber(calculated_hours))
    {
    goto end; //Numeric
    }

    // apiv1pending_txsverbose_transaction_inputs->dst
    cJSON *dst = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transaction_inputsJSON, "dst");
    if(!cJSON_IsString(dst) || (dst->valuestring == NULL)){
    goto end; //String
    }

    // apiv1pending_txsverbose_transaction_inputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transaction_inputsJSON, "coins");
    if(!cJSON_IsString(coins) || (coins->valuestring == NULL)){
    goto end; //String
    }

    // apiv1pending_txsverbose_transaction_inputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(apiv1pending_txsverbose_transaction_inputsJSON, "uxid");
    if(!cJSON_IsString(uxid) || (uxid->valuestring == NULL)){
    goto end; //String
    }


    apiv1pending_txsverbose_transaction_inputs = apiv1pending_txsverbose_transaction_inputs_create (
        hours->valuedouble,
        calculated_hours->valuedouble,
        strdup(dst->valuestring),
        strdup(coins->valuestring),
        strdup(uxid->valuestring)
        );
 cJSON_Delete(apiv1pending_txsverbose_transaction_inputsJSON);
    return apiv1pending_txsverbose_transaction_inputs;
end:
    cJSON_Delete(apiv1pending_txsverbose_transaction_inputsJSON);
    return NULL;

}

