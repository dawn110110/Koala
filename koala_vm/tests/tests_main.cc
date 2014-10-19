#include "style_sample.hpp"
#include "gtest/gtest.h"

namespace {

class NageSirenKoalaTest : public ::testing::Test {
};

TEST_F(NageSirenKoalaTest, JustGtestSample) {
    koala::code_style_sample::NageSirenKoala foo;
    auto result = foo.add_int(1, 2);
    ASSERT_EQ(4, result);
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
