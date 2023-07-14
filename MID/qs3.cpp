#include <iostream>
using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

     
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    
    int temp = array[min_idx];
    array[min_idx] = array[step];
    array[step]= temp;
  }
}

double findMedian(int array[], int size) {
  if (size % 2 == 0) {
    //  even, return the average of the two middle elements
    return (array[size / 2 - 1] + array[size / 2]) / 2.0;
  } else {
    //  odd, return the middle element
    return array[size / 2];
  }
}

int main() {
  int size;
  cout << "Enter the number of elements in the array: ";
  cin >> size;

  int data[size];
  cout << "Enter the elements in the array: ";
  for (int i = 0; i < size; i++) {
    cin >> data[i];
  }

  selectionSort(data, size);
  cout << "Sorted array in ascending order: ";
  printArray(data, size);

  double median = findMedian(data, size);
  cout << "Median of the array: " << median << endl;
  return 0;
}
