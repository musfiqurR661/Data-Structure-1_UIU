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
        printf("Khali");
        return;
    }

    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->value != ele)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL)
    {
        /* code */
        prev->next = cur->next;
    }
    else
    {
        head = NULL;
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
void insertMid(int ele)    //question 1 using insertfirst() function;
{
    if (head == NULL)
    {
        insertfirst(ele);
    }
    else
    {
        // Count the number of elements in the linked list
        int count = 0;
        struct node *current = head;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }

        // Find the mid position
        int mid = count / 2;

        // Traverse to the mid position
        struct node *temp = head;
        if (count % 2 == 0)
        {
            // If the count is even, move temp one node before the middle
            for (int i = 0; i < mid - 1; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            // If the count is odd, move temp to the middle node
            for (int i = 0; i < mid; i++)
            {
                temp = temp->next;
            }
        }

        // Create a new node
        struct node *newItem = (struct node *)malloc(sizeof(struct node));
        newItem->value = ele;

        // Insert the new node in the middle
        newItem->next = temp->next;
        temp->next = newItem;
    }
}
void addAll_end(int arr[], int size)     //question 2 using insertLast () function;
{
    for (int i = 0; i < size; i++)
    {
        insertlast(arr[i]);
    }
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

void deleteKth(int k)   //Question  3
{
    if (head == NULL)
    {
        printf("List is empty and nothing to delete.\n");
        return;
    }

    struct node *fastPtr = head;
    struct node *slowPtr = head;
    struct node *prevPtr = NULL;

    // Move the fast pointer k nodes ahead of the slow pointer
    for (int i = 0; i < k; i++)
    {
        if (fastPtr == NULL)
        {
            printf("Invalid value of k.\n");
            return;
        }
        fastPtr = fastPtr->next;
    }

    // Move both pointers until the fast pointer reaches the end
    while (fastPtr != NULL)
    {
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    // Delete the k-th last element
    if (prevPtr == NULL)
    {
        // If prevPtr is NULL, it means the head needs to be deleted
        head = head->next;
    }
    else
    {
        prevPtr->next = slowPtr->next;
    }

    free(slowPtr);
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
    while ((prev->value != num) && (prev->next != NULL))
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
    struct node *cur = head;
    while (cur != NULL)
    {
        sum += cur->value;
        cur = cur->next;
    }
    printf("%d\n", sum);
}
void replaceLastWithSum()  //question 4 using sum() function.
{
    if (head == NULL)
    {
        printf("List is empty and no last element to replace.\n");
        return;
    }

    struct node *cur = head;
    struct node *prev = NULL;
    int sum = 0;

    // Traverse the linked list to calculate the sum and find the last node
    while (cur->next != NULL)
    {
        sum += cur->value;
        prev = cur;
        cur = cur->next;
    }

    // Replace the value of the last node with the sum
    sum += cur->value;
    cur->value = sum;

    printf("Last element replaced with the sum: %d\n", sum);
}


struct Result    //Question 5
{
    int *evenArray;
    int count;
};

struct Result searchEvenNumbers()
{
    int count = 0;
    struct node *current = head;

    // Count the number of even numbers in the linked list
    while (current != NULL)
    {
        if (current->value % 2 == 0)
        {
            count++;
        }
        current = current->next;
    }

    // Create an array to store even numbers
    int *evenArray = (int *)malloc(count * sizeof(int));

    // Traverse the linked list and store even numbers in the array
    current = head;
    int index = 0;
    while (current != NULL)
    {
        if (current->value % 2 == 0)
        {
            evenArray[index++] = current->value;
        }
        current = current->next;
    }

    struct Result result;
    result.evenArray = evenArray;
    result.count = count;
    return result;
}

int main()
{
    init();

    int ch, element;
    while (1)
    {
        printf("\n1. Insert new item. \n2. Delete item. \n3. Search item. \n4. Insert Last. \n5. Print. \n6.Delete Last \n7.Delete First \n8.Insert After \n9.Print Linked List in Reverse way. \n10.Sum \n11.Make the linked list reverse  \n12.InsertMid \n13.Add all in End \n14.Delete k-th \n15.Replace last with sum \n16.Search All even number \n17.Exit\n-------------------------------------------------------------------------------------\n");
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
        {
            int ele;
            printf("Enter the value to insert: ");
            scanf("%d", &ele);
            insertMid(ele);
        }
        else if (ch == 13)
        {
            int size;
            printf("Enter the size of the array: ");
            scanf("%d", &size);

            int arr[size];
            printf("Enter the elements of the array: ");
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &arr[i]);
            }

            addAll_end(arr, size);
        }
        else if (ch == 14)
        {
            int k;
            printf("Enter the position of the k-th last element to delete: ");
            scanf("%d", &k);
            deleteKth(k);
        }
        else if (ch == 15)
        {
            replaceLastWithSum();
        }
        else if (ch == 16)
        {
            struct Result result = searchEvenNumbers();

            printf("Even numbers in the linked list: ");
            for (int i = 0; i < result.count; i++)
            {
                printf("%d ", result.evenArray[i]);
            }

            free(result.evenArray);
        }
        else if (ch == 17)
            return 0;//exit
        else
            return 0;
    }
    return 0;
}