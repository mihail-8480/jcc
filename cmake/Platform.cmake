cmake_minimum_required(VERSION 3.0)

if (UNIX AND NOT (APPLE OR HAIKU))
    add_compile_definitions(UNIX_LIKE)
    set(UNIX_LIKE 1)
endif (UNIX AND NOT (APPLE OR HAIKU))

if (WIN32)
    add_compile_definitions(WIN32)
endif (WIN32)

if (UNIX)
    add_compile_definitions(UNIX)
endif (UNIX)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(LINUX)
    set(LINUX 1)
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")

if (HAIKU)
    add_compile_definitions(HAIKU)
    add_compile_definitions(_BSD_SOURCE)
endif (HAIKU)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(JCC_DEBUG)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -fPIC")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    message("-- Building in release mode")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")
else()
    message("-- Building in debug mode")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb3")
endif()

string(LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_PATH_SIZE)
add_compile_definitions("SOURCE_PATH_SIZE=${SOURCE_PATH_SIZE}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

IF (UNIX)
    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF ()

SET(JCC_PLATFORM "libc" CACHE STRING "The JCC platform")
set(JCORE_LIB "jcore_${JCC_PLATFORM}")

message("-- JCC platform: " ${JCC_PLATFORM})
message("-- JCC core lib: " ${JCORE_LIB})

add_library(${JCORE_LIB} SHARED src/core/string.c src/core/error.c src/core/logs.c)
target_compile_definitions(${JCORE_LIB} PRIVATE JCC_IMPL)
target_compile_definitions(${JCORE_LIB} PUBLIC "JCC_PLATFORM=${JCC_PLATFORM}")

