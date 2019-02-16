/*
 * apiv1exploreraddress_inputs.h
 *
 * 
 */

#ifndef _apiv1exploreraddress_inputs_H_
#define _apiv1exploreraddress_inputs_H_

#include <string.h>
#include "cJSON.h"




typedef struct apiv1exploreraddress_inputs_t {
        char *owner; //no enum string
        long hours; //numeric
        long calculated_hours; //numeric
        char *coins; //no enum string
        char *uxid; //no enum string

} apiv1exploreraddress_inputs_t;

apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs_create(
        char *owner,
        long hours,
        long calculated_hours,
        char *coins,
        char *uxid
);

void apiv1exploreraddress_inputs_free(apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs);

apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs_parseFromJSON(char *jsonString);

cJSON *apiv1exploreraddress_inputs_convertToJSON(apiv1exploreraddress_inputs_t *apiv1exploreraddress_inputs);

#endif /* _apiv1exploreraddress_inputs_H_ */

