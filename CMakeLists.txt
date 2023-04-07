cmake_minimum_required(VERSION 3.0) 
project(jcc
    LANGUAGES C
    VERSION 0.0.0
    DESCRIPTION "A C compiler that outputs JavaScript"
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

include_directories(lib)

add_library(jcore SHARED src/core/string.c)

add_executable(jcc src/main.c)
target_link_libraries(jcc PUBLIC jcore)

install(TARGETS jcc
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY lib/ DESTINATION include)
