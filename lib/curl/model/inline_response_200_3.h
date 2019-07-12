/*
 * inline_response_200_3.h
 *
 * 
 */

#ifndef _inline_response_200_3_H_
#define _inline_response_200_3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_3_t {
    char *csrf_token; // string

} inline_response_200_3_t;

inline_response_200_3_t *inline_response_200_3_create(
    char *csrf_token
);

void inline_response_200_3_free(inline_response_200_3_t *inline_response_200_3);

inline_response_200_3_t *inline_response_200_3_parseFromJSON(cJSON *inline_response_200_3JSON);

cJSON *inline_response_200_3_convertToJSON(inline_response_200_3_t *inline_response_200_3);

#endif /* _inline_response_200_3_H_ */

