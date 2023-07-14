#include<bits/stdc++.h>
using namespace std;

int findHighestMissingElement(int arr[], int n) {
    int l = 0, h = n - 1;

    // If the last element is not n-1, then n-1 is the highest missing element
    if (arr[n - 1] != n - 1) {
        return n - 1;
    }

    // Perform binary search to find the highest missing element
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

    // The highest missing element is the current element + 1
    return arr[l - 1] + 1;
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

    int highestMissing = findHighestMissingElement(arr, n);
    cout << "The highest missing element is " << highestMissing << endl;

    return 0;
}
