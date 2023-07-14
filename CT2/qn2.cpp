
#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    int row,colm;
    cout<< "Row and Column:";
    cin>> n;

    cin>>row >>colm;
     int arr[row][colm];


    for(int i=0;i<row;i++)
    {
        for(int j=0;j<colm; j++)
        {
            cin>>[i][j];
        }
    }
    int k;
    cout<< "Enter the value:";
    cin>> k;
    for(int i=0;i<row;i++)
    {
        for(int j=0 ;j<colm; j++)
        {
            if(arr [i][j])
            {
                row=i;
                colm=j;
            }
        }
    }
}