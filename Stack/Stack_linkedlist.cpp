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
    struct Node *temp;
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
    struct Node* temp;
    int data;
    if(top== NULL)
    {
        printf("Underflow");
         exit(1);
    }
    else{
        data=top->value;
        temp =top;
        top = top ->next;
        free(temp);
        return data;
    }
}

int main()
{

     
    // push(20);
    // push(1);
    // push(15);
    
    //  struct Node* temp=top;
    // while(temp!=NULL)
    // {
    //     printf("%d ",temp->value);
    //     temp=temp->next;
    // }

    //pallendrome
    string s;
    cin>>s;
    s.size();
    
   // s.length
    bool flag=true;
   for (int i = 0; i < s.size(); i++)
    {
      // printf("%d ", s[i]);
        printf("%c ", s[i]);
        //push
        if(s[i]=='x')
        {
            flag = false;
            continue;
        }
        if(flag==true)
        {
             push(s[i]);
        }
        else{
           if( pop()!=s[i])
           {
            printf("Not Palindrome\n");
            return 0;
           }
        }
       
    }
     printf("Palindrome\n");
      return 0;

}