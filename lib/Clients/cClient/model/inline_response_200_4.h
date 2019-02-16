/*
 * inline_response_200_4.h
 *
 * 
 */

#ifndef _inline_response_200_4_H_
#define _inline_response_200_4_H_

#include <string.h>
#include "cJSON.h"
#include "apiv1pending_txs_transaction.h"

typedef int bool;
#define true 1
#define false 0



typedef struct inline_response_200_4_t {
        char *announced; //no enum string
        bool is_valid; //boolean
        char *checked; //no enum string
        char *received; //no enum string
        apiv1pending_txs_transaction_t *transaction; //nonprimitive

} inline_response_200_4_t;

inline_response_200_4_t *inline_response_200_4_create(
        char *announced,
        bool is_valid,
        char *checked,
        char *received,
        apiv1pending_txs_transaction_t *transaction
);

void inline_response_200_4_free(inline_response_200_4_t *inline_response_200_4);

inline_response_200_4_t *inline_response_200_4_parseFromJSON(char *jsonString);

cJSON *inline_response_200_4_convertToJSON(inline_response_200_4_t *inline_response_200_4);

#endif /* _inline_response_200_4_H_ */

