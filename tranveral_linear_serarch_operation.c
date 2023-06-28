#include <stdio.h>

#define MAX_SIZE 100

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform linear search in the array
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    int arr[MAX_SIZE];
    int size, key, index;

    // Input the size of the array
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Input the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the array
    displayArray(arr, size);

    // Input the key to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform linear search
    index = linearSearch(arr, size, key);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}

