/*
 * inline_response_200_1.h
 *
 * 
 */

#ifndef _inline_response_200_1_H_
#define _inline_response_200_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct inline_response_200_1_t {
    char *current_coinhour_supply; // string
    char *current_supply; // string
    list_t *locked_distribution_addresses; //primitive container
    char *max_supply; // string
    char *total_coinhour_supply; // string
    char *total_supply; // string
    list_t *unlocked_distribution_addresses; //primitive container

} inline_response_200_1_t;

inline_response_200_1_t *inline_response_200_1_create(
    char *current_coinhour_supply,
    char *current_supply,
    list_t *locked_distribution_addresses,
    char *max_supply,
    char *total_coinhour_supply,
    char *total_supply,
    list_t *unlocked_distribution_addresses
);

void inline_response_200_1_free(inline_response_200_1_t *inline_response_200_1);

inline_response_200_1_t *inline_response_200_1_parseFromJSON(cJSON *inline_response_200_1JSON);

cJSON *inline_response_200_1_convertToJSON(inline_response_200_1_t *inline_response_200_1);

#endif /* _inline_response_200_1_H_ */

