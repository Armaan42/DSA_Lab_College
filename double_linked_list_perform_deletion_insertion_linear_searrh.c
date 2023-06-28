#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to delete a node with the given key from the doubly linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete node.\n");
        return;
    }

    Node* current = *head;

    // Check if the key is found in the first node
    if (current->data == key) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        printf("Node with key %d deleted.\n", key);
        return;
    }

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with key %d deleted.\n", key);
}

// Function to perform a linear search for a given key in the doubly linked list
Node* linearSearch(Node* head, int key) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to display the doubly linked list in forward direction
void displayForward(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = head;
    printf("Doubly linked list (forward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to display the doubly linked list in backward direction
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("Doubly linked list (backward): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    displayForward(head);
    displayBackward(head);

    // Insert nodes at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    displayForward(head);
    displayBackward(head);

    // Delete a node
    deleteNode(&head, 20);
    displayForward(head);
    displayBackward(head);

    // Search for a node
    int searchKey = 40;
    Node* searchResult = linearSearch(head, searchKey);
    if (searchResult != NULL) {
        printf("Node with key %d found.\n", searchKey);
    } else {
        printf("Node with key %d not found.\n", searchKey);
    }

    return 0;
}

