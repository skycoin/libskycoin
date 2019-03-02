/*
 * inline_response_200_7.h
 *
 * 
 */

#ifndef _inline_response_200_7_H_
#define _inline_response_200_7_H_

#include <string.h>
#include "cJSON.h"
#include "inline_response_200_7_data.h"
#include "object.h"




typedef struct inline_response_200_7_t {
        inline_response_200_7_data_t *data; //nonprimitive
        object_t *error; //nonprimitive

} inline_response_200_7_t;

inline_response_200_7_t *inline_response_200_7_create(
        inline_response_200_7_data_t *data,
        object_t *error
);

void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7);

inline_response_200_7_t *inline_response_200_7_parseFromJSON(char *jsonString);

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7);

#endif /* _inline_response_200_7_H_ */

