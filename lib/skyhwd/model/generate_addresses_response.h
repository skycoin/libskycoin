/*
 * generate_addresses_response.h
 *
 * 
 */

#ifndef _generate_addresses_response_H_
#define _generate_addresses_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct generate_addresses_response_t {
    list_t *data; //primitive container

} generate_addresses_response_t;

generate_addresses_response_t *generate_addresses_response_create(
    list_t *data
);

void generate_addresses_response_free(generate_addresses_response_t *generate_addresses_response);

generate_addresses_response_t *generate_addresses_response_parseFromJSON(cJSON *generate_addresses_responseJSON);

cJSON *generate_addresses_response_convertToJSON(generate_addresses_response_t *generate_addresses_response);

#endif /* _generate_addresses_response_H_ */

