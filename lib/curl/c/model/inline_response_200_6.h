/*
 * inline_response_200_6.h
 *
 * 
 */

#ifndef _inline_response_200_6_H_
#define _inline_response_200_6_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1transactionsverbose_txn.h"
#include "apiv1transactionsverbose_txn_status.h"




typedef struct inline_response_200_6_t {
        long time; //numeric
        apiv1transactionsverbose_txn_t *txn; //nonprimitive
        apiv1transactionsverbose_txn_status_t *status; //nonprimitive

} inline_response_200_6_t;

inline_response_200_6_t *inline_response_200_6_create(
        long time,
        apiv1transactionsverbose_txn_t *txn,
        apiv1transactionsverbose_txn_status_t *status
);

void inline_response_200_6_free(inline_response_200_6_t *inline_response_200_6);

inline_response_200_6_t *inline_response_200_6_parseFromJSON(char *jsonString);

cJSON *inline_response_200_6_convertToJSON(inline_response_200_6_t *inline_response_200_6);

#endif /* _inline_response_200_6_H_ */

