#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
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

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

// Function to delete a node with the given key from the circular linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete node.\n");
        return;
    }

    Node* current = *head;
    Node* previous = NULL;

    // Check if the key is found in the first node
    if (current->data == key && current->next == *head) {
        *head = NULL;
        free(current);
        printf("Node with key %d deleted.\n", key);
        return;
    }

    Node* lastNode = *head;
    while (lastNode->next != *head) {
        lastNode = lastNode->next;
    }

    int isKeyFound = 0;
    if (current->data == key) {
        *head = current->next;
        lastNode->next = *head;
        isKeyFound = 1;
    } else if (current->next == *head) {
        printf("Node with key %d not found.\n", key);
        return;
    } else {
        while (current->next != *head) {
            if (current->data == key) {
                isKeyFound = 1;
                break;
            }
            previous = current;
            current = current->next;
        }
    }

    if (isKeyFound) {
        previous->next = current->next;
        free(current);
        printf("Node with key %d deleted.\n", key);
    } else {
        printf("Node with key %d not found.\n", key);
    }
}

// Function to perform a linear search for a given key in the circular linked list
Node* linearSearch(Node* head, int key) {
    if (head == NULL) {
        return NULL;
    }

    Node* current = head;
    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return NULL;
}

// Function to display the circular linked list
void displayLinkedList(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = head;
    printf("Circular linked list: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    displayLinkedList(head);

    // Insert nodes at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    displayLinkedList(head);

    // Delete a node
    deleteNode(&head, 20);
    displayLinkedList(head);

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

