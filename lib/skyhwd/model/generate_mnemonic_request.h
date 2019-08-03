/*
 * generate_mnemonic_request.h
 *
 * 
 */

#ifndef _generate_mnemonic_request_H_
#define _generate_mnemonic_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct generate_mnemonic_request_t {
    int word_count; //numeric
    int use_passphrase; //boolean

} generate_mnemonic_request_t;

generate_mnemonic_request_t *generate_mnemonic_request_create(
    int word_count,
    int use_passphrase
);

void generate_mnemonic_request_free(generate_mnemonic_request_t *generate_mnemonic_request);

generate_mnemonic_request_t *generate_mnemonic_request_parseFromJSON(cJSON *generate_mnemonic_requestJSON);

cJSON *generate_mnemonic_request_convertToJSON(generate_mnemonic_request_t *generate_mnemonic_request);

#endif /* _generate_mnemonic_request_H_ */

