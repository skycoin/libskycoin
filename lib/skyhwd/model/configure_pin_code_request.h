/*
 * configure_pin_code_request.h
 *
 * 
 */

#ifndef _configure_pin_code_request_H_
#define _configure_pin_code_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct configure_pin_code_request_t {
    int remove_pin; //boolean

} configure_pin_code_request_t;

configure_pin_code_request_t *configure_pin_code_request_create(
    int remove_pin
);

void configure_pin_code_request_free(configure_pin_code_request_t *configure_pin_code_request);

configure_pin_code_request_t *configure_pin_code_request_parseFromJSON(cJSON *configure_pin_code_requestJSON);

cJSON *configure_pin_code_request_convertToJSON(configure_pin_code_request_t *configure_pin_code_request);

#endif /* _configure_pin_code_request_H_ */

