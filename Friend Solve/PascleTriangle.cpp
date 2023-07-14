#include <iostream>
using namespace std;
int binomialCoefficient(int n, int k)
{
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void printPascalsTriangle(int num_rows)
{
    for (int row = 0; row < num_rows; row++)
    {
        for (int space = 0; space < num_rows - row - 1; space++)
        {
            cout << " ";
        }
        for (int col = 0; col <= row; col++)
        {
            int coefficient = binomialCoefficient(row, col);
            cout << coefficient << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num_rows;
    cout << "Enter the number of rows for Pascal's triangle: ";
    cin >> num_rows;
    printPascalsTriangle(num_rows);

    return 0;
}
