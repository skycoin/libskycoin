/*
 * multi_key.h
 *
 * 
 */

#ifndef _multi_key_H_
#define _multi_key_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "multi_key_data.h"



typedef struct multi_key_t {
    multi_key_data_t *data; //model

} multi_key_t;

multi_key_t *multi_key_create(
    multi_key_data_t *data
);

void multi_key_free(multi_key_t *multi_key);

multi_key_t *multi_key_parseFromJSON(cJSON *multi_keyJSON);

cJSON *multi_key_convertToJSON(multi_key_t *multi_key);

#endif /* _multi_key_H_ */

