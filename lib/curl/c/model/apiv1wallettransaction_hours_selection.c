#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1wallettransaction_hours_selection.h"


apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection_create(
    char *mode,
    char *share_factor,
    char *type
    ) {
	apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection = malloc(sizeof(apiv1wallettransaction_hours_selection_t));
	apiv1wallettransaction_hours_selection->mode = mode;
	apiv1wallettransaction_hours_selection->share_factor = share_factor;
	apiv1wallettransaction_hours_selection->type = type;

	return apiv1wallettransaction_hours_selection;
}


void apiv1wallettransaction_hours_selection_free(apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection) {
    listEntry_t *listEntry;
    free(apiv1wallettransaction_hours_selection->mode);
    free(apiv1wallettransaction_hours_selection->share_factor);
    free(apiv1wallettransaction_hours_selection->type);

	free(apiv1wallettransaction_hours_selection);
}

cJSON *apiv1wallettransaction_hours_selection_convertToJSON(apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection) {
	cJSON *item = cJSON_CreateObject();
	// apiv1wallettransaction_hours_selection->mode
    if(cJSON_AddStringToObject(item, "mode", apiv1wallettransaction_hours_selection->mode) == NULL) {
    goto fail; //String
    }

	// apiv1wallettransaction_hours_selection->share_factor
    if(cJSON_AddStringToObject(item, "share_factor", apiv1wallettransaction_hours_selection->share_factor) == NULL) {
    goto fail; //String
    }

	// apiv1wallettransaction_hours_selection->type
    if(cJSON_AddStringToObject(item, "type", apiv1wallettransaction_hours_selection->type) == NULL) {
    goto fail; //String
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection_parseFromJSON(char *jsonString){

    apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection = NULL;
    cJSON *apiv1wallettransaction_hours_selectionJSON = cJSON_Parse(jsonString);
    if(apiv1wallettransaction_hours_selectionJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1wallettransaction_hours_selection->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_hours_selectionJSON, "mode");
    if(!cJSON_IsString(mode) || (mode->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallettransaction_hours_selection->share_factor
    cJSON *share_factor = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_hours_selectionJSON, "share_factor");
    if(!cJSON_IsString(share_factor) || (share_factor->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallettransaction_hours_selection->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apiv1wallettransaction_hours_selectionJSON, "type");
    if(!cJSON_IsString(type) || (type->valuestring == NULL)){
    goto end; //String
    }


    apiv1wallettransaction_hours_selection = apiv1wallettransaction_hours_selection_create (
        strdup(mode->valuestring),
        strdup(share_factor->valuestring),
        strdup(type->valuestring)
        );
 cJSON_Delete(apiv1wallettransaction_hours_selectionJSON);
    return apiv1wallettransaction_hours_selection;
end:
    cJSON_Delete(apiv1wallettransaction_hours_selectionJSON);
    return NULL;

}

