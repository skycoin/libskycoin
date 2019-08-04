/*
 * http_success_response.h
 *
 * 
 */

#ifndef _http_success_response_H_
#define _http_success_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct http_success_response_t {
    list_t *data; //primitive container

} http_success_response_t;

http_success_response_t *http_success_response_create(
    list_t *data
);

void http_success_response_free(http_success_response_t *http_success_response);

http_success_response_t *http_success_response_parseFromJSON(cJSON *http_success_responseJSON);

cJSON *http_success_response_convertToJSON(http_success_response_t *http_success_response);

#endif /* _http_success_response_H_ */

