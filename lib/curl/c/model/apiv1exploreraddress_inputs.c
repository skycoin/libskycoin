#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1exploreraddress_inputs.h"


apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs_create(
    char *owner,
    long hours,
    long calculated_hours,
    char *coins,
    char *uxid
    ) {
	apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs = malloc(sizeof(apiv1exploreraddress_inputs_t));
	apiv1exploreraddress_inputs->owner = owner;
	apiv1exploreraddress_inputs->hours = hours;
	apiv1exploreraddress_inputs->calculated_hours = calculated_hours;
	apiv1exploreraddress_inputs->coins = coins;
	apiv1exploreraddress_inputs->uxid = uxid;

	return apiv1exploreraddress_inputs;
}


void apiv1exploreraddress_inputs_free(apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs) {
    listEntry_t *listEntry;
    free(apiv1exploreraddress_inputs->owner);
    free(apiv1exploreraddress_inputs->coins);
    free(apiv1exploreraddress_inputs->uxid);

	free(apiv1exploreraddress_inputs);
}

cJSON *apiv1exploreraddress_inputs_convertToJSON(apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs) {
	cJSON *item = cJSON_CreateObject();
	// apiv1exploreraddress_inputs->owner
    if(cJSON_AddStringToObject(item, "owner", apiv1exploreraddress_inputs->owner) == NULL) {
    goto fail; //String
    }

	// apiv1exploreraddress_inputs->hours
    if(cJSON_AddNumberToObject(item, "hours", apiv1exploreraddress_inputs->hours) == NULL) {
    goto fail; //Numeric
    }

	// apiv1exploreraddress_inputs->calculated_hours
    if(cJSON_AddNumberToObject(item, "calculated_hours", apiv1exploreraddress_inputs->calculated_hours) == NULL) {
    goto fail; //Numeric
    }

	// apiv1exploreraddress_inputs->coins
    if(cJSON_AddStringToObject(item, "coins", apiv1exploreraddress_inputs->coins) == NULL) {
    goto fail; //String
    }

	// apiv1exploreraddress_inputs->uxid
    if(cJSON_AddStringToObject(item, "uxid", apiv1exploreraddress_inputs->uxid) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs_parseFromJSON(char *jsonString){

    apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs = NULL;
    cJSON *apiv1exploreraddress_inputsJSON = cJSON_Parse(jsonString);
    if(apiv1exploreraddress_inputsJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1exploreraddress_inputs->owner
    cJSON *owner = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_inputsJSON, "owner");
    if(!cJSON_IsString(owner) || (owner->valuestring == NULL)){
    goto end; //String
    }

    // apiv1exploreraddress_inputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_inputsJSON, "hours");
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }

    // apiv1exploreraddress_inputs->calculated_hours
    cJSON *calculated_hours = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_inputsJSON, "calculated_hours");
    if(!cJSON_IsNumber(calculated_hours))
    {
    goto end; //Numeric
    }

    // apiv1exploreraddress_inputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_inputsJSON, "coins");
    if(!cJSON_IsString(coins) || (coins->valuestring == NULL)){
    goto end; //String
    }

    // apiv1exploreraddress_inputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_inputsJSON, "uxid");
    if(!cJSON_IsString(uxid) || (uxid->valuestring == NULL)){
    goto end; //String
    }


    apiv1exploreraddress_inputs = apiv1exploreraddress_inputs_create (
        strdup(owner->valuestring),
        hours->valuedouble,
        calculated_hours->valuedouble,
        strdup(coins->valuestring),
        strdup(uxid->valuestring)
        );
 cJSON_Delete(apiv1exploreraddress_inputsJSON);
    return apiv1exploreraddress_inputs;
end:
    cJSON_Delete(apiv1exploreraddress_inputsJSON);
    return NULL;

}

