/*
 * _api_v1_wallets_meta.h
 *
 * 
 */

#ifndef __api_v1_wallets_meta_H_
#define __api_v1_wallets_meta_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct _api_v1_wallets_meta_t {
    char *filename; // string
    int encrypted; //boolean
    char *crypto_type; // string
    char *label; // string
    char *type; // string
    char *version; // string
    char *coin; // string
    int timestamp; //numeric

} _api_v1_wallets_meta_t;

_api_v1_wallets_meta_t *_api_v1_wallets_meta_create(
    char *filename,
    int encrypted,
    char *crypto_type,
    char *label,
    char *type,
    char *version,
    char *coin,
    int timestamp
);

void _api_v1_wallets_meta_free(_api_v1_wallets_meta_t *_api_v1_wallets_meta);

_api_v1_wallets_meta_t *_api_v1_wallets_meta_parseFromJSON(cJSON *_api_v1_wallets_metaJSON);

cJSON *_api_v1_wallets_meta_convertToJSON(_api_v1_wallets_meta_t *_api_v1_wallets_meta);

#endif /* __api_v1_wallets_meta_H_ */

