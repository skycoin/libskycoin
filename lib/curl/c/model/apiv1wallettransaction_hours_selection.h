/*
 * apiv1wallettransaction_hours_selection.h
 *
 * 
 */

#ifndef _apiv1wallettransaction_hours_selection_H_
#define _apiv1wallettransaction_hours_selection_H_

#include <string.h>
#include "cJSON.h"




typedef struct apiv1wallettransaction_hours_selection_t {
        char *mode; //no enum string
        char *share_factor; //no enum string
        char *type; //no enum string

} apiv1wallettransaction_hours_selection_t;

apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection_create(
        char *mode,
        char *share_factor,
        char *type
);

void apiv1wallettransaction_hours_selection_free(apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection);

apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection_parseFromJSON(char *jsonString);

cJSON *apiv1wallettransaction_hours_selection_convertToJSON(apiv1wallettransaction_hours_selection_t *apiv1wallettransaction_hours_selection);

#endif /* _apiv1wallettransaction_hours_selection_H_ */

