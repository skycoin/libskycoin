#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "inline_response_200_3.h"


    char* stateinline_response_200_3_ToString(state_e state){
    char *stateArray[] =  { "pending","connected","introduced" };
        return stateArray[state];
    }

    state_e stateinline_response_200_3_FromString(char* state){
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
    ) {
	inline_response_200_3_t *inline_response_200_3_local_var = malloc(sizeof(inline_response_200_3_t));
    if (!inline_response_200_3_local_var) {
        return NULL;
    }
	inline_response_200_3_local_var->last_received = last_received;
	inline_response_200_3_local_var->last_sent = last_sent;
	inline_response_200_3_local_var->outgoing = outgoing;
	inline_response_200_3_local_var->mirror = mirror;
	inline_response_200_3_local_var->address = address;
	inline_response_200_3_local_var->listen_port = listen_port;
	inline_response_200_3_local_var->is_trusted_peer = is_trusted_peer;
	inline_response_200_3_local_var->connected_at = connected_at;
	inline_response_200_3_local_var->unconfirmed_verify_transaction = unconfirmed_verify_transaction;
	inline_response_200_3_local_var->id = id;
	inline_response_200_3_local_var->state = state;
	inline_response_200_3_local_var->user_agent = user_agent;
	inline_response_200_3_local_var->height = height;

	return inline_response_200_3_local_var;
}


void inline_response_200_3_free(inline_response_200_3_t *inline_response_200_3) {
    listEntry_t *listEntry;
    free(inline_response_200_3->address);
    inline_response_200_3_unconfirmed_verify_transaction_free(inline_response_200_3->unconfirmed_verify_transaction);
    free(inline_response_200_3->user_agent);
	free(inline_response_200_3);
}

cJSON *inline_response_200_3_convertToJSON(inline_response_200_3_t *inline_response_200_3) {
	cJSON *item = cJSON_CreateObject();

	// inline_response_200_3->last_received
    if(inline_response_200_3->last_received) { 
    if(cJSON_AddNumberToObject(item, "last_received", inline_response_200_3->last_received) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3->last_sent
    if(inline_response_200_3->last_sent) { 
    if(cJSON_AddNumberToObject(item, "last_sent", inline_response_200_3->last_sent) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3->outgoing
    if(inline_response_200_3->outgoing) { 
    if(cJSON_AddBoolToObject(item, "outgoing", inline_response_200_3->outgoing) == NULL) {
    goto fail; //Bool
    }
     } 


	// inline_response_200_3->mirror
    if(inline_response_200_3->mirror) { 
    if(cJSON_AddNumberToObject(item, "mirror", inline_response_200_3->mirror) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3->address
    if(inline_response_200_3->address) { 
    if(cJSON_AddStringToObject(item, "address", inline_response_200_3->address) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_3->listen_port
    if(inline_response_200_3->listen_port) { 
    if(cJSON_AddNumberToObject(item, "listen_port", inline_response_200_3->listen_port) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3->is_trusted_peer
    if(inline_response_200_3->is_trusted_peer) { 
    if(cJSON_AddBoolToObject(item, "is_trusted_peer", inline_response_200_3->is_trusted_peer) == NULL) {
    goto fail; //Bool
    }
     } 


	// inline_response_200_3->connected_at
    if(inline_response_200_3->connected_at) { 
    if(cJSON_AddNumberToObject(item, "connected_at", inline_response_200_3->connected_at) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3->unconfirmed_verify_transaction
    if(inline_response_200_3->unconfirmed_verify_transaction) { 
    cJSON *unconfirmed_verify_transaction_local_JSON = inline_response_200_3_unconfirmed_verify_transaction_convertToJSON(inline_response_200_3->unconfirmed_verify_transaction);
    if(unconfirmed_verify_transaction_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "unconfirmed_verify_transaction", unconfirmed_verify_transaction_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


	// inline_response_200_3->id
    if(inline_response_200_3->id) { 
    if(cJSON_AddNumberToObject(item, "id", inline_response_200_3->id) == NULL) {
    goto fail; //Numeric
    }
     } 


	// inline_response_200_3->state
    
    if(cJSON_AddStringToObject(item, "state", stateinline_response_200_3_ToString(inline_response_200_3->state)) == NULL)
    {
    goto fail; //Enum
    }
    


	// inline_response_200_3->user_agent
    if(inline_response_200_3->user_agent) { 
    if(cJSON_AddStringToObject(item, "user_agent", inline_response_200_3->user_agent) == NULL) {
    goto fail; //String
    }
     } 


	// inline_response_200_3->height
    if(inline_response_200_3->height) { 
    if(cJSON_AddNumberToObject(item, "height", inline_response_200_3->height) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

inline_response_200_3_t *inline_response_200_3_parseFromJSON(cJSON *inline_response_200_3JSON){

    inline_response_200_3_t *inline_response_200_3_local_var = NULL;

    // inline_response_200_3->last_received
    cJSON *last_received = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "last_received");
    if (last_received) { 
    if(!cJSON_IsNumber(last_received))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3->last_sent
    cJSON *last_sent = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "last_sent");
    if (last_sent) { 
    if(!cJSON_IsNumber(last_sent))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3->outgoing
    cJSON *outgoing = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "outgoing");
    if (outgoing) { 
    if(!cJSON_IsBool(outgoing))
    {
    goto end; //Bool
    }
    }

    // inline_response_200_3->mirror
    cJSON *mirror = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "mirror");
    if (mirror) { 
    if(!cJSON_IsNumber(mirror))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "address");
    if (address) { 
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }
    }

    // inline_response_200_3->listen_port
    cJSON *listen_port = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "listen_port");
    if (listen_port) { 
    if(!cJSON_IsNumber(listen_port))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3->is_trusted_peer
    cJSON *is_trusted_peer = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "is_trusted_peer");
    if (is_trusted_peer) { 
    if(!cJSON_IsBool(is_trusted_peer))
    {
    goto end; //Bool
    }
    }

    // inline_response_200_3->connected_at
    cJSON *connected_at = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "connected_at");
    if (connected_at) { 
    if(!cJSON_IsNumber(connected_at))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3->unconfirmed_verify_transaction
    cJSON *unconfirmed_verify_transaction = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "unconfirmed_verify_transaction");
    inline_response_200_3_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction_local_nonprim = NULL;
    if (unconfirmed_verify_transaction) { 
    unconfirmed_verify_transaction_local_nonprim = inline_response_200_3_unconfirmed_verify_transaction_parseFromJSON(unconfirmed_verify_transaction); //nonprimitive
    }

    // inline_response_200_3->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "id");
    if (id) { 
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }
    }

    // inline_response_200_3->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "state");
    state_e stateVariable;
    if (state) { 
    if(!cJSON_IsString(state))
    {
    goto end; //Enum
    }
    stateVariable = stateinline_response_200_3_FromString(state->valuestring);
    }

    // inline_response_200_3->user_agent
    cJSON *user_agent = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "user_agent");
    if (user_agent) { 
    if(!cJSON_IsString(user_agent))
    {
    goto end; //String
    }
    }

    // inline_response_200_3->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "height");
    if (height) { 
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }
    }


    inline_response_200_3_local_var = inline_response_200_3_create (
        last_received ? last_received->valuedouble : 0,
        last_sent ? last_sent->valuedouble : 0,
        outgoing ? outgoing->valueint : 0,
        mirror ? mirror->valuedouble : 0,
        address ? strdup(address->valuestring) : NULL,
        listen_port ? listen_port->valuedouble : 0,
        is_trusted_peer ? is_trusted_peer->valueint : 0,
        connected_at ? connected_at->valuedouble : 0,
        unconfirmed_verify_transaction ? unconfirmed_verify_transaction_local_nonprim : NULL,
        id ? id->valuedouble : 0,
        state ? stateVariable : -1,
        user_agent ? strdup(user_agent->valuestring) : NULL,
        height ? height->valuedouble : 0
        );

    return inline_response_200_3_local_var;
end:
    return NULL;

}
