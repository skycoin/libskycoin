/*
 * passphrase_request.h
 *
 * 
 */

#ifndef _passphrase_request_H_
#define _passphrase_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct passphrase_request_t {
    char *passphrase; // string

} passphrase_request_t;

passphrase_request_t *passphrase_request_create(
    char *passphrase
);

void passphrase_request_free(passphrase_request_t *passphrase_request);

passphrase_request_t *passphrase_request_parseFromJSON(cJSON *passphrase_requestJSON);

cJSON *passphrase_request_convertToJSON(passphrase_request_t *passphrase_request);

#endif /* _passphrase_request_H_ */

