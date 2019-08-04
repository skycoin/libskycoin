/*
 * pin_matrix_request.h
 *
 * 
 */

#ifndef _pin_matrix_request_H_
#define _pin_matrix_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct pin_matrix_request_t {
    char *pin; // string

} pin_matrix_request_t;

pin_matrix_request_t *pin_matrix_request_create(
    char *pin
);

void pin_matrix_request_free(pin_matrix_request_t *pin_matrix_request);

pin_matrix_request_t *pin_matrix_request_parseFromJSON(cJSON *pin_matrix_requestJSON);

cJSON *pin_matrix_request_convertToJSON(pin_matrix_request_t *pin_matrix_request);

#endif /* _pin_matrix_request_H_ */

