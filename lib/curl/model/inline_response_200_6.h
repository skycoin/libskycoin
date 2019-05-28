/*
 * inline_response_200_6.h
 *
 * 
 */

#ifndef _inline_response_200_6_H_
#define _inline_response_200_6_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "inline_response_200_6_data.h"



typedef struct inline_response_200_6_t {
    inline_response_200_6_data_t *data; //model

} inline_response_200_6_t;

inline_response_200_6_t *inline_response_200_6_create(
    inline_response_200_6_data_t *data
);

void inline_response_200_6_free(inline_response_200_6_t *inline_response_200_6);

inline_response_200_6_t *inline_response_200_6_parseFromJSON(cJSON *inline_response_200_6JSON);

cJSON *inline_response_200_6_convertToJSON(inline_response_200_6_t *inline_response_200_6);

#endif /* _inline_response_200_6_H_ */

