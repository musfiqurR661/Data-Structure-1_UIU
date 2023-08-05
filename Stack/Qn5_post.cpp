#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

struct Node {
    int value;
    struct Node* next;
};

struct Node* top;

void push(int data) {
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory(heap) is full.
    if (!temp) {
        printf("\n Heap Overflow");
        exit(1);
    }
    temp->value = data;
    temp->next = top;
    top = temp;
}

int pop() {
    struct Node* temp;
    int data;
    if (top == NULL) {
        printf("Underflow");
        exit(1);
    } else {
        data = top->value;
        temp = top;
        top = top->next;
        free(temp);
        return data;
    }
}

int peek() {
    if (top == NULL) {
        printf("Underflow");
        exit(1);
    } else {
        return top->value;
    }
}

int isEmpty() {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int evaluatePostfix(string expression) {
    stack<int> st;
    stringstream ss(expression);

    string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            int num = stoi(token);
            push(num);
        } else {
            int operand2 = pop();
            int operand1 = pop();

            char op = token[0];
            int result;

            switch (op) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    cout << "Invalid operator: " << op << endl;
                    return -1;
            }

            push(result);
        }
    }

    return pop();
}

int main() {
    top = NULL;

    string postfixExpression;
    cout << "Enter the postfix expression: ";
    getline(cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
