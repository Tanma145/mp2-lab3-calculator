#include "gtest.h"
#include "..\mp2-lab3-calculator\TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
    ASSERT_NO_THROW(TCalculator c);
}
TEST(TCalculator, can_set_and_get_expression)
{
    TCalculator c;
    c.SetExpr("2 + 2");
    EXPECT_EQ("2 + 2", c.GetExpr());
}
TEST(TCalculator, can_make_postfix)
{
    TCalculator c;
    c.SetExpr("2 + 2");
    c.ToPostfix();
    ASSERT_NO_THROW(c.GetPostfix());
}
TEST(TCalculator, throws_when_wrong_number_of_brackets)
{
    TCalculator c;
    c.SetExpr("2 + 2)");
    EXPECT_FALSE(c.CheckBrackets());
}
TEST(TCalculator, throws_when_incorrect_expression)
{
    TCalculator c;
    c.SetExpr("f");
    ASSERT_ANY_THROW(c.Calc());
}