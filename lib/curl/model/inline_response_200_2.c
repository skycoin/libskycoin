#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_2.h"



inline_response_200_2_t *inline_response_200_2_create(
    char *current_coinhour_supply,
    char *current_supply,
    list_t *locked_distribution_addresses,
    char *max_supply,
    char *total_coinhour_supply,
    char *total_supply,
    list_t *unlocked_distribution_addresses
    ) {
	inline_response_200_2_t *inline_response_200_2_local_var = malloc(sizeof(inline_response_200_2_t));
    if (!inline_response_200_2_local_var) {
        return NULL;
    }
	inline_response_200_2_local_var->current_coinhour_supply = current_coinhour_supply;
	inline_response_200_2_local_var->current_supply = current_supply;
	inline_response_200_2_local_var->locked_distribution_addresses = locked_distribution_addresses;
	inline_response_200_2_local_var->max_supply = max_supply;
	inline_response_200_2_local_var->total_coinhour_supply = total_coinhour_supply;
	inline_response_200_2_local_var->total_supply = total_supply;
	inline_response_200_2_local_var->unlocked_distribution_addresses = unlocked_distribution_addresses;

	return inline_response_200_2_local_var;
}


void inline_response_200_2_free(inline_response_200_2_t *inline_response_200_2) {
    listEntry_t *listEntry;
    free(inline_response_200_2->current_coinhour_supply);
    free(inline_response_200_2->current_supply);
	list_ForEach(listEntry, inline_response_200_2->locked_distribution_addresses) {
		free(listEntry->data);
	}
	list_free(inline_response_200_2->locked_distribution_addresses);
    free(inline_response_200_2->max_supply);
    free(inline_response_200_2->total_coinhour_supply);
    free(inline_response_200_2->total_supply);
	list_ForEach(listEntry, inline_response_200_2->unlocked_distribution_addresses) {
		free(listEntry->data);
	}
	list_free(inline_response_200_2->unlocked_distribution_addresses);
	free(inline_response_200_2);
}

cJSON *inline_response_200_2_convertToJSON(inline_response_200_2_t *inline_response_200_2) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_2->current_coinhour_supply
    if(inline_response_200_2->current_coinhour_supply) { 
    if(cJSON_AddStringToObject(item, "current_coinhour_supply", inline_response_200_2->current_coinhour_supply) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->current_supply
    if(inline_response_200_2->current_supply) { 
    if(cJSON_AddStringToObject(item, "current_supply", inline_response_200_2->current_supply) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->locked_distribution_addresses
    if(inline_response_200_2->locked_distribution_addresses) { 
	cJSON *locked_distribution_addresses = cJSON_AddArrayToObject(item, "locked_distribution_addresses");
	if(locked_distribution_addresses == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *locked_distribution_addressesListEntry;
    list_ForEach(locked_distribution_addressesListEntry, inline_response_200_2->locked_distribution_addresses) {
    if(cJSON_AddStringToObject(locked_distribution_addresses, "", (char*)locked_distribution_addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 


	// inline_response_200_2->max_supply
    if(inline_response_200_2->max_supply) { 
    if(cJSON_AddStringToObject(item, "max_supply", inline_response_200_2->max_supply) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->total_coinhour_supply
    if(inline_response_200_2->total_coinhour_supply) { 
    if(cJSON_AddStringToObject(item, "total_coinhour_supply", inline_response_200_2->total_coinhour_supply) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->total_supply
    if(inline_response_200_2->total_supply) { 
    if(cJSON_AddStringToObject(item, "total_supply", inline_response_200_2->total_supply) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_2->unlocked_distribution_addresses
    if(inline_response_200_2->unlocked_distribution_addresses) { 
	cJSON *unlocked_distribution_addresses = cJSON_AddArrayToObject(item, "unlocked_distribution_addresses");
	if(unlocked_distribution_addresses == NULL) {
		goto fail; //primitive container
	}

	listEntry_t *unlocked_distribution_addressesListEntry;
    list_ForEach(unlocked_distribution_addressesListEntry, inline_response_200_2->unlocked_distribution_addresses) {
    if(cJSON_AddStringToObject(unlocked_distribution_addresses, "", (char*)unlocked_distribution_addressesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_2_t *inline_response_200_2_parseFromJSON(cJSON *inline_response_200_2JSON){

    inline_response_200_2_t *inline_response_200_2_local_var = NULL;

    // inline_response_200_2->current_coinhour_supply
    cJSON *current_coinhour_supply = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "current_coinhour_supply");
    if (current_coinhour_supply) { 
    if(!cJSON_IsString(current_coinhour_supply))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->current_supply
    cJSON *current_supply = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "current_supply");
    if (current_supply) { 
    if(!cJSON_IsString(current_supply))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->locked_distribution_addresses
    cJSON *locked_distribution_addresses = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "locked_distribution_addresses");
    list_t *locked_distribution_addressesList;
    if (locked_distribution_addresses) { 
    cJSON *locked_distribution_addresses_local;
    if(!cJSON_IsArray(locked_distribution_addresses)) {
        goto end;//primitive container
    }
    locked_distribution_addressesList = list_create();

    cJSON_ArrayForEach(locked_distribution_addresses_local, locked_distribution_addresses)
    {
        if(!cJSON_IsString(locked_distribution_addresses_local))
        {
            goto end;
        }
        list_addElement(locked_distribution_addressesList , strdup(locked_distribution_addresses_local->valuestring));
    }
    }

    // inline_response_200_2->max_supply
    cJSON *max_supply = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "max_supply");
    if (max_supply) { 
    if(!cJSON_IsString(max_supply))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->total_coinhour_supply
    cJSON *total_coinhour_supply = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "total_coinhour_supply");
    if (total_coinhour_supply) { 
    if(!cJSON_IsString(total_coinhour_supply))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->total_supply
    cJSON *total_supply = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "total_supply");
    if (total_supply) { 
    if(!cJSON_IsString(total_supply))
    {
    goto end; //String
    }
    }

    // inline_response_200_2->unlocked_distribution_addresses
    cJSON *unlocked_distribution_addresses = cJSON_GetObjectItemCaseSensitive(inline_response_200_2JSON, "unlocked_distribution_addresses");
    list_t *unlocked_distribution_addressesList;
    if (unlocked_distribution_addresses) { 
    cJSON *unlocked_distribution_addresses_local;
    if(!cJSON_IsArray(unlocked_distribution_addresses)) {
        goto end;//primitive container
    }
    unlocked_distribution_addressesList = list_create();

    cJSON_ArrayForEach(unlocked_distribution_addresses_local, unlocked_distribution_addresses)
    {
        if(!cJSON_IsString(unlocked_distribution_addresses_local))
        {
            goto end;
        }
        list_addElement(unlocked_distribution_addressesList , strdup(unlocked_distribution_addresses_local->valuestring));
    }
    }


    inline_response_200_2_local_var = inline_response_200_2_create (
        current_coinhour_supply ? strdup(current_coinhour_supply->valuestring) : NULL,
        current_supply ? strdup(current_supply->valuestring) : NULL,
        locked_distribution_addresses ? locked_distribution_addressesList : NULL,
        max_supply ? strdup(max_supply->valuestring) : NULL,
        total_coinhour_supply ? strdup(total_coinhour_supply->valuestring) : NULL,
        total_supply ? strdup(total_supply->valuestring) : NULL,
        unlocked_distribution_addresses ? unlocked_distribution_addressesList : NULL
        );

    return inline_response_200_2_local_var;
end:
    return NULL;

}
