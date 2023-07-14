#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

void sortEvenOdd(int array[], int size)
{
  // Partition the array into even and odd numbers
  int evenIndex = 0;
  int oddIndex = size - 1;

  while (evenIndex < oddIndex)
  {
    // Find the first odd number from the left
    while (array[evenIndex] % 2 == 0 && evenIndex < oddIndex)
    {
      evenIndex++;
    }

    // Find the first even number from the right
    while (array[oddIndex] % 2 != 0 && evenIndex < oddIndex)
    {
      oddIndex--;
    }

    // Swap the even and odd numbers
    if (evenIndex < oddIndex)
    {
      swap(array[evenIndex], array[oddIndex]);
    }
  }

  // Sort the even numbers in ascending order using selection sort
  for (int i = 0; i < evenIndex - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < evenIndex; j++)
    {
      if (array[j] < array[minIndex])
      {
        minIndex = j;
      }
    }
    swap(array[i], array[minIndex]);
  }

  // Sort the odd numbers in descending order using selection sort
  for (int i = evenIndex; i < size - 1; i++)
  {
    int maxIndex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[j] > array[maxIndex])
      {
        maxIndex = j;
      }
    }
    swap(array[i], array[maxIndex]);
  }
}

int main()
{
  int size;
  cout << "Enter the number of elements in the array: ";
  cin >> size;

  int data[size];
  cout << "Enter the elements in the array: ";
  for (int i = 0; i < size; i++)
  {
    cin >> data[i];
  }

  sortEvenOdd(data, size);
  cout << "Sorted array: ";
  printArray(data, size);

  return 0;
}
