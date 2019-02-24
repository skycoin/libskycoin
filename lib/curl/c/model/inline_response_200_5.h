/*
 * inline_response_200_5.h
 *
 * 
 */

#ifndef _inline_response_200_5_H_
#define _inline_response_200_5_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1wallets_entries.h"
#include "apiv1wallets_meta.h"
#include "list.h"




typedef struct inline_response_200_5_t {
        list_t *entries; //nonprimitive container
        apiv1wallets_meta_t *meta; //nonprimitive

} inline_response_200_5_t;

inline_response_200_5_t *inline_response_200_5_create(
        list_t *entries,
        apiv1wallets_meta_t *meta
);

void inline_response_200_5_free(inline_response_200_5_t *inline_response_200_5);

inline_response_200_5_t *inline_response_200_5_parseFromJSON(char *jsonString);

cJSON *inline_response_200_5_convertToJSON(inline_response_200_5_t *inline_response_200_5);

#endif /* _inline_response_200_5_H_ */

