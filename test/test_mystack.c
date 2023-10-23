#include "vendor/unity.h"
#include "../src/mystack.h"
#include <stdlib.h>

MyStack* stack;

void setUp(void) {
    stack = stack_create();
}

void tearDown(void) {
    stack_delete(stack);
}




void test_stack_create(void)
{
  TEST_ASSERT_NOT_NULL(stack);
  TEST_ASSERT_EQUAL_INT(-1, stack->top);

  for (size_t i = 0; i < MAX_STACK_SIZE; i++) {
    TEST_ASSERT_EQUAL_INT_MESSAGE(0, stack->data[i], "data should be 0");
  }
}

void test_push_stack_valid_data_count(){
  stack_push(stack, 5);
  TEST_ASSERT_EQUAL_INT(0, stack->top);
  TEST_ASSERT_EQUAL_INT(5, stack->data[0]);
}


void test_stack_push_stack_is_full_so_false_gets_returned(){
  // GIVEN a full stack
  for(int i = 0; i < MAX_STACK_SIZE; i++)
  {
    stack_push(stack, i*10);
  }
  // WHEN i no eapas dazua push
  bool retVal = stack_push(stack, 12);

  // THEN returns false
  TEST_ASSERT_FALSE(retVal);
}

void test_stack_push_success_so_true_gets_returned(){
  // GIVEN an empty stack

  // WHEN i no eapas dazua push
  bool retVal = stack_push(stack, 12);

  // THEN returns false
  TEST_ASSERT_TRUE(retVal);
}

void test_stack_pop_testing_last_element_was_pushed(){
  // GIVEN a full stack
  int expected = 15;
  for(int i = 0; i < 16; i ++)
  {
    stack_push(stack, i);
  }
  // WHEN we pop the last element
  int val = 0;
  stack_pop(stack, &val);
  // THEN ob die zahl ou des war was dinna wahr
  TEST_ASSERT_EQUAL_INT(expected, val);
}



int main(void)
{
   UnityBegin("MyStack");

  RUN_TEST(test_stack_create);
  RUN_TEST(test_push_stack_valid_data_count);
  RUN_TEST(test_stack_push_stack_is_full_so_false_gets_returned);
  RUN_TEST(test_stack_push_success_so_true_gets_returned);
  RUN_TEST(test_stack_pop_testing_last_element_was_pushed);
   UnityEnd();
   return 0;
}
