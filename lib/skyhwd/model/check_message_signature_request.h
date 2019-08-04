/*
 * check_message_signature_request.h
 *
 * 
 */

#ifndef _check_message_signature_request_H_
#define _check_message_signature_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct check_message_signature_request_t {
    char *message; // string
    char *signature; // string
    char *address; // string

} check_message_signature_request_t;

check_message_signature_request_t *check_message_signature_request_create(
    char *message,
    char *signature,
    char *address
);

void check_message_signature_request_free(check_message_signature_request_t *check_message_signature_request);

check_message_signature_request_t *check_message_signature_request_parseFromJSON(cJSON *check_message_signature_requestJSON);

cJSON *check_message_signature_request_convertToJSON(check_message_signature_request_t *check_message_signature_request);

#endif /* _check_message_signature_request_H_ */

