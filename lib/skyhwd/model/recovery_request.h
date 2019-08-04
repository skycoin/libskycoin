/*
 * recovery_request.h
 *
 * 
 */

#ifndef _recovery_request_H_
#define _recovery_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct recovery_request_t {
    int word_count; //numeric
    int use_passphrase; //boolean
    int dry_run; //boolean

} recovery_request_t;

recovery_request_t *recovery_request_create(
    int word_count,
    int use_passphrase,
    int dry_run
);

void recovery_request_free(recovery_request_t *recovery_request);

recovery_request_t *recovery_request_parseFromJSON(cJSON *recovery_requestJSON);

cJSON *recovery_request_convertToJSON(recovery_request_t *recovery_request);

#endif /* _recovery_request_H_ */

