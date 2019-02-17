/*
 * inline_response_200_1.h
 *
 * 
 */

#ifndef _inline_response_200_1_H_
#define _inline_response_200_1_H_

#include <string.h>
#include "cJSON.h"




typedef struct inline_response_200_1_t {
        char *csrf_token; //no enum string

} inline_response_200_1_t;

inline_response_200_1_t *inline_response_200_1_create(
        char *csrf_token
);

void inline_response_200_1_free(inline_response_200_1_t *inline_response_200_1);

inline_response_200_1_t *inline_response_200_1_parseFromJSON(char *jsonString);

cJSON *inline_response_200_1_convertToJSON(inline_response_200_1_t *inline_response_200_1);

#endif /* _inline_response_200_1_H_ */

