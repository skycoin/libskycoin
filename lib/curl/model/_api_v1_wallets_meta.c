#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_api_v1_wallets_meta.h"



_api_v1_wallets_meta_t *_api_v1_wallets_meta_create(
    char *filename,
    int encrypted,
    char *crypto_type,
    char *label,
    char *type,
    char *version,
    char *coin,
    int timestamp
    ) {
	_api_v1_wallets_meta_t *_api_v1_wallets_meta_local_var = malloc(sizeof(_api_v1_wallets_meta_t));
    if (!_api_v1_wallets_meta_local_var) {
        return NULL;
    }
	_api_v1_wallets_meta_local_var->filename = filename;
	_api_v1_wallets_meta_local_var->encrypted = encrypted;
	_api_v1_wallets_meta_local_var->crypto_type = crypto_type;
	_api_v1_wallets_meta_local_var->label = label;
	_api_v1_wallets_meta_local_var->type = type;
	_api_v1_wallets_meta_local_var->version = version;
	_api_v1_wallets_meta_local_var->coin = coin;
	_api_v1_wallets_meta_local_var->timestamp = timestamp;

	return _api_v1_wallets_meta_local_var;
}


void _api_v1_wallets_meta_free(_api_v1_wallets_meta_t *_api_v1_wallets_meta) {
    listEntry_t *listEntry;
    free(_api_v1_wallets_meta->filename);
    free(_api_v1_wallets_meta->crypto_type);
    free(_api_v1_wallets_meta->label);
    free(_api_v1_wallets_meta->type);
    free(_api_v1_wallets_meta->version);
    free(_api_v1_wallets_meta->coin);
	free(_api_v1_wallets_meta);
}

cJSON *_api_v1_wallets_meta_convertToJSON(_api_v1_wallets_meta_t *_api_v1_wallets_meta) {
	cJSON *item = cJSON_CreateObject();

	// _api_v1_wallets_meta->filename
    if(_api_v1_wallets_meta->filename) { 
    if(cJSON_AddStringToObject(item, "filename", _api_v1_wallets_meta->filename) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_meta->encrypted
    if(_api_v1_wallets_meta->encrypted) { 
    if(cJSON_AddBoolToObject(item, "encrypted", _api_v1_wallets_meta->encrypted) == NULL) {
    goto fail; //Bool
    }
     } 


	// _api_v1_wallets_meta->crypto_type
    if(_api_v1_wallets_meta->crypto_type) { 
    if(cJSON_AddStringToObject(item, "crypto_type", _api_v1_wallets_meta->crypto_type) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_meta->label
    if(_api_v1_wallets_meta->label) { 
    if(cJSON_AddStringToObject(item, "label", _api_v1_wallets_meta->label) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_meta->type
    if(_api_v1_wallets_meta->type) { 
    if(cJSON_AddStringToObject(item, "type", _api_v1_wallets_meta->type) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_meta->version
    if(_api_v1_wallets_meta->version) { 
    if(cJSON_AddStringToObject(item, "version", _api_v1_wallets_meta->version) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_meta->coin
    if(_api_v1_wallets_meta->coin) { 
    if(cJSON_AddStringToObject(item, "coin", _api_v1_wallets_meta->coin) == NULL) {
    goto fail; //String
    }
     } 


	// _api_v1_wallets_meta->timestamp
    if(_api_v1_wallets_meta->timestamp) { 
    if(cJSON_AddNumberToObject(item, "timestamp", _api_v1_wallets_meta->timestamp) == NULL) {
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

_api_v1_wallets_meta_t *_api_v1_wallets_meta_parseFromJSON(cJSON *_api_v1_wallets_metaJSON){

    _api_v1_wallets_meta_t *_api_v1_wallets_meta_local_var = NULL;

    // _api_v1_wallets_meta->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "filename");
    if (filename) { 
    if(!cJSON_IsString(filename))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_meta->encrypted
    cJSON *encrypted = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "encrypted");
    if (encrypted) { 
    if(!cJSON_IsBool(encrypted))
    {
    goto end; //Bool
    }
    }

    // _api_v1_wallets_meta->crypto_type
    cJSON *crypto_type = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "crypto_type");
    if (crypto_type) { 
    if(!cJSON_IsString(crypto_type))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_meta->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "label");
    if (label) { 
    if(!cJSON_IsString(label))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_meta->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_meta->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "version");
    if (version) { 
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_meta->coin
    cJSON *coin = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "coin");
    if (coin) { 
    if(!cJSON_IsString(coin))
    {
    goto end; //String
    }
    }

    // _api_v1_wallets_meta->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(_api_v1_wallets_metaJSON, "timestamp");
    if (timestamp) { 
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }
    }


    _api_v1_wallets_meta_local_var = _api_v1_wallets_meta_create (
        filename ? strdup(filename->valuestring) : NULL,
        encrypted ? encrypted->valueint : 0,
        crypto_type ? strdup(crypto_type->valuestring) : NULL,
        label ? strdup(label->valuestring) : NULL,
        type ? strdup(type->valuestring) : NULL,
        version ? strdup(version->valuestring) : NULL,
        coin ? strdup(coin->valuestring) : NULL,
        timestamp ? timestamp->valuedouble : 0
        );

    return _api_v1_wallets_meta_local_var;
end:
    return NULL;

}
