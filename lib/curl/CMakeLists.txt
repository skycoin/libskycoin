cmake_minimum_required (VERSION 2.6)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_BUILD_TYPE Debug)

set(pkgName "skyapi")

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
    model/_api_v1_explorer_address_inputs.c
    model/_api_v1_explorer_address_outputs.c
    model/_api_v1_explorer_address_status.c
    model/_api_v1_pending_txs_transaction.c
    model/_api_v1_wallet_transaction_hours_selection.c
    model/_api_v1_wallet_transaction_to.c
    model/_api_v1_wallet_transaction_wallet.c
    model/_api_v1_wallets_entries.c
    model/_api_v1_wallets_meta.c
    model/inline_object.c
    model/inline_response_200.c
    model/inline_response_200_1.c
    model/inline_response_200_2.c
    model/inline_response_200_3.c
    model/inline_response_200_3_unconfirmed_verify_transaction.c
    model/inline_response_200_4.c
    model/inline_response_200_5.c
    model/inline_response_200_6.c
    model/inline_response_200_7.c
    model/inline_response_200_7_data.c
    model/inline_response_default.c
    api/DefaultAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/keyValuePair.h
    external/cJSON.h
    model/_api_v1_explorer_address_inputs.h
    model/_api_v1_explorer_address_outputs.h
    model/_api_v1_explorer_address_status.h
    model/_api_v1_pending_txs_transaction.h
    model/_api_v1_wallet_transaction_hours_selection.h
    model/_api_v1_wallet_transaction_to.h
    model/_api_v1_wallet_transaction_wallet.h
    model/_api_v1_wallets_entries.h
    model/_api_v1_wallets_meta.h
    model/inline_object.h
    model/inline_response_200.h
    model/inline_response_200_1.h
    model/inline_response_200_2.h
    model/inline_response_200_3.h
    model/inline_response_200_3_unconfirmed_verify_transaction.h
    model/inline_response_200_4.h
    model/inline_response_200_5.h
    model/inline_response_200_6.h
    model/inline_response_200_7.h
    model/inline_response_200_7_data.h
    model/inline_response_default.h
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
