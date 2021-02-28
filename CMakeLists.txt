cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 17)
project (hello_headers)

set(SOURCES
    src/main.cpp
    src/heys.cpp
)

add_executable(hello_headers ${SOURCES})

target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/common
)
