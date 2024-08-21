cmake_minimum_required (VERSION 3.19)

set(PROJECT_NAME Demo)
project(PROJECT_NAME CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

set(Proj_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_INSTALL_PREFIX "${Demo_ROOT_DIR}/bin")
set(BINARY_ROOT_DIR "${CMAKE_INSTALL_PREFIX}/")

add_subdirectory(3rdParty)
add_subdirectory(src)


