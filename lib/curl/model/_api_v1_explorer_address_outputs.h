/*
 * _api_v1_explorer_address_outputs.h
 *
 * 
 */

#ifndef __api_v1_explorer_address_outputs_H_
#define __api_v1_explorer_address_outputs_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_explorer_address_outputs_t {
    long hours; //numeric
    char *dst; // string
    char *coins; // string
    char *uxid; // string

} _api_v1_explorer_address_outputs_t;

_api_v1_explorer_address_outputs_t *_api_v1_explorer_address_outputs_create(
    long hours,
    char *dst,
    char *coins,
    char *uxid
);

void _api_v1_explorer_address_outputs_free(_api_v1_explorer_address_outputs_t *_api_v1_explorer_address_outputs);

_api_v1_explorer_address_outputs_t *_api_v1_explorer_address_outputs_parseFromJSON(cJSON *_api_v1_explorer_address_outputsJSON);

cJSON *_api_v1_explorer_address_outputs_convertToJSON(_api_v1_explorer_address_outputs_t *_api_v1_explorer_address_outputs);

#endif /* __api_v1_explorer_address_outputs_H_ */

