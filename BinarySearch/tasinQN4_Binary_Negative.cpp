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

void countNegativeRepetitions(const int arr[], int n) {
    int negativeNumbers[MAX_SIZE];
    int negativeCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negativeNumbers[negativeCount++] = arr[i];
        }
    }

    sort(negativeNumbers, negativeNumbers + negativeCount);

    for (int i = 0; i < negativeCount; i++) {
        int number = negativeNumbers[i];
        int firstIndex = binarySearchFirst(negativeNumbers, negativeCount, number);
        int lastIndex = binarySearchLast(negativeNumbers, negativeCount, number);
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
    countNegativeRepetitions(arr, n);

    return 0;
}
