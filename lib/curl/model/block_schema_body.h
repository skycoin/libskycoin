/*
 * block_schema_body.h
 *
 * 
 */

#ifndef _block_schema_body_H_
#define _block_schema_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct block_schema_body_t {
    list_t *txns; //nonprimitive container

} block_schema_body_t;

block_schema_body_t *block_schema_body_create(
    list_t *txns
);

void block_schema_body_free(block_schema_body_t *block_schema_body);

block_schema_body_t *block_schema_body_parseFromJSON(cJSON *block_schema_bodyJSON);

cJSON *block_schema_body_convertToJSON(block_schema_body_t *block_schema_body);

#endif /* _block_schema_body_H_ */

