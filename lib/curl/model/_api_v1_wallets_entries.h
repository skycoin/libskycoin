/*
 * _api_v1_wallets_entries.h
 *
 * 
 */

#ifndef __api_v1_wallets_entries_H_
#define __api_v1_wallets_entries_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_wallets_entries_t {
    char *public_key; // string
    char *address; // string

} _api_v1_wallets_entries_t;

_api_v1_wallets_entries_t *_api_v1_wallets_entries_create(
    char *public_key,
    char *address
);

void _api_v1_wallets_entries_free(_api_v1_wallets_entries_t *_api_v1_wallets_entries);

_api_v1_wallets_entries_t *_api_v1_wallets_entries_parseFromJSON(cJSON *_api_v1_wallets_entriesJSON);

cJSON *_api_v1_wallets_entries_convertToJSON(_api_v1_wallets_entries_t *_api_v1_wallets_entries);

#endif /* __api_v1_wallets_entries_H_ */

