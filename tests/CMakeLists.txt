include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

add_executable(
  hangman_test
  hello_test.cc
)
target_link_libraries(
  hangman_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hangman_test)