/*
 * features_response_data.h
 *
 * 
 */

#ifndef _features_response_data_H_
#define _features_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct features_response_data_t {
    int firmware_features; //numeric
    char *device_id; // string
    int passphrase_protection; //boolean
    char *label; // string
    int fw_patch; //numeric
    int fw_major; //numeric
    int fw_minor; //numeric
    int minor_version; //numeric
    int pin_protection; //boolean
    char *bootloader_hash; // string
    int major_version; //numeric
    int pin_cached; //boolean
    char *vendor; // string
    int needs_backup; //boolean
    int initialized; //boolean
    char *model; // string
    int passphrase_cached; //boolean
    int patch_version; //numeric

} features_response_data_t;

features_response_data_t *features_response_data_create(
    int firmware_features,
    char *device_id,
    int passphrase_protection,
    char *label,
    int fw_patch,
    int fw_major,
    int fw_minor,
    int minor_version,
    int pin_protection,
    char *bootloader_hash,
    int major_version,
    int pin_cached,
    char *vendor,
    int needs_backup,
    int initialized,
    char *model,
    int passphrase_cached,
    int patch_version
);

void features_response_data_free(features_response_data_t *features_response_data);

features_response_data_t *features_response_data_parseFromJSON(cJSON *features_response_dataJSON);

cJSON *features_response_data_convertToJSON(features_response_data_t *features_response_data);

#endif /* _features_response_data_H_ */

