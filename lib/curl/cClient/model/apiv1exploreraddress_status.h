/*
 * apiv1exploreraddress_status.h
 *
 * 
 */

#ifndef _apiv1exploreraddress_status_H_
#define _apiv1exploreraddress_status_H_

#include <string.h>
#include "cJSON.h"

typedef int bool;
#define true 1
#define false 0
typedef int bool;
#define true 1
#define false 0



typedef struct apiv1exploreraddress_status_t {
        bool unconfirmed; //boolean
        long block_seq; //numeric
        long label; //numeric
        bool confirmed; //boolean

} apiv1exploreraddress_status_t;

apiv1exploreraddress_status_t *apiv1exploreraddress_status_create(
        bool unconfirmed,
        long block_seq,
        long label,
        bool confirmed
);

void apiv1exploreraddress_status_free(apiv1exploreraddress_status_t *apiv1exploreraddress_status);

apiv1exploreraddress_status_t *apiv1exploreraddress_status_parseFromJSON(char *jsonString);

cJSON *apiv1exploreraddress_status_convertToJSON(apiv1exploreraddress_status_t *apiv1exploreraddress_status);

#endif /* _apiv1exploreraddress_status_H_ */

