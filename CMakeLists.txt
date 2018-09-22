project(th-securitytest-android)
cmake_minimum_required(VERSION 3.12)
include_directories(src)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(th-securitytest-android ${SOURCE_FILES})