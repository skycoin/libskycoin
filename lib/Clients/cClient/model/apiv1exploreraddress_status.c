#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1exploreraddress_status.h"


apiv1exploreraddress_status_t *apiv1exploreraddress_status_create(
    bool unconfirmed,
    long block_seq,
    long label,
    bool confirmed
    ) {
	apiv1exploreraddress_status_t *apiv1exploreraddress_status = malloc(sizeof(apiv1exploreraddress_status_t));
	apiv1exploreraddress_status->unconfirmed = unconfirmed;
	apiv1exploreraddress_status->block_seq = block_seq;
	apiv1exploreraddress_status->label = label;
	apiv1exploreraddress_status->confirmed = confirmed;

	return apiv1exploreraddress_status;
}


void apiv1exploreraddress_status_free(apiv1exploreraddress_status_t *apiv1exploreraddress_status) {
    listEntry_t *listEntry;

	free(apiv1exploreraddress_status);
}

cJSON *apiv1exploreraddress_status_convertToJSON(apiv1exploreraddress_status_t *apiv1exploreraddress_status) {
	cJSON *item = cJSON_CreateObject();
	// apiv1exploreraddress_status->unconfirmed
    if(cJSON_AddBoolToObject(item, "unconfirmed", apiv1exploreraddress_status->unconfirmed) == NULL) {
    goto fail; //Numeric
    }

	// apiv1exploreraddress_status->block_seq
    if(cJSON_AddNumberToObject(item, "block_seq", apiv1exploreraddress_status->block_seq) == NULL) {
    goto fail; //Numeric
    }

	// apiv1exploreraddress_status->label
    if(cJSON_AddNumberToObject(item, "label", apiv1exploreraddress_status->label) == NULL) {
    goto fail; //Numeric
    }

	// apiv1exploreraddress_status->confirmed
    if(cJSON_AddBoolToObject(item, "confirmed", apiv1exploreraddress_status->confirmed) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1exploreraddress_status_t *apiv1exploreraddress_status_parseFromJSON(char *jsonString){

    apiv1exploreraddress_status_t *apiv1exploreraddress_status = NULL;
    cJSON *apiv1exploreraddress_statusJSON = cJSON_Parse(jsonString);
    if(apiv1exploreraddress_statusJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1exploreraddress_status->unconfirmed
    cJSON *unconfirmed = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_statusJSON, "unconfirmed");
    if(!cJSON_IsBool(unconfirmed))
    {
    goto end; //Numeric
    }

    // apiv1exploreraddress_status->block_seq
    cJSON *block_seq = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_statusJSON, "block_seq");
    if(!cJSON_IsNumber(block_seq))
    {
    goto end; //Numeric
    }

    // apiv1exploreraddress_status->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_statusJSON, "label");
    if(!cJSON_IsNumber(label))
    {
    goto end; //Numeric
    }

    // apiv1exploreraddress_status->confirmed
    cJSON *confirmed = cJSON_GetObjectItemCaseSensitive(apiv1exploreraddress_statusJSON, "confirmed");
    if(!cJSON_IsBool(confirmed))
    {
    goto end; //Numeric
    }


    apiv1exploreraddress_status = apiv1exploreraddress_status_create (
        unconfirmed->valueint,
        block_seq->valuedouble,
        label->valuedouble,
        confirmed->valueint
        );
 cJSON_Delete(apiv1exploreraddress_statusJSON);
    return apiv1exploreraddress_status;
end:
    cJSON_Delete(apiv1exploreraddress_statusJSON);
    return NULL;

}

