#include<bits/stdc++.h>
using namespace std;

int findSmallestMissingElement(int arr[], int n) {
    int l = 0, h = n - 1;

   
    if (arr[0] != 0) {
        return 0;
    }

 
    while (l < h) {
        int mid = (l + h) / 2;

       
        if (arr[mid] - mid > 1) {
            h = mid;
        }
        
        else {
            l = mid + 1;
        }
    }

    // The smallest missing element is the current element + 1
    return arr[l] + 1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int smallestMissing = findSmallestMissingElement(arr, n);
    cout << "The smallest missing element is " << smallestMissing << endl;

    return 0;
}
