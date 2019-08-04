/*
 * word_request.h
 *
 * 
 */

#ifndef _word_request_H_
#define _word_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct word_request_t {
    char *word; // string

} word_request_t;

word_request_t *word_request_create(
    char *word
);

void word_request_free(word_request_t *word_request);

word_request_t *word_request_parseFromJSON(cJSON *word_requestJSON);

cJSON *word_request_convertToJSON(word_request_t *word_request);

#endif /* _word_request_H_ */

