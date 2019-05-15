/*
 * inline_response_200_7_data.h
 *
 * 
 */

#ifndef _inline_response_200_7_data_H_
#define _inline_response_200_7_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_7_data_t {
    long version; //numeric

} inline_response_200_7_data_t;

inline_response_200_7_data_t *inline_response_200_7_data_create(
    long version
);

void inline_response_200_7_data_free(inline_response_200_7_data_t *inline_response_200_7_data);

inline_response_200_7_data_t *inline_response_200_7_data_parseFromJSON(cJSON *inline_response_200_7_dataJSON);

cJSON *inline_response_200_7_data_convertToJSON(inline_response_200_7_data_t *inline_response_200_7_data);

#endif /* _inline_response_200_7_data_H_ */

