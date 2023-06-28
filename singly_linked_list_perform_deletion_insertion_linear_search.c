#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
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

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
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
    }
}

// Function to delete a node with the given key from the linked list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete node.\n");
        return;
    }

    Node* current = *head;
    Node* previous = NULL;

    // Check if the key is found in the first node
    if (current->data == key) {
        *head = current->next;
        free(current);
        printf("Node with key %d deleted.\n", key);
        return;
    }

    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }

    previous->next = current->next;
    free(current);
    printf("Node with key %d deleted.\n", key);
}

// Function to perform a linear search for a given key in the linked list
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

// Function to display the linked list
void displayLinkedList(Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
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
    deleteNode(&head, 30);
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

