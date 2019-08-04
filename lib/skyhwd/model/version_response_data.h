/*
 * version_response_data.h
 *
 * 
 */

#ifndef _version_response_data_H_
#define _version_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct version_response_data_t {
    char *commit; // string
    char *version; // string
    char *branch; // string

} version_response_data_t;

version_response_data_t *version_response_data_create(
    char *commit,
    char *version,
    char *branch
);

void version_response_data_free(version_response_data_t *version_response_data);

version_response_data_t *version_response_data_parseFromJSON(cJSON *version_response_dataJSON);

cJSON *version_response_data_convertToJSON(version_response_data_t *version_response_data);

#endif /* _version_response_data_H_ */

