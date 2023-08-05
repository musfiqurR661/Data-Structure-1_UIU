#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the queue is empty
int isEmpty(struct Node* front) {
    return (front == NULL);
}

// Function to enqueue an integer item into the queue
void enqueue(struct Node** front, struct Node** rear, int item) {
    struct Node* newNode = createNode(item);

    // If the queue is empty, set both front and rear to the new node
    if (*front == NULL) {
        *front = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        (*rear)->next = newNode;
    }
    *rear = newNode;
}

// Function to dequeue and return the front item from the queue
int dequeue(struct Node** front) {
    if (isEmpty(*front)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate failure
    }

    // Store the front node and its data
    struct Node* frontNode = *front;
    int frontItem = frontNode->data;

    // Update the front pointer to the next node and free the old front node
    *front = (*front)->next;
    free(frontNode);

    return frontItem;
}

// Function to return the front item from the queue without removing it
int getFront(struct Node* front) {
    if (isEmpty(front)) {
        printf("Queue is empty. No front item.\n");
        return -1; // Return a sentinel value to indicate failure
    }
    return front->data;
}

// Function to free the memory used by the queue
void freeQueue(struct Node** front) {
    while (!isEmpty(*front)) {
        dequeue(front);
    }
}

int main() {
    // Initialize the front and rear pointers
    struct Node* frontNode = NULL;
    struct Node* rear = NULL;

    // Enqueue some elements
    enqueue(&frontNode, &rear, 10);
    enqueue(&frontNode, &rear, 20);
    enqueue(&frontNode, &rear, 30);

    // Dequeue elements and print them
    printf("Dequeued item: %d\n", dequeue(&frontNode));
    printf("Dequeued item: %d\n", dequeue(&frontNode));
  printf("Dequeued item: %d\n", dequeue(&frontNode));

    // Check if the queue is empty and print the front item
    printf("Is queue empty? %d\n", isEmpty(frontNode));
    printf("Front item: %d\n", getFront(frontNode));

    // Dequeue the last element
    printf("Dequeued item: %d\n", dequeue(&frontNode));

    // Check if the queue is empty after dequeuing all elements
    printf("Is queue empty? %d\n", isEmpty(frontNode));

    // Free the memory used by the queue
    freeQueue(&frontNode);

    return 0;
}
