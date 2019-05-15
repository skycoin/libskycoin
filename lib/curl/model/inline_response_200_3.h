/*
 * inline_response_200_3.h
 *
 * 
 */

#ifndef _inline_response_200_3_H_
#define _inline_response_200_3_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "inline_response_200_3_unconfirmed_verify_transaction.h"

                typedef enum  {  pending, connected, introduced } state_e;

        char* state_ToString(state_e state);

        state_e state_FromString(char* state);


typedef struct inline_response_200_3_t {
    long last_received; //numeric
    long last_sent; //numeric
    int outgoing; //boolean
    int mirror; //numeric
    char *address; // string
    int listen_port; //numeric
    int is_trusted_peer; //boolean
    long connected_at; //numeric
    inline_response_200_3_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction; //model
    long id; //numeric
    state_e state; //enum
    char *user_agent; // string
    long height; //numeric

} inline_response_200_3_t;

inline_response_200_3_t *inline_response_200_3_create(
    long last_received,
    long last_sent,
    int outgoing,
    int mirror,
    char *address,
    int listen_port,
    int is_trusted_peer,
    long connected_at,
    inline_response_200_3_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction,
    long id,
    state_e state,
    char *user_agent,
    long height
);

void inline_response_200_3_free(inline_response_200_3_t *inline_response_200_3);

inline_response_200_3_t *inline_response_200_3_parseFromJSON(cJSON *inline_response_200_3JSON);

cJSON *inline_response_200_3_convertToJSON(inline_response_200_3_t *inline_response_200_3);

#endif /* _inline_response_200_3_H_ */

