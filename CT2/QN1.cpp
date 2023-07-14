#include <bits/stdc++.h>
using namespace std;
 

int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

 int main()
{
   
     int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

   
    
    cout<<"Which You Want:";
      int z;
     cin>>z;
   

   cout<<"First occurrence of"<< z <<" is on 9"<< first(arr, 0, n - 1, z, n);
         
 
    return 0;
}