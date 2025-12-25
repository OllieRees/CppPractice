add_executable(hangman main.cpp)

add_library(
    hangmanlib
    word.cpp
    game.cpp
    display.cpp
)
target_compile_features(hangmanlib PUBLIC cxx_std_23)
target_link_libraries( hangmanlib PUBLIC CURL::libcurl nlohmann_json::nlohmann_json )
target_include_directories( hangmanlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )

target_compile_features(hangman PRIVATE cxx_std_23)
target_link_libraries(hangman PRIVATE hangmanlib)