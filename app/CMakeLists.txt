add_executable(${CMAKE_PROJECT_NAME} glad.c main.c)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    ${GLFW_LIBRARY}
    libs
    src
)