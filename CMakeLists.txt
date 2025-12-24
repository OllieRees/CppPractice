cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 23)
project(practice VERSION 0.1.0 LANGUAGES CXX)

find_package(CURL REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(hangman)

target_compile_features(hangman PRIVATE cxx_std_23)

target_link_libraries(hangman PRIVATE CURL::libcurl)
target_link_libraries(hangman PRIVATE nlohmann_json::nlohmann_json)

target_sources(
    hangman
    PRIVATE
        hangman/main.cpp
        hangman/word.cpp
        hangman/game.cpp
        hangman/display.cpp
)
