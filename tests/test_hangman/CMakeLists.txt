add_executable(
  hangman_test
  test_word.cpp
)
target_link_libraries(
  hangman_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hangman_test)