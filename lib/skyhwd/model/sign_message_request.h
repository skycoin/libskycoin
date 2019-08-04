/*
 * sign_message_request.h
 *
 * 
 */

#ifndef _sign_message_request_H_
#define _sign_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct sign_message_request_t {
    int address_n; //numeric
    char *message; // string

} sign_message_request_t;

sign_message_request_t *sign_message_request_create(
    int address_n,
    char *message
);

void sign_message_request_free(sign_message_request_t *sign_message_request);

sign_message_request_t *sign_message_request_parseFromJSON(cJSON *sign_message_requestJSON);

cJSON *sign_message_request_convertToJSON(sign_message_request_t *sign_message_request);

#endif /* _sign_message_request_H_ */

