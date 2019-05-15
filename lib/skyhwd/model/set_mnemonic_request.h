/*
 * set_mnemonic_request.h
 *
 * 
 */

#ifndef _set_mnemonic_request_H_
#define _set_mnemonic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct set_mnemonic_request_t {
    char *mnemonic; // string

} set_mnemonic_request_t;

set_mnemonic_request_t *set_mnemonic_request_create(
    char *mnemonic
);

void set_mnemonic_request_free(set_mnemonic_request_t *set_mnemonic_request);

set_mnemonic_request_t *set_mnemonic_request_parseFromJSON(cJSON *set_mnemonic_requestJSON);

cJSON *set_mnemonic_request_convertToJSON(set_mnemonic_request_t *set_mnemonic_request);

#endif /* _set_mnemonic_request_H_ */

