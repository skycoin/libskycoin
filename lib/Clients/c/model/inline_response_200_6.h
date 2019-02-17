/*
 * inline_response_200_6.h
 *
 * 
 */

#ifndef _inline_response_200_6_H_
#define _inline_response_200_6_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1wallets_entries.h"
#include "apiv1wallets_meta.h"
#include "list.h"




typedef struct inline_response_200_6_t {
        list_t *entries; //nonprimitive container
        apiv1wallets_meta_t *meta; //nonprimitive

} inline_response_200_6_t;

inline_response_200_6_t *inline_response_200_6_create(
        list_t *entries,
        apiv1wallets_meta_t *meta
);

void inline_response_200_6_free(inline_response_200_6_t *inline_response_200_6);

inline_response_200_6_t *inline_response_200_6_parseFromJSON(char *jsonString);

cJSON *inline_response_200_6_convertToJSON(inline_response_200_6_t *inline_response_200_6);

#endif /* _inline_response_200_6_H_ */

