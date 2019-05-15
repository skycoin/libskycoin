/*
 * _api_v1_explorer_address_inputs.h
 *
 * 
 */

#ifndef __api_v1_explorer_address_inputs_H_
#define __api_v1_explorer_address_inputs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_explorer_address_inputs_t {
    char *owner; // string
    long hours; //numeric
    long calculated_hours; //numeric
    char *coins; // string
    char *uxid; // string

} _api_v1_explorer_address_inputs_t;

_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs_create(
    char *owner,
    long hours,
    long calculated_hours,
    char *coins,
    char *uxid
);

void _api_v1_explorer_address_inputs_free(_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs);

_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs_parseFromJSON(cJSON *_api_v1_explorer_address_inputsJSON);

cJSON *_api_v1_explorer_address_inputs_convertToJSON(_api_v1_explorer_address_inputs_t *_api_v1_explorer_address_inputs);

#endif /* __api_v1_explorer_address_inputs_H_ */

