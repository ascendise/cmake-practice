#include "stack.h"
#include "stdlib.h"


typedef struct Element {
    int value;
    struct Element* lastElement;
} Element;

struct Stack {
    int length;
    Element* top;
};

Stack* stack_init() {
    Stack* stack = malloc(sizeof(Stack));
    stack->length = 0;
    stack->top = NULL;
    return stack;
}

void stack_free(Stack* stack) {
    Element* top = stack->top;
    while(top) {
        Element* next = top->lastElement;
        free(top);
        top = next;
    }
    free(stack);
}

void stack_push(Stack* stack, int value) {
    Element* element = malloc(sizeof(Element));
    element->value = value;
    element->lastElement = stack->top;
    stack->top = element;
    stack->length++;
}

int stack_pop(Stack* stack, int* retValue) {
    Element* top = stack->top;
    if(!stack->top) {
        return STACK_EMPTY_ERROR;
    }
    *retValue = top->value;
    stack->top = top->lastElement;
    stack->length--;
    free(top);
    return STACK_NO_ERROR;
}

int stack_peek(Stack* stack, int* retValue) {
    if(!stack->top) {
        return STACK_EMPTY_ERROR;
    }
    *retValue = stack->top->value;
    return STACK_NO_ERROR;
}

int stack_length(Stack* stack) {
    return stack->length;
}