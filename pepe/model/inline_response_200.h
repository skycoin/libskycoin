/*
 * inline_response_200.h
 *
 * 
 */

#ifndef _inline_response_200_H_
#define _inline_response_200_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_t {
    long count; //numeric

} inline_response_200_t;

inline_response_200_t *inline_response_200_create(
    long count
);

void inline_response_200_free(inline_response_200_t *inline_response_200);

inline_response_200_t *inline_response_200_parseFromJSON(cJSON *inline_response_200JSON);

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200);

#endif /* _inline_response_200_H_ */

