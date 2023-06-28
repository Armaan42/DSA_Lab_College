#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue element.\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->arr[queue->rear] = element;
}

// Function to remove an element from the queue (dequeue)
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue element.\n");
        return -1;
    }

    int element = queue->arr[queue->front];

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return element;
}

// Function to display the elements in the queue
void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;
    printf("Queue elements: ");
    while (i != queue->rear) {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue->arr[i]);
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    // Display queue
    displayQueue(&queue);

    // Dequeue elements
    int dequeuedElement = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeuedElement);
    dequeuedElement = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeuedElement);

    // Display queue
    displayQueue(&queue);

    return 0;
}

