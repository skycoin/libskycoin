/*
 * _api_v1_explorer_address_status.h
 *
 * 
 */

#ifndef __api_v1_explorer_address_status_H_
#define __api_v1_explorer_address_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_explorer_address_status_t {
    int unconfirmed; //boolean
    long block_seq; //numeric
    long label; //numeric
    int confirmed; //boolean

} _api_v1_explorer_address_status_t;

_api_v1_explorer_address_status_t *_api_v1_explorer_address_status_create(
    int unconfirmed,
    long block_seq,
    long label,
    int confirmed
);

void _api_v1_explorer_address_status_free(_api_v1_explorer_address_status_t *_api_v1_explorer_address_status);

_api_v1_explorer_address_status_t *_api_v1_explorer_address_status_parseFromJSON(cJSON *_api_v1_explorer_address_statusJSON);

cJSON *_api_v1_explorer_address_status_convertToJSON(_api_v1_explorer_address_status_t *_api_v1_explorer_address_status);

#endif /* __api_v1_explorer_address_status_H_ */

