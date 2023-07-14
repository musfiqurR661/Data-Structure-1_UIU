#include <iostream>

using namespace std;

int main()
{
    int number1, number2, revNumber;
    cout << "Enter the number:" << endl;
    cin >> number1 >> number2;
    cout << "your Entired number :" << number1 << endl
         << number2 << endl;
    revNumber = number1;
    number1 = number2;
    number2 = number1;
    number2 = revNumber;

    cout << "Swapping :" << number1 << endl
         << number2 << endl;

    return 0;
}
