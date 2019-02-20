#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1wallettransaction_to.h"


apiv1wallettransaction_to_t *apiv1wallettransaction_to_create(
    long hours,
    char *address,
    long coins
    ) {
	apiv1wallettransaction_to_t *apiv1wallettransaction_to = malloc(sizeof(apiv1wallettransaction_to_t));
	apiv1wallettransaction_to->hours = hours;
	apiv1wallettransaction_to->address = address;
	apiv1wallettransaction_to->coins = coins;

	return apiv1wallettransaction_to;
}


void apiv1wallettransaction_to_free(apiv1wallettransaction_to_t *apiv1wallettransaction_to) {
    listEntry_t *listEntry;
    free(apiv1wallettransaction_to->address);

	free(apiv1wallettransaction_to);
}

cJSON *apiv1wallettransaction_to_convertToJSON(apiv1wallettransaction_to_t *apiv1wallettransaction_to) {
	cJSON *item = cJSON_CreateObject();
	// apiv1wallettransaction_to->hours
    if(cJSON_AddNumberToObject(item, "hours", apiv1wallettransaction_to->hours) == NULL) {
    goto fail; //Numeric
    }

	// apiv1wallettransaction_to->address
    if(cJSON_AddStringToObject(item, "address", apiv1wallettransaction_to->address) == NULL) {
    goto fail; //String
    }

	// apiv1wallettransaction_to->coins
    if(cJSON_AddNumberToObject(item, "coins", apiv1wallettransaction_to->coins) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1wallettransaction_to_t *apiv1wallettransaction_to_parseFromJSON(char *jsonString){

    apiv1wallettransaction_to_t *apiv1wallettransaction_to = NULL;
    cJSON *apiv1wallettransaction_toJSON = cJSON_Parse(jsonString);
    if(apiv1wallettransaction_toJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1wallettransaction_to->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_toJSON, "hours");
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }

    // apiv1wallettransaction_to->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_toJSON, "address");
    if(!cJSON_IsString(address) || (address->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallettransaction_to->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_toJSON, "coins");
    if(!cJSON_IsNumber(coins))
    {
    goto end; //Numeric
    }


    apiv1wallettransaction_to = apiv1wallettransaction_to_create (
        hours->valuedouble,
        strdup(address->valuestring),
        coins->valuedouble
        );
 cJSON_Delete(apiv1wallettransaction_toJSON);
    return apiv1wallettransaction_to;
end:
    cJSON_Delete(apiv1wallettransaction_toJSON);
    return NULL;

}

