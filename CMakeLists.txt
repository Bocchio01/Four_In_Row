cmake_minimum_required(VERSION 3.28)

project(Connect_4_Game
    VERSION 2.3
    DESCRIPTION "A (not so basic) 'Connect 4 Game' implementation"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Werror -O2)
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

add_definitions(-DLOG_USE_COLOR)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

add_subdirectory(libs)
add_subdirectory(src)
add_subdirectory(app)
