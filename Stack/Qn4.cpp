#include<bits/stdc++.h>
using namespace std;

struct Node {
int value;
struct Node* next;
};

struct Node* top;

void push(int data) {
	struct Node* temp;
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory(heap) is full.
     if (!temp){
    printf("\n Heap Overflow");
    exit(1);
    }
    temp->value = data;
    temp->next = top;
    top = temp;
}

int pop(){
    struct Node* temp;
    int data;
    if (top == NULL) {
    printf("\n Stack Underflow" );
    exit(1);
    }
    else {
    data = top->value;
    temp = top;
    top = top->next;
    free(temp);
    return data;
    }
}

int main()
{
    string s;

    cin>>s;

    // for(int i=0;i<s.size();i++)
    // {
    //     if(s[i]=='('||s[i]=='{'||s[i]=='[')
    //     {
    //         push(s[i]);
    //     }
    //     else
    //     {
    //          if(s[i]==')'&& pop() !='(')
    //         {
    //             cout<<"Invalid"<<endl;
    //             return 0;
    //         }
    //          if(s[i]==']'&& pop() !='[')
    //         {
    //             cout<<"Invalid"<<endl;
    //             return 0;
    //         }
             
    //          if(s[i]=='}'&& pop() !='{')
    //         {
    //             cout<<"Invalid"<<endl;
    //             return 0;
    //         }
    //     }
    // }

    // cout<<"Valid"<<endl;

    // return 0;
 for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(s[i]);
        }
        else {
            if (top == NULL) { // Added a check here to ensure stack is not empty
                cout << "Invalid" << endl;
                return 0;
            }
            if (s[i] == ')' && pop() != '(') {
                cout << "Invalid" << endl;
                return 0;
            }
            if (s[i] == ']' && pop() != '[') {
                cout << "Invalid" << endl;
                return 0;
            }
            if (s[i] == '}' && pop() != '{') {
                cout << "Invalid" << endl;
                return 0;
            }
        }
    }

    if (top != NULL) { // Added a check here to ensure stack is empty
        cout << "Invalid" << endl;
    }
    else {
        cout << "Valid" << endl;
    }

    return 0;

}