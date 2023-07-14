#include<iostream>
using namespace std;

//void insertionSort(int ary[], int n);
//  void printArray(int ary[], int n);


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
int resultA(int A[], int n)
{
     insertionSort(A, n);
     for(int i=0;i<n;i++)
     {
        cout<<A[0]<<"and"<<A[n-1];
     }
    cout<<resultA;
}

int main()
{
    int i,n;
    cin>>n;
    int A[n]; 
   // int ary = sizeof(A) / sizeof(A[1]);

for(int i=0;i<n;i++)
{
    cin>>A[i];
} 
   
    insertionSort(A, n);
    printArray(A, n);
     resultA(A,n);
    return 0;
}
