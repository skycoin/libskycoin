/*
 * csrf_response.h
 *
 * 
 */

#ifndef _csrf_response_H_
#define _csrf_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct csrf_response_t {
    char *data; // string

} csrf_response_t;

csrf_response_t *csrf_response_create(
    char *data
);

void csrf_response_free(csrf_response_t *csrf_response);

csrf_response_t *csrf_response_parseFromJSON(cJSON *csrf_responseJSON);

cJSON *csrf_response_convertToJSON(csrf_response_t *csrf_response);

#endif /* _csrf_response_H_ */

