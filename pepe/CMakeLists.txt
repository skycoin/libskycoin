cmake_minimum_required (VERSION 2.6)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_BUILD_TYPE Debug)

set(pkgName "skycoin_rest_api/")

find_package(CURL 7.58.0 REQUIRED)
if(CURL_FOUND)
	include_directories(${CURL_INCLUDE_DIR})
	set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else(CURL_FOUND)
	message(FATAL_ERROR "Could not find the CURL library and development files.")
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    external/cJSON.c
    model/_api_v1_pending_txs_transaction.c
    model/_api_v1_pending_txs_transaction_outputs.c
    model/_api_v1_pending_txs_verbose_transaction.c
    model/address.c
    model/block_schema.c
    model/block_schema_body.c
    model/block_verbose_schema.c
    model/block_verbose_schema_body.c
    model/block_verbose_schema_header.c
    model/inline_response_200.c
    model/inline_response_200_1.c
    model/inline_response_200_10.c
    model/inline_response_200_10_data.c
    model/inline_response_200_11.c
    model/inline_response_200_12.c
    model/inline_response_200_13.c
    model/inline_response_200_2.c
    model/inline_response_200_3.c
    model/inline_response_200_4.c
    model/inline_response_200_5.c
    model/inline_response_200_6.c
    model/inline_response_200_7.c
    model/inline_response_200_8.c
    model/inline_response_200_9.c
    model/inline_response_default.c
    model/multi_key.c
    model/multi_key_data.c
    model/multi_key_data_key2.c
    model/network_connection_schema.c
    model/network_connection_schema_unconfirmed_verify_transaction.c
    model/single_key.c
    model/transaction.c
    model/transaction_encoded.c
    model/transaction_encoded_s.c
    model/transaction_status.c
    model/transaction_txn.c
    model/transaction_v2_params_address.c
    model/transaction_v2_params_address_hours_selection.c
    model/transaction_v2_params_unspent.c
    model/transaction_v2_params_unspent_hours_selection.c
    model/transaction_v2_params_unspent_to.c
    model/transaction_verbose.c
    model/transaction_verbose_txn.c
    model/transaction_verbose_txn_inputs.c
    api/DefaultAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/keyValuePair.h
    external/cJSON.h
    model/_api_v1_pending_txs_transaction.h
    model/_api_v1_pending_txs_transaction_outputs.h
    model/_api_v1_pending_txs_verbose_transaction.h
    model/address.h
    model/block_schema.h
    model/block_schema_body.h
    model/block_verbose_schema.h
    model/block_verbose_schema_body.h
    model/block_verbose_schema_header.h
    model/inline_response_200.h
    model/inline_response_200_1.h
    model/inline_response_200_10.h
    model/inline_response_200_10_data.h
    model/inline_response_200_11.h
    model/inline_response_200_12.h
    model/inline_response_200_13.h
    model/inline_response_200_2.h
    model/inline_response_200_3.h
    model/inline_response_200_4.h
    model/inline_response_200_5.h
    model/inline_response_200_6.h
    model/inline_response_200_7.h
    model/inline_response_200_8.h
    model/inline_response_200_9.h
    model/inline_response_default.h
    model/multi_key.h
    model/multi_key_data.h
    model/multi_key_data_key2.h
    model/network_connection_schema.h
    model/network_connection_schema_unconfirmed_verify_transaction.h
    model/single_key.h
    model/transaction.h
    model/transaction_encoded.h
    model/transaction_encoded_s.h
    model/transaction_status.h
    model/transaction_txn.h
    model/transaction_v2_params_address.h
    model/transaction_v2_params_address_hours_selection.h
    model/transaction_v2_params_unspent.h
    model/transaction_v2_params_unspent_hours_selection.h
    model/transaction_v2_params_unspent_to.h
    model/transaction_verbose.h
    model/transaction_verbose_txn.h
    model/transaction_verbose_txn_inputs.h
    api/DefaultAPI.h

)

# Add library with project file with projectname as library name
add_library(${pkgName} SHARED ${SRCS} ${HDRS})
# Link dependent libraries
target_link_libraries(${pkgName} ${CURL_LIBRARIES} )
#install library to destination
install(TARGETS ${pkgName} DESTINATION ${CMAKE_INSTALL_PREFIX})

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled libary to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-PetAPI.c
#    unit-tests/manual-StoreAPI.c
#    unit-tests/manual-UserAPI.c
#    unit-tests/manual-order.c
#    unit-tests/manual-user.c)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable doesnot support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created libary to executable and dependent libary curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
