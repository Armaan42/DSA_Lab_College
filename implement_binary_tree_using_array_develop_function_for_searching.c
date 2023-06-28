#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to create a new node with the given data
int* createNode(int data) {
    int* newNode = (int*)malloc(sizeof(int));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    *newNode = data;
    return newNode;
}

// Function to insert a node into the binary search tree
void insertNode(int tree[], int index, int data) {
    if (tree[index] == -1) {
        tree[index] = data;
        printf("Inserted element: %d\n", data);
    } else if (data < tree[index]) {
        insertNode(tree, 2 * index + 1, data);
    } else if (data > tree[index]) {
        insertNode(tree, 2 * index + 2, data);
    } else {
        printf("Element already exists in the tree: %d\n", data);
    }
}

// Function to search for a key in the binary search tree
int search(int tree[], int index, int key) {
    if (tree[index] == -1 || tree[index] == key) {
        return tree[index];
    }

    if (key < tree[index]) {
        return search(tree, 2 * index + 1, key);
    } else {
        return search(tree, 2 * index + 2, key);
    }
}

int main() {
    int tree[MAX_SIZE];

    // Initialize the tree with -1 (empty nodes)
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }

    // Insert nodes into the binary search tree
    insertNode(tree, 0, 50);
    insertNode(tree, 0, 30);
    insertNode(tree, 0, 20);
    insertNode(tree, 0, 40);
    insertNode(tree, 0, 70);
    insertNode(tree, 0, 60);
    insertNode(tree, 0, 80);

    // Search for a key in the binary search tree
    int searchKey = 40;
    int searchResult = search(tree, 0, searchKey);
    if (searchResult == -1) {
        printf("Node with key %d not found.\n", searchKey);
    } else {
        printf("Node with key %d found.\n", searchKey);
    }

    return 0;
}

