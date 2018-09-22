project(th-securitytest-android)
cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)
include_directories(src)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(th-securitytest-android ${SOURCE_FILES} ${HEADER_FILES})