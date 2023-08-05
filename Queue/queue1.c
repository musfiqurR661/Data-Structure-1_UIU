
#include <stdio.h>
int front = -1;
int rear = -1;
#define Qsize 3
int myQ[Qsize];

void enqueue(int data)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        myQ[rear] = data;
    }
    else if ((rear + 1) % Qsize == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear = (rear + 1) % Qsize;
        myQ[rear] = data;
    }
    // Print the enqueued element
    printf("Enqueued: %d\n", data);
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
        return -1; // Return a special value to indicate underflow
    }
    else if (front == rear)
    {
        int data = myQ[front];
        front = -1;
        rear = -1;
        return data;
    }
    else
    {
        int data = myQ[front];
        front = (front + 1) % Qsize;
        return data;
    }
}

int main()
{
    int i, numElements, element;

    printf("Enter the number of elements (up to %d)\n", Qsize);
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


    printf("Dequeuing elements:\n");
    for (i = 0; i < numElements; i++)
    {
        int value = dequeue();
        if (value != -1)
        {
            printf("%d\n", value);
        }
    }

    return 0;
}
