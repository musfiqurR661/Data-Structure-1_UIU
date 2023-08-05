#include <stdio.h>
using namespace std;
int stack[100], top;

void push(int a) {
    int n = 100;
    if (top >= n - 1) {
        printf("\n Stack is Overflow");
        return;
    } else
        top++;
    stack[top] = a;
}

int pop() {
    int y;
    if (top <= -1) {
        printf("\n Stack is Underflow");
    } else {
        y = stack[top];
        top--;
        return y;
    }
    return 0;
}
int peek() {
if(top==-1 )
{
    printf("\n Stack is Empty");
    return -1;
}
else
    return stack[top];

}

int isEmpty() {
    if ( top==-1 )
    {
        return 1;
    }
    else
    return 0;
}

int main() {
    top = -1;
   /* push(20);
    push(1);
    push(15);
    pop();
    pop();
    pop();

    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    */
    //user input
     int num, item;
      char choice;
    printf("Enter the number of elements to push onto the stack: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &item);
        push(item);
    }

    printf("\nElements in the stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }

 printf("\n");

    printf("\nDo you want to pop an element from the stack? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        int popped = pop();
        if (popped != -1) {
            printf("Popped item: %d\n", popped);
        }

        printf("\nDo you want to pop another element from the stack? (y/n): ");
        scanf(" %c", &choice);
    }


    printf("\nTopmost item: %d\n", peek());

    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");
}
