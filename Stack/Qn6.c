#include <stdio.h>

int stack[100], top;

void push(int x) {
    int n = 100;
    if (top >= n - 1) {
        printf("\n Stack is Overflow");
        return;
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    int y;
    if (top <= -1) {
        printf("\n Underflow");
    } else {
        y = stack[top];
        top--;
        return y;
    }
}

// Declare insertAtBottom function before using it in reverseStack
void insertAtBottom(int item);

// Recursive function to reverse the stack
void reverseStack() {
    if (top == -1) {
        return; // Base case: stack is empty
    } else {
        int x = pop(); // Pop the top element
        reverseStack(); // Recursively reverse the remaining stack
        insertAtBottom(x); // Insert the popped element at the bottom
    }
}

// Recursive function to insert an element at the bottom of the stack
void insertAtBottom(int item) {
    if (top == -1) {
        push(item); // Base case: stack is empty, push the item
    } else {
        int x = pop(); // Pop the top element
        insertAtBottom(item); // Recursively insert the item at the bottom
        push(x); // Push the popped element back on the stack
    }
}

int main() {
    top = -1;
    push(1);
    push(2);
    push(3);
    push(4);

    printf("Input: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    reverseStack();

    printf("Output: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}
