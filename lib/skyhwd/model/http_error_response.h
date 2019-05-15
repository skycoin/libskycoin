/*
 * http_error_response.h
 *
 * 
 */

#ifndef _http_error_response_H_
#define _http_error_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "http_error_response_error.h"



typedef struct http_error_response_t {
    http_error_response_error_t *error; //model

} http_error_response_t;

http_error_response_t *http_error_response_create(
    http_error_response_error_t *error
);

void http_error_response_free(http_error_response_t *http_error_response);

http_error_response_t *http_error_response_parseFromJSON(cJSON *http_error_responseJSON);

cJSON *http_error_response_convertToJSON(http_error_response_t *http_error_response);

#endif /* _http_error_response_H_ */

