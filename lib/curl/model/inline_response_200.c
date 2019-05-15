#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200.h"



inline_response_200_t *inline_response_200_create(
    long hours,
    int coins,
    char *uxid,
    char *owner_address,
    int spent_block_seq,
    char *spent_tx,
    long time,
    long src_block_seq,
    char *src_tx
    ) {
	inline_response_200_t *inline_response_200_local_var = malloc(sizeof(inline_response_200_t));
    if (!inline_response_200_local_var) {
        return NULL;
    }
	inline_response_200_local_var->hours = hours;
	inline_response_200_local_var->coins = coins;
	inline_response_200_local_var->uxid = uxid;
	inline_response_200_local_var->owner_address = owner_address;
	inline_response_200_local_var->spent_block_seq = spent_block_seq;
	inline_response_200_local_var->spent_tx = spent_tx;
	inline_response_200_local_var->time = time;
	inline_response_200_local_var->src_block_seq = src_block_seq;
	inline_response_200_local_var->src_tx = src_tx;

	return inline_response_200_local_var;
}


void inline_response_200_free(inline_response_200_t *inline_response_200) {
    listEntry_t *listEntry;
    free(inline_response_200->uxid);
    free(inline_response_200->owner_address);
    free(inline_response_200->spent_tx);
    free(inline_response_200->src_tx);
	free(inline_response_200);
}

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200->hours
    if(inline_response_200->hours) { 
    if(cJSON_AddNumberToObject(item, "hours", inline_response_200->hours) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200->coins
    if(inline_response_200->coins) { 
    if(cJSON_AddNumberToObject(item, "coins", inline_response_200->coins) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200->uxid
    if(inline_response_200->uxid) { 
    if(cJSON_AddStringToObject(item, "uxid", inline_response_200->uxid) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200->owner_address
    if(inline_response_200->owner_address) { 
    if(cJSON_AddStringToObject(item, "owner_address", inline_response_200->owner_address) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200->spent_block_seq
    if(inline_response_200->spent_block_seq) { 
    if(cJSON_AddNumberToObject(item, "spent_block_seq", inline_response_200->spent_block_seq) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200->spent_tx
    if(inline_response_200->spent_tx) { 
    if(cJSON_AddStringToObject(item, "spent_tx", inline_response_200->spent_tx) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200->time
    if(inline_response_200->time) { 
    if(cJSON_AddNumberToObject(item, "time", inline_response_200->time) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200->src_block_seq
    if(inline_response_200->src_block_seq) { 
    if(cJSON_AddNumberToObject(item, "src_block_seq", inline_response_200->src_block_seq) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200->src_tx
    if(inline_response_200->src_tx) { 
    if(cJSON_AddStringToObject(item, "src_tx", inline_response_200->src_tx) == NULL) {
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

inline_response_200_t *inline_response_200_parseFromJSON(cJSON *inline_response_200JSON){

    inline_response_200_t *inline_response_200_local_var = NULL;

    // inline_response_200->hours
    cJSON *hours = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "hours");
    if (hours) { 
    if(!cJSON_IsNumber(hours))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200->coins
    cJSON *coins = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "coins");
    if (coins) { 
    if(!cJSON_IsNumber(coins))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200->uxid
    cJSON *uxid = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "uxid");
    if (uxid) { 
    if(!cJSON_IsString(uxid))
    {
    goto end; //String
    }
    }

    // inline_response_200->owner_address
    cJSON *owner_address = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "owner_address");
    if (owner_address) { 
    if(!cJSON_IsString(owner_address))
    {
    goto end; //String
    }
    }

    // inline_response_200->spent_block_seq
    cJSON *spent_block_seq = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "spent_block_seq");
    if (spent_block_seq) { 
    if(!cJSON_IsNumber(spent_block_seq))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200->spent_tx
    cJSON *spent_tx = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "spent_tx");
    if (spent_tx) { 
    if(!cJSON_IsString(spent_tx))
    {
    goto end; //String
    }
    }

    // inline_response_200->time
    cJSON *time = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "time");
    if (time) { 
    if(!cJSON_IsNumber(time))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200->src_block_seq
    cJSON *src_block_seq = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "src_block_seq");
    if (src_block_seq) { 
    if(!cJSON_IsNumber(src_block_seq))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200->src_tx
    cJSON *src_tx = cJSON_GetObjectItemCaseSensitive(inline_response_200JSON, "src_tx");
    if (src_tx) { 
    if(!cJSON_IsString(src_tx))
    {
    goto end; //String
    }
    }


    inline_response_200_local_var = inline_response_200_create (
        hours ? hours->valuedouble : 0,
        coins ? coins->valuedouble : 0,
        uxid ? strdup(uxid->valuestring) : NULL,
        owner_address ? strdup(owner_address->valuestring) : NULL,
        spent_block_seq ? spent_block_seq->valuedouble : 0,
        spent_tx ? strdup(spent_tx->valuestring) : NULL,
        time ? time->valuedouble : 0,
        src_block_seq ? src_block_seq->valuedouble : 0,
        src_tx ? strdup(src_tx->valuestring) : NULL
        );

    return inline_response_200_local_var;
end:
    return NULL;

}
