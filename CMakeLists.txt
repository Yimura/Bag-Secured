cmake_minimum_required(VERSION 3.20.x)

project(BagSecured VERSION 0.0.1 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23)
