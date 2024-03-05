add_library(libs
    libs.c
    libs.h
)

add_subdirectory(cGETOPT)

target_link_libraries(libs
    cGETOPT
)

target_include_directories(libs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cGETOPT
)