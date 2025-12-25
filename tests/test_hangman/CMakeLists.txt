
add_executable( hangman_test test_word.cpp )
target_link_libraries( hangman_test PRIVATE GTest::gtest_main )
target_link_libraries( hangman_test PRIVATE hangman_lib )

include(GoogleTest)
gtest_discover_tests(hangman_test)