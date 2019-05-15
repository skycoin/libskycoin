#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "features_response_data.h"



features_response_data_t *features_response_data_create(
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
    ) {
	features_response_data_t *features_response_data_local_var = malloc(sizeof(features_response_data_t));
    if (!features_response_data_local_var) {
        return NULL;
    }
	features_response_data_local_var->device_id = device_id;
	features_response_data_local_var->passphrase_protection = passphrase_protection;
	features_response_data_local_var->label = label;
	features_response_data_local_var->fw_patch = fw_patch;
	features_response_data_local_var->fw_major = fw_major;
	features_response_data_local_var->fw_minor = fw_minor;
	features_response_data_local_var->minor_version = minor_version;
	features_response_data_local_var->pin_protection = pin_protection;
	features_response_data_local_var->bootloader_hash = bootloader_hash;
	features_response_data_local_var->major_version = major_version;
	features_response_data_local_var->pin_cached = pin_cached;
	features_response_data_local_var->vendor = vendor;
	features_response_data_local_var->needs_backup = needs_backup;
	features_response_data_local_var->initialized = initialized;
	features_response_data_local_var->model = model;
	features_response_data_local_var->passphrase_cached = passphrase_cached;
	features_response_data_local_var->patch_version = patch_version;

	return features_response_data_local_var;
}


void features_response_data_free(features_response_data_t *features_response_data) {
    listEntry_t *listEntry;
    free(features_response_data->device_id);
    free(features_response_data->label);
    free(features_response_data->bootloader_hash);
    free(features_response_data->vendor);
    free(features_response_data->model);
	free(features_response_data);
}

cJSON *features_response_data_convertToJSON(features_response_data_t *features_response_data) {
	cJSON *item = cJSON_CreateObject();

	// features_response_data->device_id
    if(features_response_data->device_id) { 
    if(cJSON_AddStringToObject(item, "device_id", features_response_data->device_id) == NULL) {
    goto fail; //String
    }
     } 


	// features_response_data->passphrase_protection
    if (!features_response_data->passphrase_protection) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "passphrase_protection", features_response_data->passphrase_protection) == NULL) {
    goto fail; //Bool
    }


	// features_response_data->label
    if(features_response_data->label) { 
    if(cJSON_AddStringToObject(item, "label", features_response_data->label) == NULL) {
    goto fail; //String
    }
     } 


	// features_response_data->fw_patch
    if (!features_response_data->fw_patch) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "fw_patch", features_response_data->fw_patch) == NULL) {
    goto fail; //Numeric
    }


	// features_response_data->fw_major
    if (!features_response_data->fw_major) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "fw_major", features_response_data->fw_major) == NULL) {
    goto fail; //Numeric
    }


	// features_response_data->fw_minor
    if (!features_response_data->fw_minor) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "fw_minor", features_response_data->fw_minor) == NULL) {
    goto fail; //Numeric
    }


	// features_response_data->minor_version
    if(features_response_data->minor_version) { 
    if(cJSON_AddNumberToObject(item, "minor_version", features_response_data->minor_version) == NULL) {
    goto fail; //Numeric
    }
     } 


	// features_response_data->pin_protection
    if (!features_response_data->pin_protection) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "pin_protection", features_response_data->pin_protection) == NULL) {
    goto fail; //Bool
    }


	// features_response_data->bootloader_hash
    if(features_response_data->bootloader_hash) { 
    if(cJSON_AddStringToObject(item, "bootloader_hash", features_response_data->bootloader_hash) == NULL) {
    goto fail; //String
    }
     } 


	// features_response_data->major_version
    if(features_response_data->major_version) { 
    if(cJSON_AddNumberToObject(item, "major_version", features_response_data->major_version) == NULL) {
    goto fail; //Numeric
    }
     } 


	// features_response_data->pin_cached
    if (!features_response_data->pin_cached) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "pin_cached", features_response_data->pin_cached) == NULL) {
    goto fail; //Bool
    }


	// features_response_data->vendor
    if (!features_response_data->vendor) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "vendor", features_response_data->vendor) == NULL) {
    goto fail; //String
    }


	// features_response_data->needs_backup
    if (!features_response_data->needs_backup) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "needs_backup", features_response_data->needs_backup) == NULL) {
    goto fail; //Bool
    }


	// features_response_data->initialized
    if (!features_response_data->initialized) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "initialized", features_response_data->initialized) == NULL) {
    goto fail; //Bool
    }


	// features_response_data->model
    if(features_response_data->model) { 
    if(cJSON_AddStringToObject(item, "model", features_response_data->model) == NULL) {
    goto fail; //String
    }
     } 


	// features_response_data->passphrase_cached
    if (!features_response_data->passphrase_cached) {
        goto fail;
    }
    
    if(cJSON_AddBoolToObject(item, "passphrase_cached", features_response_data->passphrase_cached) == NULL) {
    goto fail; //Bool
    }


	// features_response_data->patch_version
    if(features_response_data->patch_version) { 
    if(cJSON_AddNumberToObject(item, "patch_version", features_response_data->patch_version) == NULL) {
    goto fail; //Numeric
    }
     } 

	return item;
fail:
	if (item) {
        cJSON_Delete(item);
    }
	return NULL;
}

features_response_data_t *features_response_data_parseFromJSON(cJSON *features_response_dataJSON){

    features_response_data_t *features_response_data_local_var = NULL;

    // features_response_data->device_id
    cJSON *device_id = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "device_id");
    if (device_id) { 
    if(!cJSON_IsString(device_id))
    {
    goto end; //String
    }
    }

    // features_response_data->passphrase_protection
    cJSON *passphrase_protection = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "passphrase_protection");
    if (!passphrase_protection) {
        goto end;
    }

    
    if(!cJSON_IsBool(passphrase_protection))
    {
    goto end; //Bool
    }

    // features_response_data->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "label");
    if (label) { 
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }
    }

    // features_response_data->fw_patch
    cJSON *fw_patch = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "fw_patch");
    if (!fw_patch) {
        goto end;
    }

    
    if(!cJSON_IsNumber(fw_patch))
    {
    goto end; //Numeric
    }

    // features_response_data->fw_major
    cJSON *fw_major = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "fw_major");
    if (!fw_major) {
        goto end;
    }

    
    if(!cJSON_IsNumber(fw_major))
    {
    goto end; //Numeric
    }

    // features_response_data->fw_minor
    cJSON *fw_minor = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "fw_minor");
    if (!fw_minor) {
        goto end;
    }

    
    if(!cJSON_IsNumber(fw_minor))
    {
    goto end; //Numeric
    }

    // features_response_data->minor_version
    cJSON *minor_version = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "minor_version");
    if (minor_version) { 
    if(!cJSON_IsNumber(minor_version))
    {
    goto end; //Numeric
    }
    }

    // features_response_data->pin_protection
    cJSON *pin_protection = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "pin_protection");
    if (!pin_protection) {
        goto end;
    }

    
    if(!cJSON_IsBool(pin_protection))
    {
    goto end; //Bool
    }

    // features_response_data->bootloader_hash
    cJSON *bootloader_hash = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "bootloader_hash");
    if (bootloader_hash) { 
    if(!cJSON_IsString(bootloader_hash))
    {
    goto end; //String
    }
    }

    // features_response_data->major_version
    cJSON *major_version = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "major_version");
    if (major_version) { 
    if(!cJSON_IsNumber(major_version))
    {
    goto end; //Numeric
    }
    }

    // features_response_data->pin_cached
    cJSON *pin_cached = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "pin_cached");
    if (!pin_cached) {
        goto end;
    }

    
    if(!cJSON_IsBool(pin_cached))
    {
    goto end; //Bool
    }

    // features_response_data->vendor
    cJSON *vendor = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "vendor");
    if (!vendor) {
        goto end;
    }

    
    if(!cJSON_IsString(vendor))
    {
    goto end; //String
    }

    // features_response_data->needs_backup
    cJSON *needs_backup = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "needs_backup");
    if (!needs_backup) {
        goto end;
    }

    
    if(!cJSON_IsBool(needs_backup))
    {
    goto end; //Bool
    }

    // features_response_data->initialized
    cJSON *initialized = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "initialized");
    if (!initialized) {
        goto end;
    }

    
    if(!cJSON_IsBool(initialized))
    {
    goto end; //Bool
    }

    // features_response_data->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "model");
    if (model) { 
    if(!cJSON_IsString(model))
    {
    goto end; //String
    }
    }

    // features_response_data->passphrase_cached
    cJSON *passphrase_cached = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "passphrase_cached");
    if (!passphrase_cached) {
        goto end;
    }

    
    if(!cJSON_IsBool(passphrase_cached))
    {
    goto end; //Bool
    }

    // features_response_data->patch_version
    cJSON *patch_version = cJSON_GetObjectItemCaseSensitive(features_response_dataJSON, "patch_version");
    if (patch_version) { 
    if(!cJSON_IsNumber(patch_version))
    {
    goto end; //Numeric
    }
    }


    features_response_data_local_var = features_response_data_create (
        device_id ? strdup(device_id->valuestring) : NULL,
        passphrase_protection->valueint,
        label ? strdup(label->valuestring) : NULL,
        fw_patch->valuedouble,
        fw_major->valuedouble,
        fw_minor->valuedouble,
        minor_version ? minor_version->valuedouble : 0,
        pin_protection->valueint,
        bootloader_hash ? strdup(bootloader_hash->valuestring) : NULL,
        major_version ? major_version->valuedouble : 0,
        pin_cached->valueint,
        strdup(vendor->valuestring),
        needs_backup->valueint,
        initialized->valueint,
        model ? strdup(model->valuestring) : NULL,
        passphrase_cached->valueint,
        patch_version ? patch_version->valuedouble : 0
        );

    return features_response_data_local_var;
end:
    return NULL;

}
