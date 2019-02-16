#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cJSON.h"
#include "list.h"
#include "keyValuePair.h"
#include "apiv1wallets_meta.h"


apiv1wallets_meta_t *apiv1wallets_meta_create(
    char *filename,
    bool encrypted,
    char *crypto_type,
    char *label,
    char *type,
    char *version,
    char *coin,
    int timestamp
    ) {
	apiv1wallets_meta_t *apiv1wallets_meta = malloc(sizeof(apiv1wallets_meta_t));
	apiv1wallets_meta->filename = filename;
	apiv1wallets_meta->encrypted = encrypted;
	apiv1wallets_meta->crypto_type = crypto_type;
	apiv1wallets_meta->label = label;
	apiv1wallets_meta->type = type;
	apiv1wallets_meta->version = version;
	apiv1wallets_meta->coin = coin;
	apiv1wallets_meta->timestamp = timestamp;

	return apiv1wallets_meta;
}


void apiv1wallets_meta_free(apiv1wallets_meta_t *apiv1wallets_meta) {
    listEntry_t *listEntry;
    free(apiv1wallets_meta->filename);
    free(apiv1wallets_meta->crypto_type);
    free(apiv1wallets_meta->label);
    free(apiv1wallets_meta->type);
    free(apiv1wallets_meta->version);
    free(apiv1wallets_meta->coin);

	free(apiv1wallets_meta);
}

cJSON *apiv1wallets_meta_convertToJSON(apiv1wallets_meta_t *apiv1wallets_meta) {
	cJSON *item = cJSON_CreateObject();
	// apiv1wallets_meta->filename
    if(cJSON_AddStringToObject(item, "filename", apiv1wallets_meta->filename) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_meta->encrypted
    if(cJSON_AddBoolToObject(item, "encrypted", apiv1wallets_meta->encrypted) == NULL) {
    goto fail; //Numeric
    }

	// apiv1wallets_meta->crypto_type
    if(cJSON_AddStringToObject(item, "crypto_type", apiv1wallets_meta->crypto_type) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_meta->label
    if(cJSON_AddStringToObject(item, "label", apiv1wallets_meta->label) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_meta->type
    if(cJSON_AddStringToObject(item, "type", apiv1wallets_meta->type) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_meta->version
    if(cJSON_AddStringToObject(item, "version", apiv1wallets_meta->version) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_meta->coin
    if(cJSON_AddStringToObject(item, "coin", apiv1wallets_meta->coin) == NULL) {
    goto fail; //String
    }

	// apiv1wallets_meta->timestamp
    if(cJSON_AddNumberToObject(item, "timestamp", apiv1wallets_meta->timestamp) == NULL) {
    goto fail; //Numeric
    }

	return item;
fail:
	cJSON_Delete(item);
	return NULL;
}

apiv1wallets_meta_t *apiv1wallets_meta_parseFromJSON(char *jsonString){

    apiv1wallets_meta_t *apiv1wallets_meta = NULL;
    cJSON *apiv1wallets_metaJSON = cJSON_Parse(jsonString);
    if(apiv1wallets_metaJSON == NULL){
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error Before: %s\n", error_ptr);
            goto end;
        }
    }

    // apiv1wallets_meta->filename
    cJSON *filename = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "filename");
    if(!cJSON_IsString(filename) || (filename->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_meta->encrypted
    cJSON *encrypted = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "encrypted");
    if(!cJSON_IsBool(encrypted))
    {
    goto end; //Numeric
    }

    // apiv1wallets_meta->crypto_type
    cJSON *crypto_type = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "crypto_type");
    if(!cJSON_IsString(crypto_type) || (crypto_type->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_meta->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "label");
    if(!cJSON_IsString(label) || (label->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_meta->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "type");
    if(!cJSON_IsString(type) || (type->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_meta->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "version");
    if(!cJSON_IsString(version) || (version->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_meta->coin
    cJSON *coin = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "coin");
    if(!cJSON_IsString(coin) || (coin->valuestring == NULL)){
    goto end; //String
    }

    // apiv1wallets_meta->timestamp
    cJSON *timestamp = cJSON_GetObjectItemCaseSensitive(apiv1wallets_metaJSON, "timestamp");
    if(!cJSON_IsNumber(timestamp))
    {
    goto end; //Numeric
    }


    apiv1wallets_meta = apiv1wallets_meta_create (
        strdup(filename->valuestring),
        encrypted->valueint,
        strdup(crypto_type->valuestring),
        strdup(label->valuestring),
        strdup(type->valuestring),
        strdup(version->valuestring),
        strdup(coin->valuestring),
        timestamp->valuedouble
        );
 cJSON_Delete(apiv1wallets_metaJSON);
    return apiv1wallets_meta;
end:
    cJSON_Delete(apiv1wallets_metaJSON);
    return NULL;

}

