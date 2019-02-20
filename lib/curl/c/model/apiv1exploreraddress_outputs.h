/*
 * apiv1exploreraddress_outputs.h
 *
 * 
 */

#ifndef _apiv1exploreraddress_outputs_H_
#define _apiv1exploreraddress_outputs_H_

#include <string.h>
#include "cJSON.h"




typedef struct apiv1exploreraddress_outputs_t {
        long hours; //numeric
        char *dst; //no enum string
        char *coins; //no enum string
        char *uxid; //no enum string

} apiv1exploreraddress_outputs_t;

apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs_create(
        long hours,
        char *dst,
        char *coins,
        char *uxid
);

void apiv1exploreraddress_outputs_free(apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs);

apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs_parseFromJSON(char *jsonString);

cJSON *apiv1exploreraddress_outputs_convertToJSON(apiv1exploreraddress_outputs_t *apiv1exploreraddress_outputs);

#endif /* _apiv1exploreraddress_outputs_H_ */

