/*
 * inline_response_200_2.h
 *
 * 
 */

#ifndef _inline_response_200_2_H_
#define _inline_response_200_2_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_2_t {
    char *csrf_token; // string

} inline_response_200_2_t;

inline_response_200_2_t *inline_response_200_2_create(
    char *csrf_token
);

void inline_response_200_2_free(inline_response_200_2_t *inline_response_200_2);

inline_response_200_2_t *inline_response_200_2_parseFromJSON(cJSON *inline_response_200_2JSON);

cJSON *inline_response_200_2_convertToJSON(inline_response_200_2_t *inline_response_200_2);

#endif /* _inline_response_200_2_H_ */

