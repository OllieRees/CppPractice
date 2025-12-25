find_package(GTest REQUIRED)
find_library(hangmanlib hangmanlib HINTS "${CMAKE_PREFIX_PATH}")

add_executable(hangman_test test_word.cpp)
target_link_libraries(hangman_test
    PRIVATE 
        hangmanlib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hangman_test)