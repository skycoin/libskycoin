/*
 * sign_message_response.h
 *
 * 
 */

#ifndef _sign_message_response_H_
#define _sign_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct sign_message_response_t {
    char *data; // string

} sign_message_response_t;

sign_message_response_t *sign_message_response_create(
    char *data
);

void sign_message_response_free(sign_message_response_t *sign_message_response);

sign_message_response_t *sign_message_response_parseFromJSON(cJSON *sign_message_responseJSON);

cJSON *sign_message_response_convertToJSON(sign_message_response_t *sign_message_response);

#endif /* _sign_message_response_H_ */

