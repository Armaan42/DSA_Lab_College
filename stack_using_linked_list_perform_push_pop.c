#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node** top, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    newNode->next = *top;
    *top = newNode;
    printf("Pushed element: %d\n", data);
}

// Function to pop an element from the stack
void pop(Node** top) {
    if (*top == NULL) {
        printf("Stack is empty. Cannot pop element.\n");
        return;
    }

    Node* temp = *top;
    *top = (*top)->next;
    int poppedData = temp->data;
    free(temp);
    printf("Popped element: %d\n", poppedData);
}

// Function to display the elements in the stack
void displayStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* top = NULL;

    // Push elements onto the stack
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    displayStack(top);

    // Pop elements from the stack
    pop(&top);
    displayStack(top);

    pop(&top);
    displayStack(top);

    pop(&top);
    displayStack(top);

    pop(&top);  // Trying to pop from an empty stack

    return 0;
}

