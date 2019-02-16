/*
 * inline_response_200_3.h
 *
 * 
 */

#ifndef _inline_response_200_3_H_
#define _inline_response_200_3_H_

#include <string.h>
#include "cJSON.h"
#include "inline_response_200_3_unconfirmed_verify_transaction.h"

typedef int bool;
#define true 1
#define false 0
typedef int bool;
#define true 1
#define false 0

typedef enum  {  pending, connected, introduced } state_e;

char* stateinline_response_200_3_ToString(state_e state);

state_e stateinline_response_200_3_FromString(char* state);

typedef struct inline_response_200_3_t {
        long last_received; //numeric
        long last_sent; //numeric
        bool outgoing; //boolean
        int mirror; //numeric
        char *address; //no enum string
        int listen_port; //numeric
        bool is_trusted_peer; //boolean
        long connected_at; //numeric
        inline_response_200_3_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction; //nonprimitive
        long id; //numeric
        state_e state; //enum string
        char *user_agent; //no enum string
        long height; //numeric

} inline_response_200_3_t;

inline_response_200_3_t *inline_response_200_3_create(
        long last_received,
        long last_sent,
        bool outgoing,
        int mirror,
        char *address,
        int listen_port,
        bool is_trusted_peer,
        long connected_at,
        inline_response_200_3_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction,
        long id,
        state_e state,
        char *user_agent,
        long height
);

void inline_response_200_3_free(inline_response_200_3_t *inline_response_200_3);

inline_response_200_3_t *inline_response_200_3_parseFromJSON(char *jsonString);

cJSON *inline_response_200_3_convertToJSON(inline_response_200_3_t *inline_response_200_3);

#endif /* _inline_response_200_3_H_ */

