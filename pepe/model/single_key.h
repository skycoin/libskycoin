/*
 * single_key.h
 *
 * 
 */

#ifndef _single_key_H_
#define _single_key_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct single_key_t {
    char *data; // string

} single_key_t;

single_key_t *single_key_create(
    char *data
);

void single_key_free(single_key_t *single_key);

single_key_t *single_key_parseFromJSON(cJSON *single_keyJSON);

cJSON *single_key_convertToJSON(single_key_t *single_key);

#endif /* _single_key_H_ */

