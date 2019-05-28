/*
 * inline_response_200_6_data.h
 *
 * 
 */

#ifndef _inline_response_200_6_data_H_
#define _inline_response_200_6_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "transaction.h"



typedef struct inline_response_200_6_data_t {
    transaction_t *transaction; //model

} inline_response_200_6_data_t;

inline_response_200_6_data_t *inline_response_200_6_data_create(
    transaction_t *transaction
);

void inline_response_200_6_data_free(inline_response_200_6_data_t *inline_response_200_6_data);

inline_response_200_6_data_t *inline_response_200_6_data_parseFromJSON(cJSON *inline_response_200_6_dataJSON);

cJSON *inline_response_200_6_data_convertToJSON(inline_response_200_6_data_t *inline_response_200_6_data);

#endif /* _inline_response_200_6_data_H_ */

