project(setup
    VERSION 1.0
    DESCRIPTION "Setup module for the Connect_4_Game"
    LANGUAGES C
)

add_library(${PROJECT_NAME}
    setup.h
    setup.c
    default.h
    default.c
    cmd.h
    cmd.c
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})