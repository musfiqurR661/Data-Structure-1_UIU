#include <stdio.h>
#include <stdlib.h>

struct node // make node for linked list using structure
{
    int value;         // value part of node contains the element
    struct node *next; // the next part of node contains the address of next element of list
};

struct node *head; // contains the address of first element of linked list

void init()
{
    head = NULL; // initialize the beginning(head) of list to NULL
}

void insertfirst(int element) // inserts element in linked list
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node)); // New named node declared with size of node declared before
    New->value = element;                             // inserts the new element to the value part of node New
    New->next = NULL;                                 // makes the next part of node New NULL so that no garbage value remains
    New->next = head;                                 // the address of previously first node, which was stored in head is now assigned to next part of node New
    head = New;                                       // the address of new first element which is present in node New is assigned to head node
}

void print()
{
    if (head == NULL) // condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur = head;
    int count;
    count = 0;
    while (cur != NULL) // the loop traverse until it gets any NULL node
    {
        printf("%d->", cur->value);
        count++;         // counts the number of nodes or elements present in list
        cur = cur->next; // moves cur pointer to next node to check and get value
    }
    printf("NULL\n");
    printf("number of nodes %d\n", count);
}

void deleteitem(int ele)
{
    // memory of the structure cur is deallocated
    if (head == NULL)
    {
        printf("Khali");  return;
    }
  
    struct node *cur = head;
    struct node *prev =NULL;
    while(cur->value !=ele)
    {
        prev = cur;
        cur = cur ->next;
    }
    if (prev != NULL)
    {
        /* code */
        prev->next=cur->next;
    }
    else{
        head=NULL;
    }
    free(cur);
    
}

int searchitem(int ele)
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        if (temp->value == ele)
            return 1; // element is found
        temp = temp->next;
    }
    return 0;
}

void insertlast(int ele) // insert at the last of linked list
{
    if (head == NULL)
    {
        insertfirst(ele);
    }
    else
    {
        // creat new node
        struct node *newItem;
        newItem = (struct node *)malloc(sizeof(struct node));
        newItem->value = ele;
        newItem->next = NULL;
        // set last to print the last node of the list
        struct node *last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = newItem;
    }
}

void deletelast() // delete the last element
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev->next != NULL)
        prev->next = NULL;
    free(cur);
}

void deletefirst() // delete the first element
{
    struct node *cur;
    if (head == NULL)
        printf("list is empty and nothing to delete\n");
    cur = head;
    head = head->next;
    free(cur);
}
void deleteKth(int n) // delete the kth element
{
//     struct node *cur;
//     if (head == NULL)
//         printf("list is empty and nothing to delete\n");
//     cur = head;
//     head = head->next;
//     free(cur);

int counter =0;
struct node* cur = head;
while (cur != NULL)
{
    /* code */
    counter++;
    cur=cur->next;
}
counter=counter-n;
cur=head;
int i= 1;
while (cur!=NULL)
{
    /* code */
    if(i==counter)
    {
        struct node*freeNode=cur->next;

        cur ->next = cur->next->next;
       freeNode->next=NULL;
       free(freeNode);
        break;
    }
    cur=cur->next;
    i++;
}



}

void insertafter(int elem, int num) // inserts element for any given element present in linked list
{
    
    // creat new node
    struct node *newItem;
    newItem = (struct node *)malloc(sizeof(struct node));
    newItem->value = elem;
    newItem->next = NULL;
    // set last to print the last node of the list
    struct node *prev = head;
    while ((prev->value != num) && (prev->next!= NULL))
    {

        prev = prev->next;
    }
    if (prev->next == NULL)
    {
        printf("%d doesnt exist");
    }
    else
    {
        newItem->next = prev->next;
        prev->next = newItem;
    }
}

void printReverse(struct node *head) // print the linked list in reverse way using recursion
{
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist() // reverse the linked list
{
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev; // points the head pointer to prev as it the new head or beginning in reverse list
}

void sum() // sum of elements of the linked list
{
    int sum = 0;
    struct node* cur  = head;
    while(cur != NULL)
    {
        sum += cur->value;
        cur = cur->next;
    }
    printf("%d\n", sum);
}

int main()
{
    init();

    int ch, element;
    while (1)
    {
        printf("\n1. Insert new item. 2. Delete item. 3. Search item. 4. Insert Last. 5. Print. 6.Delete Last 7.Delete First 8.Insert After 9.Print Linked List in Reverse way. 10.Sum 11.Make the linked list reverse .12.delete k th element 13.Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("enter element to list: ");
            scanf("%d", &element);
            insertfirst(element);
        }
        else if (ch == 2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d", &de);
            deleteitem(de);
        }
        else if (ch == 3)
        {
            int se, reply;
            printf("enter element to search ");
            scanf("%d", &se);
            reply = searchitem(se);
            if (reply == 1)
                printf("element found\n");
            else
                printf("element not found\n");
        }
        else if (ch == 4)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d", &le);
            insertlast(le);
        }
        else if (ch == 5)
        {
            print();
        }
        else if (ch == 6)
        {
            deletelast();
        }
        else if (ch == 7)
        {
            deletefirst();
        }
        else if (ch == 8)
        {
            int ie, p;
            printf("enter element to insert: ");
            scanf("%d", &ie);
            printf("enter after which element to insert: ");
            scanf("%d", &p);
            insertafter(ie, p);
        }
        else if (ch == 9)
        {
            printReverse(head);
        }
        else if (ch == 10)
        {
            sum();
        }
        else if (ch == 11)
        {
            reverselist();
        }
        else if (ch == 12)
        {  int n;
            printf("Position:");
            scanf("%d", &n);
            deleteKth(n);
        }
        else if (ch == 13)
            return 0;
        else
            return 0;
    }
    return 0;
}