#include "stdio.h"
#include "stack.h"

int main() {
    Stack* stack = stack_init();
    for(int i = 0; i < 10000; i++) {
        stack_push(stack, i);
    }
    for(int i = 0; i <= stack_length(stack); i++) {
        int retValue;
        stack_pop(stack, &retValue);
    }
    stack_free(stack);
}