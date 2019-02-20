/*
 * apiv1wallettransaction_wallet.h
 *
 * 
 */

#ifndef _apiv1wallettransaction_wallet_H_
#define _apiv1wallettransaction_wallet_H_

#include <string.h>
#include "cJSON.h"
#include "list.h"




typedef struct apiv1wallettransaction_wallet_t {
        list_t *unspents; //primitive container
        list_t *addresses; //primitive container
        char *password; //no enum string
        char *id; //no enum string

} apiv1wallettransaction_wallet_t;

apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet_create(
        list_t *unspents,
        list_t *addresses,
        char *password,
        char *id
);

void apiv1wallettransaction_wallet_free(apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet);

apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet_parseFromJSON(char *jsonString);

cJSON *apiv1wallettransaction_wallet_convertToJSON(apiv1wallettransaction_wallet_t *apiv1wallettransaction_wallet);

#endif /* _apiv1wallettransaction_wallet_H_ */

