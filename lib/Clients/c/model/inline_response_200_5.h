/*
 * inline_response_200_5.h
 *
 * 
 */

#ifndef _inline_response_200_5_H_
#define _inline_response_200_5_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1transactions_txn.h"
#include "apiv1transactions_txn_status.h"




typedef struct inline_response_200_5_t {
        long time; //numeric
        apiv1transactions_txn_t *txn; //nonprimitive
        apiv1transactions_txn_status_t *status; //nonprimitive

} inline_response_200_5_t;

inline_response_200_5_t *inline_response_200_5_create(
        long time,
        apiv1transactions_txn_t *txn,
        apiv1transactions_txn_status_t *status
);

void inline_response_200_5_free(inline_response_200_5_t *inline_response_200_5);

inline_response_200_5_t *inline_response_200_5_parseFromJSON(char *jsonString);

cJSON *inline_response_200_5_convertToJSON(inline_response_200_5_t *inline_response_200_5);

#endif /* _inline_response_200_5_H_ */

