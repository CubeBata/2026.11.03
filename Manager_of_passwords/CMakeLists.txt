cmake_minimum_required(VERSION 3.14)

project(${CMAKE_CURRENT_SOURCE_DIR} VERSION 0.0.0 LANGUAGE C CXX)

add_executable(
    ${CMAKE_PROJECT_NAME}
    src/main.cpp
)

add_subdirectory(lib)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME}::lib)