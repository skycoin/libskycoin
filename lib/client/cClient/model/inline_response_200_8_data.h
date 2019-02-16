/*
 * inline_response_200_8_data.h
 *
 * 
 */

#ifndef _inline_response_200_8_data_H_
#define _inline_response_200_8_data_H_

#include <string.h>
#include "cJSON.h"




typedef struct inline_response_200_8_data_t {
        long version; //numeric

} inline_response_200_8_data_t;

inline_response_200_8_data_t *inline_response_200_8_data_create(
        long version
);

void inline_response_200_8_data_free(inline_response_200_8_data_t *inline_response_200_8_data);

inline_response_200_8_data_t *inline_response_200_8_data_parseFromJSON(char *jsonString);

cJSON *inline_response_200_8_data_convertToJSON(inline_response_200_8_data_t *inline_response_200_8_data);

#endif /* _inline_response_200_8_data_H_ */

