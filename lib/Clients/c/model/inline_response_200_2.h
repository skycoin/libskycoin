/*
 * inline_response_200_2.h
 *
 * 
 */

#ifndef _inline_response_200_2_H_
#define _inline_response_200_2_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1exploreraddress_inputs.h"
#include "apiv1exploreraddress_outputs.h"
#include "apiv1exploreraddress_status.h"
#include "list.h"




typedef struct inline_response_200_2_t {
        list_t *outputs; //nonprimitive container
        char *inner_hash; //no enum string
        list_t *inputs; //nonprimitive container
        int fee; //numeric
        list_t *sigs; //primitive container
        long length; //numeric
        char *txid; //no enum string
        int type; //numeric
        apiv1exploreraddress_status_t *status; //nonprimitive
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
        apiv1exploreraddress_status_t *status,
        int timestamp
);

void inline_response_200_2_free(inline_response_200_2_t *inline_response_200_2);

inline_response_200_2_t *inline_response_200_2_parseFromJSON(char *jsonString);

cJSON *inline_response_200_2_convertToJSON(inline_response_200_2_t *inline_response_200_2);

#endif /* _inline_response_200_2_H_ */

