add_executable(hangman main.cpp)

add_library(
    hangman_lib
    word.hpp
    word.cpp
    game.hpp
    game.cpp
    display.hpp
    display.cpp
)

target_compile_features(hangman_lib PUBLIC cxx_std_23)
target_link_libraries(hangman_lib PUBLIC CURL::libcurl)
target_link_libraries(hangman_lib PUBLIC nlohmann_json::nlohmann_json)

target_compile_features(hangman PRIVATE cxx_std_23)
target_link_libraries(hangman PRIVATE hangman_lib)