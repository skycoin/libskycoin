/*
 * address.h
 *
 * 
 */

#ifndef _address_H_
#define _address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct address_t {
    char *address; // string

} address_t;

address_t *address_create(
    char *address
);

void address_free(address_t *address);

address_t *address_parseFromJSON(cJSON *addressJSON);

cJSON *address_convertToJSON(address_t *address);

#endif /* _address_H_ */

