#include <word.h>
#include <gtest/gtest.h>

class TestWord : public testing::Test {
    protected:
        Word * word;
};

TEST(HelloTest, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}