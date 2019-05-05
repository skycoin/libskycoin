/*
 * inline_response_200_4.h
 *
 * 
 */

#ifndef _inline_response_200_4_H_
#define _inline_response_200_4_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_pending_txs_transaction.h"



typedef struct inline_response_200_4_t {
    char *announced; // string
    int is_valid; //boolean
    char *checked; // string
    char *received; // string
    _api_v1_pending_txs_transaction_t *transaction; //model

} inline_response_200_4_t;

inline_response_200_4_t *inline_response_200_4_create(
    char *announced,
    int is_valid,
    char *checked,
    char *received,
    _api_v1_pending_txs_transaction_t *transaction
);

void inline_response_200_4_free(inline_response_200_4_t *inline_response_200_4);

inline_response_200_4_t *inline_response_200_4_parseFromJSON(cJSON *inline_response_200_4JSON);

cJSON *inline_response_200_4_convertToJSON(inline_response_200_4_t *inline_response_200_4);

#endif /* _inline_response_200_4_H_ */

