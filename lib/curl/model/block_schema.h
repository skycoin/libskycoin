/*
 * block_schema.h
 *
 * 
 */

#ifndef _block_schema_H_
#define _block_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "block_schema_body.h"
#include "block_verbose_schema_header.h"



typedef struct block_schema_t {
    block_verbose_schema_header_t *header; //model
    block_schema_body_t *body; //model
    int size; //numeric

} block_schema_t;

block_schema_t *block_schema_create(
    block_verbose_schema_header_t *header,
    block_schema_body_t *body,
    int size
);

void block_schema_free(block_schema_t *block_schema);

block_schema_t *block_schema_parseFromJSON(cJSON *block_schemaJSON);

cJSON *block_schema_convertToJSON(block_schema_t *block_schema);

#endif /* _block_schema_H_ */

