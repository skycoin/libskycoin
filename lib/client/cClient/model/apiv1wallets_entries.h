/*
 * apiv1wallets_entries.h
 *
 * 
 */

#ifndef _apiv1wallets_entries_H_
#define _apiv1wallets_entries_H_

#include <string.h>
#include "cJSON.h"




typedef struct apiv1wallets_entries_t {
        char *public_key; //no enum string
        char *address; //no enum string

} apiv1wallets_entries_t;

apiv1wallets_entries_t *apiv1wallets_entries_create(
        char *public_key,
        char *address
);

void apiv1wallets_entries_free(apiv1wallets_entries_t *apiv1wallets_entries);

apiv1wallets_entries_t *apiv1wallets_entries_parseFromJSON(char *jsonString);

cJSON *apiv1wallets_entries_convertToJSON(apiv1wallets_entries_t *apiv1wallets_entries);

#endif /* _apiv1wallets_entries_H_ */

