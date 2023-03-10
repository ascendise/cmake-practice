#ifndef STACKH
#define STACKH

#define STACK_NO_ERROR 0
#define STACK_EMPTY_ERROR -1

typedef struct Stack Stack;

extern Stack* stack_init();
extern void stack_free(Stack* stack);
extern void stack_push(Stack* stack, int value);
extern int stack_pop(Stack* stack, int* retValue);
extern int stack_peek(Stack* stack, int* retValue);
extern int stack_length(Stack* stack);

#endif