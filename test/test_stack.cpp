#include "gtest.h"

#include "..\mp2-lab3-calculator\TStack.h"



TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> st(3));
}
