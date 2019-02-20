/*
 * inline_response_200_9.h
 *
 * 
 */

#ifndef _inline_response_200_9_H_
#define _inline_response_200_9_H_

#include <string.h>
#include "cJSON.h"
#include "inline_response_200_9_data.h"
#include "object.h"




typedef struct inline_response_200_9_t {
        inline_response_200_9_data_t *data; //nonprimitive
        object_t *error; //nonprimitive

} inline_response_200_9_t;

inline_response_200_9_t *inline_response_200_9_create(
        inline_response_200_9_data_t *data,
        object_t *error
);

void inline_response_200_9_free(inline_response_200_9_t *inline_response_200_9);

inline_response_200_9_t *inline_response_200_9_parseFromJSON(char *jsonString);

cJSON *inline_response_200_9_convertToJSON(inline_response_200_9_t *inline_response_200_9);

#endif /* _inline_response_200_9_H_ */

