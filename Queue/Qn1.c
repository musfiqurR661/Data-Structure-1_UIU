#include <stdio.h>

#define Qsize 5

int myQ[Qsize];
int front = -1;
int rear = -1;

void enqueue(int item)
{
    if ((rear + 1) % Qsize == front)
    {
        printf("Queue Overflow: Cannot enqueue. Queue is full.\n");
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % Qsize;
    }

    myQ[rear] = item;
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow: Cannot dequeue. Queue is empty.\n");
        return -1; // Return a special value to indicate underflow
    }

    int item = myQ[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % Qsize;
    }

    return item;
}

int frontElement()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
        return -1; // Return a special value to indicate an empty queue
    }

    return myQ[front];
}

int isEmpty()
{
    return (front == -1 && rear == -1);
}

int main()
{
    int i, numElements, element;

    printf("Enter the number of elements to enqueue (up to %d)\n", Qsize);
    scanf("%d", &numElements);

    if (numElements > Qsize)
    {
        printf("Number of elements exceeds queue size. Exiting.\n");
        return 1;
    }

    for (i = 0; i < numElements; i++)
    {
        printf("Enter element %d\n", i + 1);
        scanf("%d", &element);

        enqueue(element);
    }

    printf("Front element: %d\n", frontElement());

    // printf("Dequeuing elements:\n");
    // while (!isEmpty())
    // {
    //     int value = dequeue();
    //     printf("%d\n", value);
    // }

    // if (isEmpty())
    // {
    //     printf("Queue is empty.\n");
    // }


printf("Dequeuing elements:\n");
    for (i = 0; i < numElements; i++)
    {
        int value = dequeue();
        if (value != -1)
        {
            printf("%d\n", value);
        }
    }

    if (isEmpty())
    {
        printf("Queue is empty.\n");
    }
    return 0;
}
