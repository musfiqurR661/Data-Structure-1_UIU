#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    int count = 0;
    int loop = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
        loop++;
    }
    cout << "The numbers of swapping: " << count << endl;
    cout << "The numbers of loop running: " << loop << endl;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printMaxElement(int arr[], int n, int N)
{
    bubbleSort(arr, n);

    cout << "Max " << N << " elements: ";
    /*for (int i = n - 1; i >= n - N; i--)
    {
        cout << arr[i] << " ";

        // int temp = arr[i];
        // arr[i]= arr[i+1];
        // arr[i+1]= temp;
    }*/
    for (int i = n - N; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int main()
{

    // int arr[] = {1,2,3,5,4,6};
    // int arr[] = {1,3,2,4,7,6,8,10};
    // int n = sizeof(arr) /sizeof(arr[0]);

    // user input

    int size;
    cout << "Enter the Size :" << endl;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int num;
    cin >> num;

    cout << "Original array: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    printMaxElement(arr, size, num);
    return 0;
}