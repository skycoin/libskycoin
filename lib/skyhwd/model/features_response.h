/*
 * features_response.h
 *
 * 
 */

#ifndef _features_response_H_
#define _features_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "features_response_data.h"



typedef struct features_response_t {
    features_response_data_t *data; //model

} features_response_t;

features_response_t *features_response_create(
    features_response_data_t *data
);

void features_response_free(features_response_t *features_response);

features_response_t *features_response_parseFromJSON(cJSON *features_responseJSON);

cJSON *features_response_convertToJSON(features_response_t *features_response);

#endif /* _features_response_H_ */

