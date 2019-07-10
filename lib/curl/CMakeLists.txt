cmake_minimum_required(VERSION 2.6)
project(CGenerator)

#cmake_policy(SET CMP0063 NEW)

#set(CMAKE_C_VISIBILITY_PRESET default)
#set(CMAKE_CXX_VISIBILITY_PRESET default)
#set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_BUILD_TYPE Release)

set(pkgName "skyapi")

find_package(CURL 7.58.0 EXACT REQUIRED)

set(SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apiKey.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/apiClient.c
    ${CMAKE_CURRENT_SOURCE_DIR}/external/cJSON.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/_api_v1_pending_txs_transaction.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/_api_v1_pending_txs_transaction_outputs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/address.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_schema.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_schema_body.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_verbose_schema.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_verbose_schema_body.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_verbose_schema_header.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_1.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_10.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_4.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_5.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_6.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_7.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_8.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_8_data.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_9.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_default.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/network_connection_schema.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/network_connection_schema_unconfirmed_verify_transaction.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_encoded.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_encoded_s.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_status.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_txn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_address.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_address_hours_selection.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_unspent.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_unspent_hours_selection.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_unspent_to.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verbose.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verbose_txn.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verbose_txn_inputs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verify_request.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_request.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_request_hours_selection.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_request_wallet.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_sign_request.c
    ${CMAKE_CURRENT_SOURCE_DIR}/api/DefaultAPI.c
    ${CMAKE_CURRENT_SOURCE_DIR}/model/object.c

)

set(HDRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/apiClient.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/list.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/keyValuePair.h
    ${CMAKE_CURRENT_SOURCE_DIR}/external/cJSON.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/_api_v1_pending_txs_transaction.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/_api_v1_pending_txs_transaction_outputs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/address.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_schema.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_schema_body.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_verbose_schema.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_verbose_schema_body.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/block_verbose_schema_header.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_1.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_10.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_2.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_4.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_5.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_6.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_7.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_8.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_8_data.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_200_9.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/inline_response_default.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/network_connection_schema.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/network_connection_schema_unconfirmed_verify_transaction.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_encoded.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_encoded_s.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_status.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_txn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_address.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_address_hours_selection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_unspent.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_unspent_hours_selection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_v2_params_unspent_to.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verbose.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verbose_txn.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verbose_txn_inputs.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/transaction_verify_request.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_request.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_request_hours_selection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_request_wallet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/wallet_transaction_sign_request.h
    ${CMAKE_CURRENT_SOURCE_DIR}/api/DefaultAPI.h
    ${CMAKE_CURRENT_SOURCE_DIR}/model/object.h
)

include_directories(${CURL_INCLUDE_DIR})
# Add library with project file with projectname as library name
add_library(${pkgName} SHARED ${SRCS} ${HDRS})
add_library(${pkgName}Static STATIC ${SRCS} ${HDRS})
# Link dependent libraries
target_link_libraries(${pkgName} ${CURL_LIBRARIES})
#install library to destination
install(TARGETS ${pkgName} DESTINATION ${CMAKE_INSTALL_PREFIX})

unset(CMAKE_BUILD_TYPE CACHE)

# Setting file variables to null
#set(SRCS "")
#set(HDRS "")


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
