#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element.\n");
        return;
    }

    stack->top++;
    stack->arr[stack->top] = element;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element.\n");
        return -1;
    }

    int element = stack->arr[stack->top];
    stack->top--;

    return element;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* postfix) {
    Stack stack;
    initializeStack(&stack);

    int i = 0;
    while (postfix[i] != '\0') {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to int and push onto stack
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }

        i++;
    }

    return pop(&stack);
}

// Function to evaluate a prefix expression
int evaluatePrefix(char* prefix) {
    Stack stack;
    initializeStack(&stack);

    int i = 0;
    int len = 0;
    while (prefix[len] != '\0') {
        len++;
    }

    for (i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to int and push onto stack
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

// Function to evaluate an infix expression
int evaluateInfix(char* infix) {
    Stack stack;
    initializeStack(&stack);

    int i = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to int and push onto stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int precedence = 0;

            switch (ch) {
                case '+':
                case '-':
                    precedence = 1;
                    break;
                case '*':
                case '/':
                    precedence = 2;
                    break;
            }

            while (!isEmpty(&stack) && stack.arr[stack.top] != '(' &&
                   precedence <= stack.arr[stack.top]) {
                int operand2 = pop(&stack);
                int operand1 = pop(&stack);

                switch (stack.arr[stack.top]) {
                    case '+':
                        push(&stack, operand1 + operand2);
                        break;
                    case '-':
                        push(&stack, operand1 - operand2);
                        break;
                    case '*':
                        push(&stack, operand1 * operand2);
                        break;
                    case '/':
                        push(&stack, operand1 / operand2);
                        break;
                }
            }

            push(&stack, ch);
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&stack) && stack.arr[stack.top] != '(') {
                int operand2 = pop(&stack);
                int operand1 = pop(&stack);
                char operator = pop(&stack);

                switch (operator) {
                    case '+':
                        push(&stack, operand1 + operand2);
                        break;
                    case '-':
                        push(&stack, operand1 - operand2);
                        break;
                    case '*':
                        push(&stack, operand1 * operand2);
                        break;
                    case '/':
                        push(&stack, operand1 / operand2);
                        break;
                }
            }

            if (!isEmpty(&stack) && stack.arr[stack.top] == '(') {
                pop(&stack); // Discard the opening parenthesis
            }
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        int operand2 = pop(&stack);
        int operand1 = pop(&stack);
        char operator = pop(&stack);

        switch (operator) {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
        }
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[MAX_SIZE];
    char prefixExpression[MAX_SIZE];
    char infixExpression[MAX_SIZE];

    // Input the postfix expression
    printf("Enter the postfix expression: ");
    scanf("%s", postfixExpression);

    // Evaluate the postfix expression
    int postfixResult = evaluatePostfix(postfixExpression);
    printf("Postfix expression result: %d\n", postfixResult);

    // Input the prefix expression
    printf("Enter the prefix expression: ");
    scanf("%s", prefixExpression);

    // Evaluate the prefix expression
    int prefixResult = evaluatePrefix(prefixExpression);
    printf("Prefix expression result: %d\n", prefixResult);

    // Input the infix expression
    printf("Enter the infix expression: ");
    scanf("%s", infixExpression);

    // Evaluate the infix expression
    int infixResult = evaluateInfix(infixExpression);
    printf("Infix expression result: %d\n", infixResult);

    return 0;
}

