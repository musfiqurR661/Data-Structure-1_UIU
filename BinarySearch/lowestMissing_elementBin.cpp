#include<bits/stdc++.h>
using namespace std;

int findSmallestMissingElement(int arr[], int n) {
    int l = 0, h = n - 1;

    // If the first element is not 0, then 0 is the smallest missing element
    if (arr[0] != 0) {
        return 0;
    }

    // Perform binary search to find the smallest missing element
    while (l <= h) {
        int mid = (l + h) / 2;

        // If the element at mid is equal to its index, the missing element lies in the right half
        if (arr[mid] == mid) {
            l = mid + 1;
        }
        // Otherwise, the missing element lies in the left half
        else {
            h = mid - 1;
        }
    }

    // The smallest missing element is l (or h+1) if it is within the bounds of the array
    if (l < n) {
        return l;
    }
    else {
        return l + 1;
    }
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
