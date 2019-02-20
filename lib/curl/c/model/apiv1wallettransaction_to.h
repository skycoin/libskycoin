/*
 * apiv1wallettransaction_to.h
 *
 * 
 */

#ifndef _apiv1wallettransaction_to_H_
#define _apiv1wallettransaction_to_H_

#include <string.h>
#include "cJSON.h"




typedef struct apiv1wallettransaction_to_t {
        long hours; //numeric
        char *address; //no enum string
        long coins; //numeric

} apiv1wallettransaction_to_t;

apiv1wallettransaction_to_t *apiv1wallettransaction_to_create(
        long hours,
        char *address,
        long coins
);

void apiv1wallettransaction_to_free(apiv1wallettransaction_to_t *apiv1wallettransaction_to);

apiv1wallettransaction_to_t *apiv1wallettransaction_to_parseFromJSON(char *jsonString);

cJSON *apiv1wallettransaction_to_convertToJSON(apiv1wallettransaction_to_t *apiv1wallettransaction_to);

#endif /* _apiv1wallettransaction_to_H_ */

