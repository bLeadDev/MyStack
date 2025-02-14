#include "mystack.h"
#include <stddef.h>
#include <stdlib.h>

/*
* instantiates a new stack and returns a pointer to it.
* must be free'ed using stack_delete(...)
*/
MyStack* stack_create(){
  MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
  stack->top = -1;
  return stack;
}

/*
* deletes a given stack
*/
void stack_delete(MyStack* stack){

}

/*
* pushes the give element to the stack
* returns true if the push was successful,
* returns false if not (the stack is full)
*/
bool stack_push(MyStack* pStack, int data){
  pStack->top++;
  if(pStack->top >= MAX_STACK_SIZE){
    pStack->top--;
    return false;
  }
  pStack->data[pStack->top] = data;
  return true;
}

/*
* pops the top element from the stack and writes its value into
* the given value-pointer
* returns true if something was pop'ed
* returns false if the stack was empty
*/
bool stack_pop(MyStack* pStack, int* value){
  *value = pStack->data[pStack->top];
  return false;
}

/*
* writes the stack's top value into
* the given value-pointer without removing it
* returns true if the stack was not empty
* returns false if the stack was empty
*/
bool stack_peek(MyStack* stack, int* value){
  return false;
}

/*
* returns true if the stack is empty, otherwhise false
*/
bool stack_isEmpty(MyStack* stack){
  return false;
}
