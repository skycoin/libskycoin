/*
 * inline_response_200_5.h
 *
 * 
 */

#ifndef _inline_response_200_5_H_
#define _inline_response_200_5_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_wallets_entries.h"
#include "_api_v1_wallets_meta.h"



typedef struct inline_response_200_5_t {
    list_t *entries; //nonprimitive container
    _api_v1_wallets_meta_t *meta; //model

} inline_response_200_5_t;

inline_response_200_5_t *inline_response_200_5_create(
    list_t *entries,
    _api_v1_wallets_meta_t *meta
);

void inline_response_200_5_free(inline_response_200_5_t *inline_response_200_5);

inline_response_200_5_t *inline_response_200_5_parseFromJSON(cJSON *inline_response_200_5JSON);

cJSON *inline_response_200_5_convertToJSON(inline_response_200_5_t *inline_response_200_5);

#endif /* _inline_response_200_5_H_ */

