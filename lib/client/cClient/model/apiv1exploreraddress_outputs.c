#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1exploreraddress_outputs.h"


apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs_create(
    long hours,
    char *dst,
    char *coins,
    char *uxid
    ) {
	apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs = malloc(sizeof(apiv1exploreraddress_outputs_t));
	apiv1exploreraddress_outputs->hours = hours;
	apiv1exploreraddress_outputs->dst = dst;
	apiv1exploreraddress_outputs->coins = coins;
	apiv1exploreraddress_outputs->uxid = uxid;

	return apiv1exploreraddress_outputs;
}


void apiv1exploreraddress_outputs_free(apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs) {
    listEntry_t *listEntry;
    free(apiv1exploreraddress_outputs->dst);
    free(apiv1exploreraddress_outputs->coins);
    free(apiv1exploreraddress_outputs->uxid);

	free(apiv1exploreraddress_outputs);
}

cJSON *apiv1exploreraddress_outputs_convertToJSON(apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs) {
	cJSON *item = cJSON_CreateObject();
	// apiv1exploreraddress_outputs->hours
    if(cJSON_AddNumberToObject(item, "hours", apiv1exploreraddress_outputs->hours) == NULL) {
    goto fail; //Numeric
    }

	// apiv1exploreraddress_outputs->dst
    if(cJSON_AddStringToObject(item, "dst", apiv1exploreraddress_outputs->dst) == NULL) {
    goto fail; //String
    }

	// apiv1exploreraddress_outputs->coins
    if(cJSON_AddStringToObject(item, "coins", apiv1exploreraddress_outputs->coins) == NULL) {
    goto fail; //String
    }

	// apiv1exploreraddress_outputs->uxid
    if(cJSON_AddStringToObject(item, "uxid", apiv1exploreraddress_outputs->uxid) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs_parseFromJSON(char *jsonString){

    apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs = NULL;
    cJSON *apiv1exploreraddress_outputsJSON = cJSON_Parse(jsonString);
    if(apiv1exploreraddress_outputsJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1exploreraddress_outputs->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_outputsJSON, "hours");
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }

    // apiv1exploreraddress_outputs->dst
    cJSON *dst = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_outputsJSON, "dst");
    if(!cJSON_IsString(dst) || (dst->valuestring == NULL)){
    goto end; //String
    }

    // apiv1exploreraddress_outputs->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_outputsJSON, "coins");
    if(!cJSON_IsString(coins) || (coins->valuestring == NULL)){
    goto end; //String
    }

    // apiv1exploreraddress_outputs->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_outputsJSON, "uxid");
    if(!cJSON_IsString(uxid) || (uxid->valuestring == NULL)){
    goto end; //String
    }


    apiv1exploreraddress_outputs = apiv1exploreraddress_outputs_create (
        hours->valuedouble,
        strdup(dst->valuestring),
        strdup(coins->valuestring),
        strdup(uxid->valuestring)
        );
 cJSON_Delete(apiv1exploreraddress_outputsJSON);
    return apiv1exploreraddress_outputs;
end:
    cJSON_Delete(apiv1exploreraddress_outputsJSON);
    return NULL;

}

