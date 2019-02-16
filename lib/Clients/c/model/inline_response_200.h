/*
 * inline_response_200.h
 *
 * 
 */

#ifndef _inline_response_200_H_
#define _inline_response_200_H_

#include <string.h>
#include "cJSON.h"




typedef struct inline_response_200_t {
        long hours; //numeric
        int coins; //numeric
        char *uxid; //no enum string
        char *owner_address; //no enum string
        int spent_block_seq; //numeric
        char *spent_tx; //no enum string
        long time; //numeric
        long src_block_seq; //numeric
        char *src_tx; //no enum string

} inline_response_200_t;

inline_response_200_t *inline_response_200_create(
        long hours,
        int coins,
        char *uxid,
        char *owner_address,
        int spent_block_seq,
        char *spent_tx,
        long time,
        long src_block_seq,
        char *src_tx
);

void inline_response_200_free(inline_response_200_t *inline_response_200);

inline_response_200_t *inline_response_200_parseFromJSON(char *jsonString);

cJSON *inline_response_200_convertToJSON(inline_response_200_t *inline_response_200);

#endif /* _inline_response_200_H_ */

