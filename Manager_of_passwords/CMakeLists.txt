cmake_minimum_required(VERSION 3.14)

project(Manager_of_password VERSION 0.0.0 LANGUAGES C CXX)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)

add_subdirectory(lib)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}::lib)