/*
 * multi_key_data.h
 *
 * 
 */

#ifndef _multi_key_data_H_
#define _multi_key_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "multi_key_data_key2.h"



typedef struct multi_key_data_t {
    char *key1; // string
    multi_key_data_key2_t *key2; //model

} multi_key_data_t;

multi_key_data_t *multi_key_data_create(
    char *key1,
    multi_key_data_key2_t *key2
);

void multi_key_data_free(multi_key_data_t *multi_key_data);

multi_key_data_t *multi_key_data_parseFromJSON(cJSON *multi_key_dataJSON);

cJSON *multi_key_data_convertToJSON(multi_key_data_t *multi_key_data);

#endif /* _multi_key_data_H_ */

