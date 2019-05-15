/*
 * inline_response_200_3_unconfirmed_verify_transaction.h
 *
 * Represent unconfirmed transactions
 */

#ifndef _inline_response_200_3_unconfirmed_verify_transaction_H_
#define _inline_response_200_3_unconfirmed_verify_transaction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_3_unconfirmed_verify_transaction_t {
    int burn_factor; //numeric
    int max_transaction_size; //numeric
    int max_decimals; //numeric

} inline_response_200_3_unconfirmed_verify_transaction_t;

inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_create(
    int burn_factor,
    int max_transaction_size,
    int max_decimals
);

void inline_response_200_3_unconfirmed_verify_transaction_free(inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction);

inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction_parseFromJSON(cJSON *inline_response_200_3_unconfirmed_verify_transactionJSON);

cJSON *inline_response_200_3_unconfirmed_verify_transaction_convertToJSON(inline_response_200_3_unconfirmed_verify_transaction_t *inline_response_200_3_unconfirmed_verify_transaction);

#endif /* _inline_response_200_3_unconfirmed_verify_transaction_H_ */

