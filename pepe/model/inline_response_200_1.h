/*
 * inline_response_200_1.h
 *
 * 
 */

#ifndef _inline_response_200_1_H_
#define _inline_response_200_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "block_schema.h"



typedef struct inline_response_200_1_t {
    list_t *blocks; //nonprimitive container

} inline_response_200_1_t;

inline_response_200_1_t *inline_response_200_1_create(
    list_t *blocks
);

void inline_response_200_1_free(inline_response_200_1_t *inline_response_200_1);

inline_response_200_1_t *inline_response_200_1_parseFromJSON(cJSON *inline_response_200_1JSON);

cJSON *inline_response_200_1_convertToJSON(inline_response_200_1_t *inline_response_200_1);

#endif /* _inline_response_200_1_H_ */

