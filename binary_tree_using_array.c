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

// Function to insert a node into the binary tree
void insertNode(int tree[], int index, int data) {
    if (tree[index] == -1) {
        tree[index] = data;
        printf("Inserted element: %d\n", data);
    } else {
        printf("Node at index %d is not empty.\n", index);
    }
}

// Function to perform a pre-order traversal of the binary tree (root-left-right)
void preorderTraversal(int tree[], int index) {
    if (tree[index] != -1) {
        printf("%d ", tree[index]);
        preorderTraversal(tree, 2 * index + 1);
        preorderTraversal(tree, 2 * index + 2);
    }
}

int main() {
    int tree[MAX_SIZE];

    // Initialize the tree with -1 (empty nodes)
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }

    // Insert nodes into the binary tree
    insertNode(tree, 0, 10);
    insertNode(tree, 1, 20);
    insertNode(tree, 2, 30);
    insertNode(tree, 3, 40);
    insertNode(tree, 4, 50);

    // Perform a pre-order traversal of the binary tree
    printf("Pre-order traversal: ");
    preorderTraversal(tree, 0);
    printf("\n");

    return 0;
}

