/*
 * inline_response_200_8.h
 *
 * 
 */

#ifndef _inline_response_200_8_H_
#define _inline_response_200_8_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "inline_response_200_8_data.h"



typedef struct inline_response_200_8_t {
    inline_response_200_8_data_t *data; //model

} inline_response_200_8_t;

inline_response_200_8_t *inline_response_200_8_create(
    inline_response_200_8_data_t *data
);

void inline_response_200_8_free(inline_response_200_8_t *inline_response_200_8);

inline_response_200_8_t *inline_response_200_8_parseFromJSON(cJSON *inline_response_200_8JSON);

cJSON *inline_response_200_8_convertToJSON(inline_response_200_8_t *inline_response_200_8);

#endif /* _inline_response_200_8_H_ */

