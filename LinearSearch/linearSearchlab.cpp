#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
        

    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            cout << arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] << endl;
            break;
        }
    }
    return 0;
}
