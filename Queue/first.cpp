#include <stdio.h>

int front = -1;
int rear = -1;
#define Qsize 3
int myQ[Qsize];

void enqueue(int data)
{
   if ((rear + 1) % Qsize == front)
   {
       printf("Queue Overflow\n");
   }
   else
   {
       if (front == -1)
           front = 0;
       rear = (rear + 1) % Qsize;
       myQ[rear] = data;
   }
}

int dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
        return -1; // Return a special value to indicate underflow
    }
    int dequeuedElement = myQ[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % Qsize;
    }
    return dequeuedElement;
}

int main()
{
    int i, data;
    printf("Enter the number of elements\n");
    scanf("%d", &data);
    for (i = 0; i < data; i++)
    {
        printf("Enter the element\n");
        scanf("%d", &data);
        enqueue(data);
    }
    for (i = 0; i < Qsize; i++)
    {
        int dequeuedValue = dequeue();
        if (dequeuedValue != -1)
        {
            printf("%d\n", dequeuedValue);
        }
    }
    return 0;
}