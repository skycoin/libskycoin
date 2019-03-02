/*
 * inline_object.h
 *
 * 
 */

#ifndef _inline_object_H_
#define _inline_object_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1wallettransaction_hours_selection.h"
#include "apiv1wallettransaction_to.h"
#include "apiv1wallettransaction_wallet.h"
#include "list.h"

typedef int bool;
#define true 1
#define false 0



typedef struct inline_object_t {
        char *change_address; //no enum string
        apiv1wallettransaction_hours_selection_t *hours_selection; //nonprimitive
        bool ignore_unconfirmed; //boolean
        list_t *to; //nonprimitive container
        apiv1wallettransaction_wallet_t *wallet; //nonprimitive

} inline_object_t;

inline_object_t *inline_object_create(
        char *change_address,
        apiv1wallettransaction_hours_selection_t *hours_selection,
        bool ignore_unconfirmed,
        list_t *to,
        apiv1wallettransaction_wallet_t *wallet
);

void inline_object_free(inline_object_t *inline_object);

inline_object_t *inline_object_parseFromJSON(char *jsonString);

cJSON *inline_object_convertToJSON(inline_object_t *inline_object);

#endif /* _inline_object_H_ */

