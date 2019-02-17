/*
 * apiv1wallets_meta.h
 *
 * 
 */

#ifndef _apiv1wallets_meta_H_
#define _apiv1wallets_meta_H_

#include <string.h>
#include "cJSON.h"

typedef int bool;
#define true 1
#define false 0



typedef struct apiv1wallets_meta_t {
        char *filename; //no enum string
        bool encrypted; //boolean
        char *crypto_type; //no enum string
        char *label; //no enum string
        char *type; //no enum string
        char *version; //no enum string
        char *coin; //no enum string
        int timestamp; //numeric

} apiv1wallets_meta_t;

apiv1wallets_meta_t *apiv1wallets_meta_create(
        char *filename,
        bool encrypted,
        char *crypto_type,
        char *label,
        char *type,
        char *version,
        char *coin,
        int timestamp
);

void apiv1wallets_meta_free(apiv1wallets_meta_t *apiv1wallets_meta);

apiv1wallets_meta_t *apiv1wallets_meta_parseFromJSON(char *jsonString);

cJSON *apiv1wallets_meta_convertToJSON(apiv1wallets_meta_t *apiv1wallets_meta);

#endif /* _apiv1wallets_meta_H_ */

