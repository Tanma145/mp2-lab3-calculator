#include "gtest.h"

#include "..\mp2-lab3-calculator\TListStack.h"



TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> st(3));
}
TEST(TStack, throws_when_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(TStack<int> st(-3));
}TEST(TStack, can_create_copied_stack)
{
    TStack<int> st1(10);
    ASSERT_NO_THROW(TStack<int> st2(st1));
}
TEST(TStack, can_push_and_pop_element)
{
    TStack<int> st(5);
    st.Push(4);
    int a = st.Pop();
    EXPECT_EQ(4, a);
}
TEST(TStack, can_get_top_element)
{
    TStack<int> st(5);
    st.Push(4);
    EXPECT_EQ(4, st.Top());
}
TEST(TStack, throws_when_push_element_into_full_stack)
{
    TStack<int> st(1);
    st.Push(1);
    ASSERT_ANY_THROW(st.Push(2));
}
TEST(TStack, throws_when_pop_element_from_empty_stack)
{
    TStack<int> st(1);
    ASSERT_ANY_THROW(st.Pop());
}
TEST(TStack, empty_stack_is_empty)
{
    TStack<int> st(1);
    EXPECT_TRUE(st.IsEmpty());
}
TEST(TStack, not_empty_stack_is_not_empty)
{
    TStack<int> st(1);
    st.Push(1);
    EXPECT_FALSE(st.IsEmpty());
}
TEST(TStack, full_stack_is_full)
{
    TStack<int> st(1);
    st.Push(1);
    EXPECT_TRUE(st.IsFull());
}
TEST(TStack, not_full_stack_is_not_full)
{
    TStack<int> st(1);
    EXPECT_FALSE(st.IsFull());
}