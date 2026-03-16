cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 23)
project(practice VERSION 0.1.0 LANGUAGES CXX)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
enable_testing()

add_subdirectory(hangman)
add_subdirectory(tests)