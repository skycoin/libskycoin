/*
 * apply_settings_request.h
 *
 * 
 */

#ifndef _apply_settings_request_H_
#define _apply_settings_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct apply_settings_request_t {
    char *label; // string
    int use_passphrase; //boolean
    char *language; // string

} apply_settings_request_t;

apply_settings_request_t *apply_settings_request_create(
    char *label,
    int use_passphrase,
    char *language
);

void apply_settings_request_free(apply_settings_request_t *apply_settings_request);

apply_settings_request_t *apply_settings_request_parseFromJSON(cJSON *apply_settings_requestJSON);

cJSON *apply_settings_request_convertToJSON(apply_settings_request_t *apply_settings_request);

#endif /* _apply_settings_request_H_ */

