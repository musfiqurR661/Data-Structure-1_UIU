#include<bits/stdc++.h>
using namespace std;

void scanFunction(int array[], int size)
{
    for(int i=0; i<size; i++)
    {
        cin >> array[i];
    }
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

    if(size%2 !=0)
    {
        size = (size/2)+1;
        cout << data[size-1] << endl;
    }
    else
    {
        size = size/2;
        cout << (data[size-1] + data[size])/2 << endl;
    }
}
