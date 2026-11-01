cmake_minimum_required(VERSION 3.14)

project(${CMAKE_PROJECT_NAME}_lib VERSION 0.0.0 LANGUAGE C CXX)

add_library(
    ${PROJECT_NAME}

    src/*.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(${CMAKE_PROJECT_NAME}::lib ALIAS ${CMAKE_PROJECT_NAME}_lib)