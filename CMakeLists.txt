cmake_minimum_required(VERSION 2.8.4)
project(DirectoryListings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cc)

add_subdirectory(src)

add_executable(DirectoryListings ${SOURCE_FILES})

target_link_libraries(DirectoryListings directory_listing)