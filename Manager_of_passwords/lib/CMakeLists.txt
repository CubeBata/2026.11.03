cmake_minimum_required(VERSION 3.14)

project(${CMAKE_PROJECT_NAME}_lib VERSION 0.0.0 LANGUAGES C CXX)
file(GLOB LIB_SOURCES "src/*.cpp")
add_library(
    ${PROJECT_NAME}
    ${LIB_SOURCES} 
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(${CMAKE_PROJECT_NAME}::lib ALIAS ${CMAKE_PROJECT_NAME}_lib)