#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};

struct node* top;

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void push(int data)
{
    struct node* newItem = (struct node*)malloc(sizeof(struct node));
    if (!newItem)
    {
        printf("Overflow\n");
        return;
    }
    newItem->value = data;
    newItem->next = top;
    top = newItem;
    return;
}

int pop()
{
    if (isEmpty() == 1)
    {
        printf("Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int data = top->value;
    top = top->next;
    free(temp);
    return data;
}

int peek()
{
    if (isEmpty() == 1)
    {
        printf("Empty\n");
        return -1;
    }
    return top->value;
}

int main()
{
    top = NULL;
    push(10);
    push(20);
    push(30);
    push(40);

    struct node* temp = top;
    while (temp != NULL)
    {
        if (temp->next != NULL)
            printf("%d, ", temp->value);
        else
            printf("%d\n", temp->value);
        temp = temp->next;
    }

    printf("%d\n", pop());
    printf("%d\n", peek());
    push(50);

    printf("%d\n", isEmpty());

    return 0;
}
