#include <iostream>
using namespace std;

int Bsearch(int ar[], int a, int b)
{
    int index = -1; // Initialize index to -1
    int flag = 0;

    for (int i = 0; i < a; i++)
    {
        if (ar[i] == b)
        {
            flag++;
            index = i;
            break; // Exit the loop once the target number is found
        }
    }

    int sum = 0;
    if (flag > 0)
    {
        for (int i = index; i <= (index + 4) && i < a; i++) // Added boundary check for array index
        {
            sum += ar[i];
        }
    }
    else
    {
        cout << "Wrong";
        return 0; // Added return statement to exit the function
    }

    cout << "Result: " << sum;
    return sum;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int ar[n];

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    int x;
    cout << "Enter the number to search: ";
    cin >> x;

    Bsearch(ar, n, x); // Function call to Bsearch

    return 0;
}
