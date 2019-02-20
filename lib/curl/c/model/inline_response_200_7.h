/*
 * inline_response_200_7.h
 *
 * 
 */

#ifndef _inline_response_200_7_H_
#define _inline_response_200_7_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1wallets_entries.h"
#include "apiv1wallets_meta.h"
#include "list.h"




typedef struct inline_response_200_7_t {
        list_t *entries; //nonprimitive container
        apiv1wallets_meta_t *meta; //nonprimitive

} inline_response_200_7_t;

inline_response_200_7_t *inline_response_200_7_create(
        list_t *entries,
        apiv1wallets_meta_t *meta
);

void inline_response_200_7_free(inline_response_200_7_t *inline_response_200_7);

inline_response_200_7_t *inline_response_200_7_parseFromJSON(char *jsonString);

cJSON *inline_response_200_7_convertToJSON(inline_response_200_7_t *inline_response_200_7);

#endif /* _inline_response_200_7_H_ */

