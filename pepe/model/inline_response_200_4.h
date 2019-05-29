/*
 * inline_response_200_4.h
 *
 * 
 */

#ifndef _inline_response_200_4_H_
#define _inline_response_200_4_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_4_t {
    char *csrf_token; // string

} inline_response_200_4_t;

inline_response_200_4_t *inline_response_200_4_create(
    char *csrf_token
);

void inline_response_200_4_free(inline_response_200_4_t *inline_response_200_4);

inline_response_200_4_t *inline_response_200_4_parseFromJSON(cJSON *inline_response_200_4JSON);

cJSON *inline_response_200_4_convertToJSON(inline_response_200_4_t *inline_response_200_4);

#endif /* _inline_response_200_4_H_ */

