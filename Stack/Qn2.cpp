#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct Node *top;

void push(int data)
{
    struct Node *temp; // newItem(data);
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory(heap) is full.
    if (!temp)
    {
        printf("\n Heap Overflow");
        exit(1);
    }
    temp->value = data;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct Node *temp;
    int data;
    if (top == NULL)
    {
        printf("Underflow");
        exit(1);
    }
    else
    {
        data = top->value;
        temp = top;
        top = top->next;
        free(temp);
        return data;
    }
}
int peek()
{
    if (top == NULL)
    {
        printf("Underflow");
        exit(1);
    }
    else
    {
        return top->value;
    }
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    top = NULL;

    push(20);
    push(1);
    push(15);
    push(10);
    push(23);
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    printf("\nTopmost item: %d\n", peek());

    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");
}