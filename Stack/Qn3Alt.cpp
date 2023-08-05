// #include<bits/stdc++.h>
// using namespace std;

// struct Node {
//     int value;
//     struct Node* next;
// };

// struct Node* top;

// void push(int data) {
//     struct Node* temp;
//     temp = (struct Node*)malloc(sizeof(struct Node));

//     // Check if memory(heap) is full.
//     if (!temp) {
//         printf("\n Heap Overflow");
//         exit(1);
//     }
//     temp->value = data;
//     temp->next = top;
//     top = temp;
// }

// int pop() {
//     struct Node* temp;
//     int data;
//     if (top == NULL) {
//         printf("\n Stack Underflow");
//         exit(1);
//     } else {
//         data = top->value;
//         temp = top;
//         top = top->next;
//         free(temp);
//         return data;
//     }
// }

// int main() {
//     string s;

//     cin >> s;

//     for (int i = 0; i < s.size(); i++) {
//         push(s[i]);
//     }

//     bool isPalindrome = true;
//     for (int i = 0; i < s.size(); i++) {
//         char c = pop();
//         if (s[i] != c) {
//             isPalindrome = false;
//             break;
//         }
//     }

//     if (isPalindrome) {
//         cout << "Palindrome" << endl;
//     } else {
//         cout << "Not a Palindrome" << endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

struct Node {
    char value;
    struct Node* next;
};

struct Node* top;

void push(char data) {
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

char pop() {
    struct Node* temp;
    char data;
    if (top == NULL) {
        printf("\n Stack Underflow");
        exit(1);
    } else {
        data = top->value;
        temp = top;
        top = top->next;
        free(temp);
        return data;
    }
}

int main() {
    string s;

    getline(cin, s); // Use getline() to read the entire sentence

    for (int i = 0; i < s.size(); i++) {
        char c = tolower(s[i]); // Convert all characters to lowercase
        if (isalpha(c)) { // Ignore spaces and punctuation
            push(c);
        }
    }

    bool isPalindrome = true;
    for (int i = 0; i < s.size(); i++) {
        char c = tolower(s[i]);
        if (isalpha(c)) { // Ignore spaces and punctuation
            char stackChar = pop();
            if (c != stackChar) {
                isPalindrome = false;
                break;
            }
        }
    }

    if (isPalindrome) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}

