#include <stdio.h>

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

// Function to display the elements in the stack
void displayStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);

    // Pushing elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    displayStack(&stack);

    // Popping elements from the stack
    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);
    displayStack(&stack);

    return 0;
}

