/*
 * generate_addresses_request.h
 *
 * 
 */

#ifndef _generate_addresses_request_H_
#define _generate_addresses_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct generate_addresses_request_t {
    int address_n; //numeric
    int start_index; //numeric
    int confirm_address; //boolean

} generate_addresses_request_t;

generate_addresses_request_t *generate_addresses_request_create(
    int address_n,
    int start_index,
    int confirm_address
);

void generate_addresses_request_free(generate_addresses_request_t *generate_addresses_request);

generate_addresses_request_t *generate_addresses_request_parseFromJSON(cJSON *generate_addresses_requestJSON);

cJSON *generate_addresses_request_convertToJSON(generate_addresses_request_t *generate_addresses_request);

#endif /* _generate_addresses_request_H_ */

