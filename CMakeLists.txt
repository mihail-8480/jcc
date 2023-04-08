cmake_minimum_required(VERSION 3.0) 
project(jcc
    LANGUAGES C
    VERSION 0.0.0
    DESCRIPTION "A C compiler that outputs JavaScript"
    HOMEPAGE_URL "https://mojsoski.mk"
)

include("cmake/Platform.cmake")

if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
    find_package(Git)
    if (Git_FOUND)
        include("cmake/Git.cmake")
    endif ()
endif ()
add_compile_definitions(VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR})
add_compile_definitions(VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR})
add_compile_definitions(VERSION_PATCH=${CMAKE_PROJECT_VERSION_PATCH})

include_directories(lib)

add_library(jcc-compiler SHARED src/compiler/lexer.c src/versions/jcc-compiler.c)
target_link_libraries(jcc-compiler PUBLIC ${JCC_CORE_LIB})


add_library(jcc-lang-c SHARED src/compiler/c/lexer.c src/compiler/c/compiler.c src/versions/jcc-lang-c.c)
target_link_libraries(jcc-lang-c PUBLIC  ${JCC_CORE_LIB} jcc-compiler)


add_executable(jcc src/main.c src/versions/jcc.c)
target_link_libraries(jcc PUBLIC ${JCC_CORE_LIB} jcc-lang-c)

install(TARGETS jcc
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY lib/ DESTINATION include)
