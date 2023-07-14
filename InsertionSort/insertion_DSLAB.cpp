#include<iostream>
using namespace std;

void insertionSort(int ary[], int n);
void printArray(int ary[], int n);

int main()
{
    int i;
    int A[] = {5, 2, 4, 6, 1, 3};
    int ary = sizeof(A) / sizeof(A[1]);

    insertionSort(A, ary);
    printArray(A, ary);
    return 0;
}

void insertionSort(int ary[], int n)
{
    int key, i, j;
    for (i = 1; i < n; i++)
    {
        key = ary[i];
        j = i - 1;
        while (j >= 0 && ary[j] > key) // 
        {
            ary[j + 1] = ary[j];
            j = j - 1;
        }
        ary[j + 1] = key;
    }
}

void printArray(int ary[], int n)
{
    for (int i = 0; i < n; i++) //
    {
        cout << ary[i] << " ";
    }
    cout << endl;
}