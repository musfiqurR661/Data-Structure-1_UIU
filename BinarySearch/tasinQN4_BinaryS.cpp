#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the array

int binarySearchFirst(const int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int binarySearchLast(const int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

void countPositiveRepetitions(const int arr[], int n) {
    int positiveNumbers[MAX_SIZE];
    int positiveCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positiveNumbers[positiveCount++] = arr[i];
        }
    }

    sort(positiveNumbers, positiveNumbers + positiveCount);

    for (int i = 0; i < positiveCount; i++) {
        int number = positiveNumbers[i];
        int firstIndex = binarySearchFirst(positiveNumbers, positiveCount, number);
        int lastIndex = binarySearchLast(positiveNumbers, positiveCount, number);
        int count = lastIndex - firstIndex + 1;

        cout << "Number: " << number << " Count: " << count << endl;

        i = lastIndex;  // Skip to the next unique number
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[MAX_SIZE];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Output:" << endl;
    countPositiveRepetitions(arr, n);

    return 0;
}
