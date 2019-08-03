/*
 * inline_response_200_10.h
 *
 * 
 */

#ifndef _inline_response_200_10_H_
#define _inline_response_200_10_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "_api_v1_pending_txs_transaction.h"



typedef struct inline_response_200_10_t {
    _api_v1_pending_txs_transaction_t *transaction; //model
    char *received; // string
    char *checked; // string
    char *announced; // string
    int is_valid; //boolean

} inline_response_200_10_t;

inline_response_200_10_t *inline_response_200_10_create(
    _api_v1_pending_txs_transaction_t *transaction,
    char *received,
    char *checked,
    char *announced,
    int is_valid
);

void inline_response_200_10_free(inline_response_200_10_t *inline_response_200_10);

inline_response_200_10_t *inline_response_200_10_parseFromJSON(cJSON *inline_response_200_10JSON);

cJSON *inline_response_200_10_convertToJSON(inline_response_200_10_t *inline_response_200_10);

#endif /* _inline_response_200_10_H_ */

