/*
 * inline_response_default.h
 *
 * 
 */

#ifndef _inline_response_default_H_
#define _inline_response_default_H_

#include <string.h>
#include "cJSON.h"




typedef struct inline_response_default_t {
        int code; //numeric
        char *message; //no enum string

} inline_response_default_t;

inline_response_default_t *inline_response_default_create(
        int code,
        char *message
);

void inline_response_default_free(inline_response_default_t *inline_response_default);

inline_response_default_t *inline_response_default_parseFromJSON(char *jsonString);

cJSON *inline_response_default_convertToJSON(inline_response_default_t *inline_response_default);

#endif /* _inline_response_default_H_ */

