/*
 * inline_response_200_7.h
 *
 * 
 */

#ifndef _inline_response_200_7_H_
#define _inline_response_200_7_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "object.h"



typedef struct inline_response_200_7_t {
    object_t *data; //model

} inline_response_200_7_t;

inline_response_200_7_t *inline_response_200_7_create(
    object_t *data
);

void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7);

inline_response_200_7_t *inline_response_200_7_parseFromJSON(cJSON *inline_response_200_7JSON);

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7);

#endif /* _inline_response_200_7_H_ */

