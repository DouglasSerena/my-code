#include <stdio.h>
#include <assert.h>

#include "./stack.h"

int main()
{
    Stack<int> stack = Stack<int>(5);

    // Checksstack initialization
    assert(stack.getMaxSize() == 5);
    assert(stack.getSize() == 0);

    // Checks if the value is pushed onto the stack
    stack.push(2);
    stack.push(6);
    stack.push(9);

    assert(stack.getSize() == 3);

    // Checks that the returned value is popped from the stack
    assert(stack.pop() == 9);
    assert(stack.getSize() == 2);

    // Checks that the returned value is not popped from the stack
    assert(stack.peek() == 6);
    assert(stack.getSize() == 2);

    // Checks if it contains value inside the stack
    assert(stack.contains(6) == true);
    assert(stack.contains(4) == false);

    // Checks if the stack is stuck full
    stack.push(10);
    stack.push(11);
    stack.push(12);

    assert(stack.isFull() == true);
    assert(stack.isEmpty() == false);

    // Checksif the stack overflows
    assert(stack.push(13) == StackError::IsFull);
    assert(stack.getSize() == 5);

    // Checksif the string representing the stack is correct
    assert(stack.toString() == "[ 2, 6, 10, 11, 12 ]");
    
    for (int v : list)
        printf("%i, ", v);

    // Checks if the stack is being emptied
    stack.clear();

    assert(stack.getSize() == 0);
    assert(stack.isFull() == false);
    assert(stack.isEmpty() == true);

    // Checks if the stack is validating if it is empty
    assert(stack.pop() == StackError::IsEmpty);

    return 0;
}