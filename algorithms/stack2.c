//
// Created by revanth on 24.11.25.
//
#define SIZ 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Stack
{
    int data[SIZ];
    int top;
}Stk;

void push(struct Stack *s, int data)
{
    if (s->top == SIZ - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->top++;
        s->data[s->top] = data;
    }
}

int pop(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return s->data[s->top--];
    }
}
void stack_init(struct Stack *s)
{
    s->top = -1;
}

int peek(struct Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return s->data[s->top];
    }
}
bool isEmpty(const struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

bool isFull(const struct Stack *s)
{
    if (s->top == SIZ - 1)
    {
        return 1;
    }
    return 0;
}

void reverseString(char *s) {
    /**
     * Reverses a string by pushing all characters onto a stack and then popping them
     * back into the original string array.
     */
    printf("\n--- Reversing String ---\n");

    Stk stack;
    stack_init(&stack);
    int len = strlen(s);

    // 1. Push all characters onto the stack
    int i;
    for (i = 0; i < len; i++) {
        // We can skip the push check here for simplicity if we ensure MAX_SIZE is large enough
        // but for safety, the Stack implementation handles isFull.
        push(&stack, s[i]);
    }

    // 2. Pop all characters back out (they will be in reverse order)
    for (i = 0; i < len; i++) {
        s[i] = pop(&stack);
    }
}


int main()
{
    Stk my_stack;
    stack_init(&my_stack);

    char s[] = "Home is good";
    char* aa;



    aa = strtok(s," ");
    while (aa != NULL)
    {
        printf("%s\n",aa);
        aa = strtok(NULL," ");
    }





    printf("Is stack empty? %s\n", isEmpty(&my_stack) ? "True" : "False");

    push(&my_stack, 100);
    push(&my_stack, 200);

    printf("Top element (peek): %d\n", peek(&my_stack));

    push(&my_stack, 'C');

    printf("Is stack full? %s\n", isFull(&my_stack) ? "True" : "False");

    // Pop elements
    printf("Poped element (Pop): %d\n",pop(&my_stack));
    printf("Poped element (Pop): %d\n",pop(&my_stack));

    printf("Top element (peek): %d\n", peek(&my_stack));

    printf("Poped element (): %d\n",pop(&my_stack));

    char original_string[] = "HelloC";
    printf("Original String: '%s'\n", original_string);
    reverseString(original_string);
    printf("Reversed String: '%s'\n", original_string);

    // This will generate an Error message because the stack is empty
    printf("Poped element (): %d\n",pop(&my_stack) == -1 ? '\0' : peek(&my_stack));
    char another_string[] = "DataStructure";
    printf("\nOriginal String: '%s'\n", another_string);
    reverseString(another_string);
    printf("Reversed String: '%s'\n", another_string);
}


