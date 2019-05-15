cmake_minimum_required (VERSION 2.6)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_BUILD_TYPE Debug)

set(pkgName "hardware_wallet_daemon_api")

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
    model/apply_settings_request.c
    model/check_message_signature_request.c
    model/csrf_response.c
    model/features_response.c
    model/features_response_data.c
    model/generate_addresses_request.c
    model/generate_addresses_response.c
    model/generate_mnemonic_request.c
    model/http_error_response.c
    model/http_error_response_error.c
    model/http_success_response.c
    model/inline_response_200.c
    model/passphrase_request.c
    model/pin_matrix_request.c
    model/recovery_request.c
    model/set_mnemonic_request.c
    model/sign_message_request.c
    model/sign_message_response.c
    model/transaction_input.c
    model/transaction_output.c
    model/transaction_sign_request.c
    model/transaction_sign_response.c
    model/word_request.c
    api/DefaultAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/keyValuePair.h
    external/cJSON.h
    model/apply_settings_request.h
    model/check_message_signature_request.h
    model/csrf_response.h
    model/features_response.h
    model/features_response_data.h
    model/generate_addresses_request.h
    model/generate_addresses_response.h
    model/generate_mnemonic_request.h
    model/http_error_response.h
    model/http_error_response_error.h
    model/http_success_response.h
    model/inline_response_200.h
    model/passphrase_request.h
    model/pin_matrix_request.h
    model/recovery_request.h
    model/set_mnemonic_request.h
    model/sign_message_request.h
    model/sign_message_response.h
    model/transaction_input.h
    model/transaction_output.h
    model/transaction_sign_request.h
    model/transaction_sign_response.h
    model/word_request.h
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
