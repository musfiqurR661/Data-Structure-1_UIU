#include<bits/stdc++.h>
using namespace std;

void scanFunction(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        cin >> array[i];
    }
}
void printFunction(int array[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[size-1] << endl;
}


void selectionSort(int array[], int size)
{
    for(int step=0; step<size-1; step++)
    {
        int min_idx = step;
        for(int i=step+1; i<size; i++)
        {
            if(array[i] < array[min_idx]) min_idx = i;
        }
        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step]= temp;
    }
}

int main()
{
    int size; cin >> size;
    int data[size]; scanFunction(data, size);

    selectionSort(data, size);


   int newArr[size];
   int count = 0;
   for(int i=0; i<size; i++)
   {
       if(data[i]%2 == 0)
       {
           newArr[count] = data[i];
           count++;
       }
   }
    for(int i=size-1; i>=0; i--)
   {
       if(data[i]%2 != 0)
       {
           newArr[count] = data[i];
           count++;
       }
   }
   printFunction(newArr, count);
}

