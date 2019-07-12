/*
 * block_verbose_schema_header.h
 *
 * 
 */

#ifndef _block_verbose_schema_header_H_
#define _block_verbose_schema_header_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct block_verbose_schema_header_t {
    int seq; //numeric
    int timestamp; //numeric
    int fee; //numeric
    int version; //numeric
    char *block_hash; // string
    char *previous_block_hash; // string
    char *tx_body_hash; // string
    char *ux_hash; // string

} block_verbose_schema_header_t;

block_verbose_schema_header_t *block_verbose_schema_header_create(
    int seq,
    int timestamp,
    int fee,
    int version,
    char *block_hash,
    char *previous_block_hash,
    char *tx_body_hash,
    char *ux_hash
);

void block_verbose_schema_header_free(block_verbose_schema_header_t *block_verbose_schema_header);

block_verbose_schema_header_t *block_verbose_schema_header_parseFromJSON(cJSON *block_verbose_schema_headerJSON);

cJSON *block_verbose_schema_header_convertToJSON(block_verbose_schema_header_t *block_verbose_schema_header);

#endif /* _block_verbose_schema_header_H_ */

