cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
project (heys)

set(SOURCES
    src/main.cpp
    src/heys.cpp
)

add_executable(heys ${SOURCES})

target_include_directories(heys
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/common
)
