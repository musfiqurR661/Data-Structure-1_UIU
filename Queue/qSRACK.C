#include<stdio.h>
int stack[100],top;

void push(int x)
{
	if(top >= 99)
    {
        printf("\n STACK over flow");
    }
	else
    {
        top=top+1;
        stack[top] = x;
    }
}

int pop() {
    int y;
    if(top <= -1)
        printf("\n Stack under flow");
    else {
        y = stack[top];
        top--;
        return y;
    }
  return  -1;
}


int main()
{
    top=-1;
    push(20);
    push(1);
    push(15);

    //pop();
    // pop();
    // pop();
    // pop();

    for(int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }

    return 0;
}