/*
 * version_response.h
 *
 * 
 */

#ifndef _version_response_H_
#define _version_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "version_response_data.h"



typedef struct version_response_t {
    version_response_data_t *data; //model

} version_response_t;

version_response_t *version_response_create(
    version_response_data_t *data
);

void version_response_free(version_response_t *version_response);

version_response_t *version_response_parseFromJSON(cJSON *version_responseJSON);

cJSON *version_response_convertToJSON(version_response_t *version_response);

#endif /* _version_response_H_ */

