// Selection sort in C++

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

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    int temp = array[min_idx];
    array[min_idx] = array[step];
    array[step]= temp;
  }
}

int getSumR(int data[], int A)
{
    int sum =0;
    for ( int i = 0 ; i < A ; i++)
    {
        sum = sum+ data[i];
      

    }
      return sum;
}


// driver code
int main() {
//   int data[] = {20, 12, 10, 15, 2};
//   int size = sizeof(data) / sizeof(data[0]);


//user input 

int size;
cout<< "Enter the Size :"<<endl;
cin>> size;

int data[size];
for(int i=0; i< size; i++)
{
    cin>> data[i];
}

int num;
cin>> num;


  selectionSort(data, size);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, size);

cout<< "The output is : "<< getSumR(data,num);


}