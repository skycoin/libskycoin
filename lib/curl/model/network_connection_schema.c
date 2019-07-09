#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_connection_schema.h"


    char* statenetwork_connection_schema_ToString(state_e state){
    char *stateArray[] =  { "pending","connected","introduced" };
        return stateArray[state];
    }

    state_e statenetwork_connection_schema_FromString(char* state){
    int stringToReturn = 0;
    char *stateArray[] =  { "pending","connected","introduced" };
    size_t sizeofArray = sizeof(stateArray) / sizeof(stateArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(state, stateArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
    }

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
    ) {
	network_connection_schema_t *network_connection_schema_local_var = malloc(sizeof(network_connection_schema_t));
    if (!network_connection_schema_local_var) {
        return NULL;
    }
	network_connection_schema_local_var->address = address;
	network_connection_schema_local_var->connected_at = connected_at;
	network_connection_schema_local_var->height = height;
	network_connection_schema_local_var->id = id;
	network_connection_schema_local_var->is_trusted_peer = is_trusted_peer;
	network_connection_schema_local_var->last_received = last_received;
	network_connection_schema_local_var->last_sent = last_sent;
	network_connection_schema_local_var->listen_port = listen_port;
	network_connection_schema_local_var->mirror = mirror;
	network_connection_schema_local_var->outgoing = outgoing;
	network_connection_schema_local_var->state = state;
	network_connection_schema_local_var->unconfirmed_verify_transaction = unconfirmed_verify_transaction;
	network_connection_schema_local_var->user_agent = user_agent;

	return network_connection_schema_local_var;
}


void network_connection_schema_free(network_connection_schema_t *network_connection_schema) {
    listEntry_t *listEntry;
    free(network_connection_schema->address);
    network_connection_schema_unconfirmed_verify_transaction_free(network_connection_schema->unconfirmed_verify_transaction);
    free(network_connection_schema->user_agent);
	free(network_connection_schema);
}

cJSON *network_connection_schema_convertToJSON(network_connection_schema_t *network_connection_schema) {
	cJSON *item = cJSON_CreateObject();

	// network_connection_schema->address
    if(network_connection_schema->address) { 
    if(cJSON_AddStringToObject(item, "address", network_connection_schema->address) == NULL) {
    goto fail; //String
    }
     } 


	// network_connection_schema->connected_at
    if(network_connection_schema->connected_at) { 
    if(cJSON_AddNumberToObject(item, "connected_at", network_connection_schema->connected_at) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->height
    if(network_connection_schema->height) { 
    if(cJSON_AddNumberToObject(item, "height", network_connection_schema->height) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->id
    if(network_connection_schema->id) { 
    if(cJSON_AddNumberToObject(item, "id", network_connection_schema->id) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->is_trusted_peer
    if(network_connection_schema->is_trusted_peer) { 
    if(cJSON_AddBoolToObject(item, "is_trusted_peer", network_connection_schema->is_trusted_peer) == NULL) {
    goto fail; //Bool
    }
     } 


	// network_connection_schema->last_received
    if(network_connection_schema->last_received) { 
    if(cJSON_AddNumberToObject(item, "last_received", network_connection_schema->last_received) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->last_sent
    if(network_connection_schema->last_sent) { 
    if(cJSON_AddNumberToObject(item, "last_sent", network_connection_schema->last_sent) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->listen_port
    if(network_connection_schema->listen_port) { 
    if(cJSON_AddNumberToObject(item, "listen_port", network_connection_schema->listen_port) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->mirror
    if(network_connection_schema->mirror) { 
    if(cJSON_AddNumberToObject(item, "mirror", network_connection_schema->mirror) == NULL) {
    goto fail; //Numeric
    }
     } 


	// network_connection_schema->outgoing
    if(network_connection_schema->outgoing) { 
    if(cJSON_AddBoolToObject(item, "outgoing", network_connection_schema->outgoing) == NULL) {
    goto fail; //Bool
    }
     } 


	// network_connection_schema->state
    
    if(cJSON_AddStringToObject(item, "state", statenetwork_connection_schema_ToString(network_connection_schema->state)) == NULL)
    {
    goto fail; //Enum
    }
    


	// network_connection_schema->unconfirmed_verify_transaction
    if(network_connection_schema->unconfirmed_verify_transaction) { 
    cJSON *unconfirmed_verify_transaction_local_JSON = network_connection_schema_unconfirmed_verify_transaction_convertToJSON(network_connection_schema->unconfirmed_verify_transaction);
    if(unconfirmed_verify_transaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unconfirmed_verify_transaction", unconfirmed_verify_transaction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// network_connection_schema->user_agent
    if(network_connection_schema->user_agent) { 
    if(cJSON_AddStringToObject(item, "user_agent", network_connection_schema->user_agent) == NULL) {
    goto fail; //String
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

network_connection_schema_t *network_connection_schema_parseFromJSON(cJSON *network_connection_schemaJSON){

    network_connection_schema_t *network_connection_schema_local_var = NULL;

    // network_connection_schema->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "address");
    if (address) { 
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }
    }

    // network_connection_schema->connected_at
    cJSON *connected_at = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "connected_at");
    if (connected_at) { 
    if(!cJSON_IsNumber(connected_at))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "height");
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "id");
    if (id) { 
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->is_trusted_peer
    cJSON *is_trusted_peer = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "is_trusted_peer");
    if (is_trusted_peer) { 
    if(!cJSON_IsBool(is_trusted_peer))
    {
    goto end; //Bool
    }
    }

    // network_connection_schema->last_received
    cJSON *last_received = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "last_received");
    if (last_received) { 
    if(!cJSON_IsNumber(last_received))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->last_sent
    cJSON *last_sent = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "last_sent");
    if (last_sent) { 
    if(!cJSON_IsNumber(last_sent))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->listen_port
    cJSON *listen_port = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "listen_port");
    if (listen_port) { 
    if(!cJSON_IsNumber(listen_port))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->mirror
    cJSON *mirror = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "mirror");
    if (mirror) { 
    if(!cJSON_IsNumber(mirror))
    {
    goto end; //Numeric
    }
    }

    // network_connection_schema->outgoing
    cJSON *outgoing = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "outgoing");
    if (outgoing) { 
    if(!cJSON_IsBool(outgoing))
    {
    goto end; //Bool
    }
    }

    // network_connection_schema->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "state");
    state_e stateVariable;
    if (state) { 
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = statenetwork_connection_schema_FromString(state->valuestring);
    }

    // network_connection_schema->unconfirmed_verify_transaction
    cJSON *unconfirmed_verify_transaction = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "unconfirmed_verify_transaction");
    network_connection_schema_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction_local_nonprim = NULL;
    if (unconfirmed_verify_transaction) { 
    unconfirmed_verify_transaction_local_nonprim = network_connection_schema_unconfirmed_verify_transaction_parseFromJSON(unconfirmed_verify_transaction); //nonprimitive
    }

    // network_connection_schema->user_agent
    cJSON *user_agent = cJSON_GetObjectItemCaseSensitive(network_connection_schemaJSON, "user_agent");
    if (user_agent) { 
    if(!cJSON_IsString(user_agent))
    {
    goto end; //String
    }
    }


    network_connection_schema_local_var = network_connection_schema_create (
        address ? strdup(address->valuestring) : NULL,
        connected_at ? connected_at->valuedouble : 0,
        height ? height->valuedouble : 0,
        id ? id->valuedouble : 0,
        is_trusted_peer ? is_trusted_peer->valueint : 0,
        last_received ? last_received->valuedouble : 0,
        last_sent ? last_sent->valuedouble : 0,
        listen_port ? listen_port->valuedouble : 0,
        mirror ? mirror->valuedouble : 0,
        outgoing ? outgoing->valueint : 0,
        state ? stateVariable : -1,
        unconfirmed_verify_transaction ? unconfirmed_verify_transaction_local_nonprim : NULL,
        user_agent ? strdup(user_agent->valuestring) : NULL
        );

    return network_connection_schema_local_var;
end:
    return NULL;

}
