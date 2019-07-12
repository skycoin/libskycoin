/*
 * network_connection_schema.h
 *
 * 
 */

#ifndef _network_connection_schema_H_
#define _network_connection_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "network_connection_schema_unconfirmed_verify_transaction.h"

                typedef enum  {  pending, connected, introduced } state_e;

        char* state_ToString(state_e state);

        state_e state_FromString(char* state);


typedef struct network_connection_schema_t {
    char *address; // string
    long connected_at; //numeric
    long height; //numeric
    long id; //numeric
    int is_trusted_peer; //boolean
    long last_received; //numeric
    long last_sent; //numeric
    int listen_port; //numeric
    int mirror; //numeric
    int outgoing; //boolean
    state_e state; //enum
    network_connection_schema_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction; //model
    char *user_agent; // string

} network_connection_schema_t;

network_connection_schema_t *network_connection_schema_create(
    char *address,
    long connected_at,
    long height,
    long id,
    int is_trusted_peer,
    long last_received,
    long last_sent,
    int listen_port,
    int mirror,
    int outgoing,
    state_e state,
    network_connection_schema_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction,
    char *user_agent
);

void network_connection_schema_free(network_connection_schema_t *network_connection_schema);

network_connection_schema_t *network_connection_schema_parseFromJSON(cJSON *network_connection_schemaJSON);

cJSON *network_connection_schema_convertToJSON(network_connection_schema_t *network_connection_schema);

#endif /* _network_connection_schema_H_ */

