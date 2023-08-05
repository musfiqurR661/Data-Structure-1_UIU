#include <stdio.h>

int stack1[100], stack2[100];
int top1, top2;

// Function to push an element into stack1
void push1(int x)
{
    if (top1 >= 99)
    {
        printf("\n STACK1 overflow");
    }
    else
    {
        top1++;
        stack1[top1] = x;
    }
}

// Function to pop an element from stack1
int pop1()
{
    int y;
    if (top1 <= -1)
    {
        printf("\n STACK1 underflow");
    }
    else
    {
        y = stack1[top1];
        top1--;
        return y;
    }
    return -1;
}

// Function to push an element into stack2
void push2(int x)
{
    if (top2 >= 99)
    {
        printf("\n STACK2 overflow");
    }
    else
    {
        top2++;
        stack2[top2] = x;
    }
}

// Function to pop an element from stack2
int pop2()
{
    int y;
    if (top2 <= -1)
    {
        printf("\n STACK2 underflow");
    }
    else
    {
        y = stack2[top2];
        top2--;
        return y;
    }
    return -1;
}

// Function to check if stack1 is empty
int isEmptyStack1()
{
    return top1 == -1;
}

// Function to check if stack2 is empty
int isEmptyStack2()
{
    return top2 == -1;
}

// Function to enqueue an element into the queue
void enqueue(int x)
{
    push1(x);
}

// Function to dequeue an element from the queue
int dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        printf("\n Queue underflow\n");
        return -1;
    }

    if (top2 == -1)
    {
        while (top1 != -1)
        {
            push2(pop1());
        }
    }

    int element = pop2();
    return element;
}

// Function to check if the queue is empty
int isEmptyQueue()
{
    return top1 == -1 && top2 == -1;
}

void display()
{
    int temp1 = top1;
    int temp2 = top2;

    if (top1 == -1 && top2 == -1)
    {
        printf("\n Queue is empty");
        return;
    }
    if (top2 == -1)
    {
        while (temp1 != -1)
        {
            printf("%d\n", stack1[temp1]);
            temp1--;
        }
    }
    else
    {
        while (temp2 != -1)
        {
            printf("%d\n", stack2[temp2]);
            temp2--;
        }
    }
}


int main()
{
    top1 = -1;
    top2 = -1;

    enqueue(20);
    enqueue(1);
    enqueue(15);

    printf("Queue elements:\n");
    display();

  //  dequeue();
    printf("Dequeued element: %d\n", dequeue());

    printf("Queue elements after dequeue:\n");
    display();

    return 0;
}
