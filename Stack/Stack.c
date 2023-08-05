#include <stdio.h>
int stack[100], top;
void push(int x)
{
    int n = 100;
    if (top >= n - 1)
    {
        printf("\n Stack is Overflow");
        return;
    }
    else
        top++;
    stack[top] = x;
}
int pop()
{
    int y;
    if (top <= -1)
    {
        printf("\n Underflow");
    }
    else
    {
        y = stack[top];
        top--;
        return y;
    }
}

int main()
{

    top = -1;
    push(20);
    push(1);
    push(15);
   pop();
    pop();
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
}