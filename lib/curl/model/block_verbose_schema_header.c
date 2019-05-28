#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "block_verbose_schema_header.h"



block_verbose_schema_header_t *block_verbose_schema_header_create(
    int seq,
    int timestamp,
    int fee,
    int version,
    char *block_hash,
    char *previous_block_hash,
    char *tx_body_hash,
    char *ux_hash
    ) {
	block_verbose_schema_header_t *block_verbose_schema_header_local_var = malloc(sizeof(block_verbose_schema_header_t));
    if (!block_verbose_schema_header_local_var) {
        return NULL;
    }
	block_verbose_schema_header_local_var->seq = seq;
	block_verbose_schema_header_local_var->timestamp = timestamp;
	block_verbose_schema_header_local_var->fee = fee;
	block_verbose_schema_header_local_var->version = version;
	block_verbose_schema_header_local_var->block_hash = block_hash;
	block_verbose_schema_header_local_var->previous_block_hash = previous_block_hash;
	block_verbose_schema_header_local_var->tx_body_hash = tx_body_hash;
	block_verbose_schema_header_local_var->ux_hash = ux_hash;

	return block_verbose_schema_header_local_var;
}


void block_verbose_schema_header_free(block_verbose_schema_header_t *block_verbose_schema_header) {
    listEntry_t *listEntry;
    free(block_verbose_schema_header->block_hash);
    free(block_verbose_schema_header->previous_block_hash);
    free(block_verbose_schema_header->tx_body_hash);
    free(block_verbose_schema_header->ux_hash);
	free(block_verbose_schema_header);
}

cJSON *block_verbose_schema_header_convertToJSON(block_verbose_schema_header_t *block_verbose_schema_header) {
	cJSON *item = cJSON_CreateObject();

	// block_verbose_schema_header->seq
    if(block_verbose_schema_header->seq) { 
    if(cJSON_AddNumberToObject(item, "seq", block_verbose_schema_header->seq) == NULL) {
    goto fail; //Numeric
    }
     } 


	// block_verbose_schema_header->timestamp
    if(block_verbose_schema_header->timestamp) { 
    if(cJSON_AddNumberToObject(item, "timestamp", block_verbose_schema_header->timestamp) == NULL) {
    goto fail; //Numeric
    }
     } 


	// block_verbose_schema_header->fee
    if(block_verbose_schema_header->fee) { 
    if(cJSON_AddNumberToObject(item, "fee", block_verbose_schema_header->fee) == NULL) {
    goto fail; //Numeric
    }
     } 


	// block_verbose_schema_header->version
    if(block_verbose_schema_header->version) { 
    if(cJSON_AddNumberToObject(item, "version", block_verbose_schema_header->version) == NULL) {
    goto fail; //Numeric
    }
     } 


	// block_verbose_schema_header->block_hash
    if(block_verbose_schema_header->block_hash) { 
    if(cJSON_AddStringToObject(item, "block_hash", block_verbose_schema_header->block_hash) == NULL) {
    goto fail; //String
    }
     } 


	// block_verbose_schema_header->previous_block_hash
    if(block_verbose_schema_header->previous_block_hash) { 
    if(cJSON_AddStringToObject(item, "previous_block_hash", block_verbose_schema_header->previous_block_hash) == NULL) {
    goto fail; //String
    }
     } 


	// block_verbose_schema_header->tx_body_hash
    if(block_verbose_schema_header->tx_body_hash) { 
    if(cJSON_AddStringToObject(item, "tx_body_hash", block_verbose_schema_header->tx_body_hash) == NULL) {
    goto fail; //String
    }
     } 


	// block_verbose_schema_header->ux_hash
    if(block_verbose_schema_header->ux_hash) { 
    if(cJSON_AddStringToObject(item, "ux_hash", block_verbose_schema_header->ux_hash) == NULL) {
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

block_verbose_schema_header_t *block_verbose_schema_header_parseFromJSON(cJSON *block_verbose_schema_headerJSON){

    block_verbose_schema_header_t *block_verbose_schema_header_local_var = NULL;

    // block_verbose_schema_header->seq
    cJSON *seq = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "seq");
    if (seq) { 
    if(!cJSON_IsNumber(seq))
    {
    goto end; //Numeric
    }
    }

    // block_verbose_schema_header->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "timestamp");
    if (timestamp) { 
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }
    }

    // block_verbose_schema_header->fee
    cJSON *fee = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "fee");
    if (fee) { 
    if(!cJSON_IsNumber(fee))
    {
    goto end; //Numeric
    }
    }

    // block_verbose_schema_header->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "version");
    if (version) { 
    if(!cJSON_IsNumber(version))
    {
    goto end; //Numeric
    }
    }

    // block_verbose_schema_header->block_hash
    cJSON *block_hash = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "block_hash");
    if (block_hash) { 
    if(!cJSON_IsString(block_hash))
    {
    goto end; //String
    }
    }

    // block_verbose_schema_header->previous_block_hash
    cJSON *previous_block_hash = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "previous_block_hash");
    if (previous_block_hash) { 
    if(!cJSON_IsString(previous_block_hash))
    {
    goto end; //String
    }
    }

    // block_verbose_schema_header->tx_body_hash
    cJSON *tx_body_hash = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "tx_body_hash");
    if (tx_body_hash) { 
    if(!cJSON_IsString(tx_body_hash))
    {
    goto end; //String
    }
    }

    // block_verbose_schema_header->ux_hash
    cJSON *ux_hash = cJSON_GetObjectItemCaseSensitive(block_verbose_schema_headerJSON, "ux_hash");
    if (ux_hash) { 
    if(!cJSON_IsString(ux_hash))
    {
    goto end; //String
    }
    }


    block_verbose_schema_header_local_var = block_verbose_schema_header_create (
        seq ? seq->valuedouble : 0,
        timestamp ? timestamp->valuedouble : 0,
        fee ? fee->valuedouble : 0,
        version ? version->valuedouble : 0,
        block_hash ? strdup(block_hash->valuestring) : NULL,
        previous_block_hash ? strdup(previous_block_hash->valuestring) : NULL,
        tx_body_hash ? strdup(tx_body_hash->valuestring) : NULL,
        ux_hash ? strdup(ux_hash->valuestring) : NULL
        );

    return block_verbose_schema_header_local_var;
end:
    return NULL;

}
