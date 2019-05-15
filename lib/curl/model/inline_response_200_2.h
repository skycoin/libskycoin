/*
 * inline_response_200_2.h
 *
 * 
 */

#ifndef _inline_response_200_2_H_
#define _inline_response_200_2_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_explorer_address_inputs.h"
#include "_api_v1_explorer_address_outputs.h"
#include "_api_v1_explorer_address_status.h"



typedef struct inline_response_200_2_t {
    list_t *outputs; //nonprimitive container
    char *inner_hash; // string
    list_t *inputs; //nonprimitive container
    int fee; //numeric
    list_t *sigs; //primitive container
    long length; //numeric
    char *txid; // string
    int type; //numeric
    _api_v1_explorer_address_status_t *status; //model
    int timestamp; //numeric

} inline_response_200_2_t;

inline_response_200_2_t *inline_response_200_2_create(
    list_t *outputs,
    char *inner_hash,
    list_t *inputs,
    int fee,
    list_t *sigs,
    long length,
    char *txid,
    int type,
    _api_v1_explorer_address_status_t *status,
    int timestamp
);

void inline_response_200_2_free(inline_response_200_2_t *inline_response_200_2);

inline_response_200_2_t *inline_response_200_2_parseFromJSON(cJSON *inline_response_200_2JSON);

cJSON *inline_response_200_2_convertToJSON(inline_response_200_2_t *inline_response_200_2);

#endif /* _inline_response_200_2_H_ */

