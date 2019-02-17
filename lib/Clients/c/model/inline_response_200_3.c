#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "inline_response_200_3.h"
#include "inline_response_200_3_unconfirmed_verify_transaction.h"

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
}

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
    ) {
	inline_response_200_3_t *inline_response_200_3 = malloc(sizeof(inline_response_200_3_t));
	inline_response_200_3->last_received = last_received;
	inline_response_200_3->last_sent = last_sent;
	inline_response_200_3->outgoing = outgoing;
	inline_response_200_3->mirror = mirror;
	inline_response_200_3->address = address;
	inline_response_200_3->listen_port = listen_port;
	inline_response_200_3->is_trusted_peer = is_trusted_peer;
	inline_response_200_3->connected_at = connected_at;
	inline_response_200_3->unconfirmed_verify_transaction = unconfirmed_verify_transaction;
	inline_response_200_3->id = id;
	inline_response_200_3->state = state;
	inline_response_200_3->user_agent = user_agent;
	inline_response_200_3->height = height;

	return inline_response_200_3;
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
    if(cJSON_AddNumberToObject(item, "last_received", inline_response_200_3->last_received) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->last_sent
    if(cJSON_AddNumberToObject(item, "last_sent", inline_response_200_3->last_sent) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->outgoing
    if(cJSON_AddBoolToObject(item, "outgoing", inline_response_200_3->outgoing) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->mirror
    if(cJSON_AddNumberToObject(item, "mirror", inline_response_200_3->mirror) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->address
    if(cJSON_AddStringToObject(item, "address", inline_response_200_3->address) == NULL) {
    goto fail; //String
    }

	// inline_response_200_3->listen_port
    if(cJSON_AddNumberToObject(item, "listen_port", inline_response_200_3->listen_port) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->is_trusted_peer
    if(cJSON_AddBoolToObject(item, "is_trusted_peer", inline_response_200_3->is_trusted_peer) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->connected_at
    if(cJSON_AddNumberToObject(item, "connected_at", inline_response_200_3->connected_at) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->unconfirmed_verify_transaction
	cJSON *unconfirmed_verify_transaction = inline_response_200_3_unconfirmed_verify_transaction_convertToJSON(inline_response_200_3->unconfirmed_verify_transaction);
	if(unconfirmed_verify_transaction == NULL) {
		goto fail; //nonprimitive
	}
	cJSON_AddItemToObject(item, "unconfirmed_verify_transaction", unconfirmed_verify_transaction);
	if(item->child == NULL) {
		goto fail;
	}

	// inline_response_200_3->id
    if(cJSON_AddNumberToObject(item, "id", inline_response_200_3->id) == NULL) {
    goto fail; //Numeric
    }

	// inline_response_200_3->state
    if(cJSON_AddStringToObject(item, "state", stateinline_response_200_3_ToString(inline_response_200_3->state)) == NULL) {
    goto fail; //String
    }

	// inline_response_200_3->user_agent
    if(cJSON_AddStringToObject(item, "user_agent", inline_response_200_3->user_agent) == NULL) {
    goto fail; //String
    }

	// inline_response_200_3->height
    if(cJSON_AddNumberToObject(item, "height", inline_response_200_3->height) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

inline_response_200_3_t *inline_response_200_3_parseFromJSON(char *jsonString){

    inline_response_200_3_t *inline_response_200_3 = NULL;
    cJSON *inline_response_200_3JSON = cJSON_Parse(jsonString);
    if(inline_response_200_3JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // inline_response_200_3->last_received
    cJSON *last_received = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "last_received");
    if(!cJSON_IsNumber(last_received))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->last_sent
    cJSON *last_sent = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "last_sent");
    if(!cJSON_IsNumber(last_sent))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->outgoing
    cJSON *outgoing = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "outgoing");
    if(!cJSON_IsBool(outgoing))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->mirror
    cJSON *mirror = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "mirror");
    if(!cJSON_IsNumber(mirror))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "address");
    if(!cJSON_IsString(address) || (address->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_3->listen_port
    cJSON *listen_port = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "listen_port");
    if(!cJSON_IsNumber(listen_port))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->is_trusted_peer
    cJSON *is_trusted_peer = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "is_trusted_peer");
    if(!cJSON_IsBool(is_trusted_peer))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->connected_at
    cJSON *connected_at = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "connected_at");
    if(!cJSON_IsNumber(connected_at))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->unconfirmed_verify_transaction
    inline_response_200_3_unconfirmed_verify_transaction_t *unconfirmed_verify_transaction;
    cJSON *unconfirmed_verify_transactionJSON = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "unconfirmed_verify_transaction");
    if(inline_response_200_3JSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
            fprintf(stderr, "Error Before: %s\n", error_ptr);
        goto end; //nonprimitive
    }
    char *unconfirmed_verify_transactionJSONData = cJSON_Print(unconfirmed_verify_transactionJSON);
    unconfirmed_verify_transaction = inline_response_200_3_unconfirmed_verify_transaction_parseFromJSON(unconfirmed_verify_transactionJSONData);

    // inline_response_200_3->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "id");
    if(!cJSON_IsNumber(id))
    {
    goto end; //Numeric
    }

    // inline_response_200_3->state
    state_e stateVariable;
    cJSON *state = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "state");
    if(!cJSON_IsString(state) || (state->valuestring == NULL)){
    goto end; //String
    }

    stateVariable = stateinline_response_200_3_FromString(state->valuestring);

    // inline_response_200_3->user_agent
    cJSON *user_agent = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "user_agent");
    if(!cJSON_IsString(user_agent) || (user_agent->valuestring == NULL)){
    goto end; //String
    }

    // inline_response_200_3->height
    cJSON *height = cJSON_GetObjectItemCaseSensitive(inline_response_200_3JSON, "height");
    if(!cJSON_IsNumber(height))
    {
    goto end; //Numeric
    }


    inline_response_200_3 = inline_response_200_3_create (
        last_received->valuedouble,
        last_sent->valuedouble,
        outgoing->valueint,
        mirror->valuedouble,
        strdup(address->valuestring),
        listen_port->valuedouble,
        is_trusted_peer->valueint,
        connected_at->valuedouble,
        unconfirmed_verify_transaction,
        id->valuedouble,
        stateVariable,
        strdup(user_agent->valuestring),
        height->valuedouble
        );
        free(unconfirmed_verify_transactionJSONData);
 cJSON_Delete(inline_response_200_3JSON);
    return inline_response_200_3;
end:
    cJSON_Delete(inline_response_200_3JSON);
    return NULL;

}

