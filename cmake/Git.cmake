cmake_minimum_required(VERSION 3.0)
execute_process(COMMAND
        "${GIT_EXECUTABLE}" rev-parse HEAD
        RESULT_VARIABLE
        GIT_HASH_RESULT
        OUTPUT_VARIABLE
        GIT_HASH)

execute_process(COMMAND
        "${GIT_EXECUTABLE}" rev-parse --abbrev-ref HEAD
        RESULT_VARIABLE
        GIT_BRANCH_RESULT
        OUTPUT_VARIABLE
        GIT_BRANCH)

execute_process(COMMAND
        "${GIT_EXECUTABLE}" config --get remote.origin.url
        RESULT_VARIABLE
        GIT_REMOTE_RESULT
        OUTPUT_VARIABLE
        GIT_REMOTE)

execute_process(COMMAND
        "${GIT_EXECUTABLE}" status --porcelain
        RESULT_VARIABLE
        GIT_CHANGES_RESULT
        OUTPUT_VARIABLE
        GIT_CHANGES)

string(LENGTH "${GIT_CHANGES}" GIT_CHANGES_LEN)
if(${GIT_CHANGES_LEN} EQUAL 0)
        add_compile_definitions(GIT_CLEAN)
endif()

string(REGEX REPLACE "\n$" "" GIT_HASH "${GIT_HASH}")
string(REGEX REPLACE "\n$" "" GIT_BRANCH "${GIT_BRANCH}")
string(REGEX REPLACE "\n$" "" GIT_REMOTE "${GIT_REMOTE}")
add_compile_definitions(GIT_HASH="${GIT_HASH}")
add_compile_definitions(GIT_BRANCH="${GIT_BRANCH}")
add_compile_definitions(GIT_REMOTE="${GIT_REMOTE}")
