#include <gtest/gtest.h>

#include <maths/maths.h>

TEST(maths, addTest)
{
    Maths::calc_status sc{};
    const int          result = Maths::add(42, 11, sc);
    EXPECT_EQ(sc, Maths::calc_status::success);
    EXPECT_EQ(result, 42 + 11);
}

TEST(maths, subTest)
{
    Maths::calc_status sc{};
    const int          result = Maths::subtract(42, 11, sc);
    EXPECT_EQ(sc, Maths::calc_status::success);
    EXPECT_EQ(result, 42 - 11);
}
