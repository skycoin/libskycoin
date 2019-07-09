#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "block_verbose_schema.h"



block_verbose_schema_t *block_verbose_schema_create(
    block_verbose_schema_header_t *header,
    block_verbose_schema_body_t *body,
    int size
    ) {
	block_verbose_schema_t *block_verbose_schema_local_var = malloc(sizeof(block_verbose_schema_t));
    if (!block_verbose_schema_local_var) {
        return NULL;
    }
	block_verbose_schema_local_var->header = header;
	block_verbose_schema_local_var->body = body;
	block_verbose_schema_local_var->size = size;

	return block_verbose_schema_local_var;
}


void block_verbose_schema_free(block_verbose_schema_t *block_verbose_schema) {
    listEntry_t *listEntry;
    block_verbose_schema_header_free(block_verbose_schema->header);
    block_verbose_schema_body_free(block_verbose_schema->body);
	free(block_verbose_schema);
}

cJSON *block_verbose_schema_convertToJSON(block_verbose_schema_t *block_verbose_schema) {
	cJSON *item = cJSON_CreateObject();

	// block_verbose_schema->header
    if(block_verbose_schema->header) { 
    cJSON *header_local_JSON = block_verbose_schema_header_convertToJSON(block_verbose_schema->header);
    if(header_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "header", header_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// block_verbose_schema->body
    if(block_verbose_schema->body) { 
    cJSON *body_local_JSON = block_verbose_schema_body_convertToJSON(block_verbose_schema->body);
    if(body_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "body", body_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// block_verbose_schema->size
    if(block_verbose_schema->size) { 
    if(cJSON_AddNumberToObject(item, "size", block_verbose_schema->size) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

block_verbose_schema_t *block_verbose_schema_parseFromJSON(cJSON *block_verbose_schemaJSON){

    block_verbose_schema_t *block_verbose_schema_local_var = NULL;

    // block_verbose_schema->header
    cJSON *header = cJSON_GetObjectItemCaseSensitive(block_verbose_schemaJSON, "header");
    block_verbose_schema_header_t *header_local_nonprim = NULL;
    if (header) { 
    header_local_nonprim = block_verbose_schema_header_parseFromJSON(header); //nonprimitive
    }

    // block_verbose_schema->body
    cJSON *body = cJSON_GetObjectItemCaseSensitive(block_verbose_schemaJSON, "body");
    block_verbose_schema_body_t *body_local_nonprim = NULL;
    if (body) { 
    body_local_nonprim = block_verbose_schema_body_parseFromJSON(body); //nonprimitive
    }

    // block_verbose_schema->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(block_verbose_schemaJSON, "size");
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }


    block_verbose_schema_local_var = block_verbose_schema_create (
        header ? header_local_nonprim : NULL,
        body ? body_local_nonprim : NULL,
        size ? size->valuedouble : 0
        );

    return block_verbose_schema_local_var;
end:
    return NULL;

}
