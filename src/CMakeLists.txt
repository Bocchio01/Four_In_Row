project(src
    VERSION 1.0
    DESCRIPTION "Source files for the Connect_4_Game"
    LANGUAGES C
)

add_subdirectory(setup)

add_library(${PROJECT_NAME}
    definitions.h
    utils.h
    utils.c
    functions.h
    functions.c
    loop.h
    loop.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME}
    setup
)