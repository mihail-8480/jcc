cmake_minimum_required(VERSION 3.0) 
project(jcc
    LANGUAGES C
    VERSION 0.0.0
    DESCRIPTION "A C compiler that outputs JavaScript."
    HOMEPAGE_URL "https://mojsoski.mk"
)

include("cmake/Platform.cmake")

find_package(Git)
if (Git_FOUND)
    include("cmake/Git.cmake")
endif ()

add_compile_definitions(JCC_VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR})
add_compile_definitions(JCC_VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR})
add_compile_definitions(JCC_VERSION_PATCH=${CMAKE_PROJECT_VERSION_PATCH})


if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    message("-- Building in release mode")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Werror -Wall -Ofast -fsized-deallocation -Werror")
else()
    message("-- Building in debug mode")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Werror -Wall -O0 -ggdb3 -fsized-deallocation -Werror")
endif()

add_executable(jcc src/main.c)
target_include_directories(jcc PUBLIC lib)


install(TARGETS jcc
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY lib/ DESTINATION include)
