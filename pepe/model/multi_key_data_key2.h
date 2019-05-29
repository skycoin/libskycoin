/*
 * multi_key_data_key2.h
 *
 * 
 */

#ifndef _multi_key_data_key2_H_
#define _multi_key_data_key2_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct multi_key_data_key2_t {
    char *key; // string

} multi_key_data_key2_t;

multi_key_data_key2_t *multi_key_data_key2_create(
    char *key
);

void multi_key_data_key2_free(multi_key_data_key2_t *multi_key_data_key2);

multi_key_data_key2_t *multi_key_data_key2_parseFromJSON(cJSON *multi_key_data_key2JSON);

cJSON *multi_key_data_key2_convertToJSON(multi_key_data_key2_t *multi_key_data_key2);

#endif /* _multi_key_data_key2_H_ */

