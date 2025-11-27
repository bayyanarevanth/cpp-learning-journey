//
// Created by revanth on 24.11.25.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum size for the stack (adjust as needed)
#define MAX_SIZE 100

// --- 1. Stack Implementation (for characters) ---

typedef struct {
    char data[MAX_SIZE];
    int top; // Index of the top element
} Stack;

void initialize(Stack *s) {
    // Initialize the top pointer to -1, indicating an empty stack.
    s->top = -1;
}

bool isEmpty(Stack *s) {
    /** Checks if the stack is empty. */
    return s->top == -1;
}

bool isFull(Stack *s) {
    /** Checks if the stack is full based on MAX_SIZE. */
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char value) {
    /** Adds an item to the top of the stack (LIFO: Last-In). */
    if (isFull(s)) {
        printf("Error: Stack is full. Cannot push '%c'.\n", value);
        return;
    }
    // Increment top and then insert the element
    s->data[++s->top] = value;
    printf("Pushed: %c\n", value);
}

char pop(Stack *s) {
    /** Removes and returns the item at the top of the stack (LIFO: First-Out). */
    if (isEmpty(s)) {
        fprintf(stderr, "Error: Stack is empty. Cannot pop.\n");
        return '\0'; // Return null character to indicate failure
    }
    // Return the top element and then decrement top
    char popped_item = s->data[s->top--];
    printf("Popped: %c\n", popped_item);
    return popped_item;
}

char peek(Stack *s) {
    /** Returns the item at the top of the stack without removing it. */
    if (isEmpty(s)) {
        return '\0'; // Return null character if empty
    }
    return s->data[s->top];
}


// --- 2. Utility Functions Using the Stack ---

void reverseString(char *s) {
    /**
     * Reverses a string by pushing all characters onto a stack and then popping them
     * back into the original string array.
     */
    printf("\n--- Reversing String ---\n");

    Stack stack;
    initialize(&stack);
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


bool isBalanced(const char *s) {
    /**
     * Detects if the parentheses (and brackets/braces) in a string are balanced.
     * Returns true if balanced, false otherwise.
     */
    printf("\n--- Checking Balanced Parentheses ---\n");

    Stack stack;
    initialize(&stack);

    for (int i = 0; s[i] != '\0'; i++) {
        char current_char = s[i];

        // 1. If it's an opening bracket, push it onto the stack.
        if (current_char == '(' || current_char == '[' || current_char == '{') {
            push(&stack, current_char);
        }
        // 2. If it's a closing bracket, check for a match.
        else if (current_char == ')' || current_char == ']' || current_char == '}') {
            if (isEmpty(&stack)) {
                printf("Found closing '%c' but stack is empty. Unbalanced.\n", current_char);
                return false; // Closing bracket without a matching opening bracket
            }

            char top_char = pop(&stack);

            // Check for correct match
            if ((current_char == ')' && top_char != '(') ||
                (current_char == ']' && top_char != '[') ||
                (current_char == '}' && top_char != '{')) {
                printf("Found '%c' but expected matching closing bracket for '%c'. Unbalanced.\n", current_char, top_char);
                return false; // Mismatch
            }
        }
        // Ignore other characters
    }

    // 3. If the stack is empty at the end, all opening brackets were matched
    bool result = isEmpty(&stack);
    printf("Result: %s\n", result ? "Balanced" : "Unbalanced (unclosed opening brackets remain)");
    return result;
}

// --- Example Usage ---

int main() {

    printf("====================================================\n");
    printf("               STACK CLASS DEMONSTRATION\n");
    printf("====================================================\n");

    Stack my_stack;
    initialize(&my_stack);

    printf("Is stack empty? %s\n", isEmpty(&my_stack) ? "True" : "False");

    push(&my_stack, 'A');
    push(&my_stack, 'B');

    printf("Top element (peek): %c\n", peek(&my_stack));

    push(&my_stack, 'C');

    printf("Is stack full? %s\n", isFull(&my_stack) ? "True" : "False");

    // Pop elements
    pop(&my_stack);
    pop(&my_stack);

    printf("Top element (peek): %c\n", peek(&my_stack));

    pop(&my_stack);

    // This will generate an Error message because the stack is empty
    pop(&my_stack);

    printf("\n====================================================\n");
    printf("            STRING REVERSAL DEMONSTRATION\n");
    printf("====================================================\n");

    // Need a mutable char array for reversal, hence the array initialization
    char original_string[] = "HelloC";
    printf("Original String: '%s'\n", original_string);
    reverseString(original_string);
    printf("Reversed String: '%s'\n", original_string);

    char another_string[] = "DataStructure";
    printf("\nOriginal String: '%s'\n", another_string);
    reverseString(another_string);
    printf("Reversed String: '%s'\n", another_string);

    printf("\n====================================================\n");
    printf("         BALANCED PARENTHESES DEMONSTRATION\n");
    printf("====================================================\n");

    // Test cases
    const char *test_strings[] = {
        "([{}])",        // Balanced
        "([]){([])}",    // Balanced
        "([)]",          // Unbalanced (Mismatch)
        "((()))]",       // Unbalanced (Closing bracket mismatch)
        "{[()]",         // Unbalanced (Unclosed opening bracket)
        "}{",            // Unbalanced (Closing bracket first)
        ""               // Balanced (Empty string)
    };
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    for (int i = 0; i < num_tests; i++) {
        printf("\nString: '%s'\n", test_strings[i]);
        isBalanced(test_strings[i]);
    }

    return 0;
}