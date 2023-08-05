#include <stdio.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue full. Cannot enqueue %d.\n", item);
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    circularQueue[rear] = item;
    printf("%d enqueued.\n", item);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue empty. Cannot dequeue.\n");
        return -1;
    }

    int item = circularQueue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

int getFront() {
    if (isEmpty()) {
        printf("Queue empty.\n");
        return -1;
    }
    return circularQueue[front];
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    int frontItem = getFront();
    printf("Front item: %d\n", frontItem);

    int dequeuedItem = dequeue();
    printf("Dequeued item: %d\n", dequeuedItem);

    enqueue(4);
    enqueue(5);
    enqueue(6);

    int isQueueFull = isFull();
    printf("Queue full? %s\n", isQueueFull ? "Yes" : "No");

    while (!isEmpty()) {
        printf("Dequeued item: %d\n", dequeue());
    }

    return 0;
}
