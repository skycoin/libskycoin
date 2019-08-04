/*
 * http_error_response_error.h
 *
 * 
 */

#ifndef _http_error_response_error_H_
#define _http_error_response_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct http_error_response_error_t {
    int code; //numeric
    char *message; // string

} http_error_response_error_t;

http_error_response_error_t *http_error_response_error_create(
    int code,
    char *message
);

void http_error_response_error_free(http_error_response_error_t *http_error_response_error);

http_error_response_error_t *http_error_response_error_parseFromJSON(cJSON *http_error_response_errorJSON);

cJSON *http_error_response_error_convertToJSON(http_error_response_error_t *http_error_response_error);

#endif /* _http_error_response_error_H_ */

