#include <iostream>
using namespace std;

int i, j, n, m = 5;
int Field[15][5], copyField[15][5];
int max_coin = 0;

void playGame(int pos, int rowsLeft, int currentCoin, int bombStatus)
{

    if (rowsLeft == -1)
    {
        return;
    }

    if (pos == m || pos == -1)
    {
        return;
    }

    if (Field[rowsLeft][pos] == 1)
    {
        currentCoin += 1;
        if (currentCoin > max_coin)
            max_coin = currentCoin;
        playGame(pos, rowsLeft - 1, currentCoin, bombStatus);
        playGame(pos - 1, rowsLeft - 1, currentCoin, bombStatus);
        playGame(pos + 1, rowsLeft - 1, currentCoin, bombStatus);
    }
    else if (Field[rowsLeft][pos] == 0)
    {
        playGame(pos, rowsLeft - 1, currentCoin, bombStatus);
        playGame(pos - 1, rowsLeft - 1, currentCoin, bombStatus);
        playGame(pos + 1, rowsLeft - 1, currentCoin, bombStatus);
    }

    else if (Field[rowsLeft][pos] == 2)
    {
        if (bombStatus == 0)
        {
            return;
        }
        else
        {
            for (i = rowsLeft; i >= 0 && i > rowsLeft - 5; i--)
            {
                for (j = pos - 2; j <= pos + 2; j++)
                {
                    if (j >= 0 && j < m && Field[i][j] == 2)
                    {
                        Field[i][j] = 0;
                    }
                }
            }
            bombStatus = 0;
            playGame(pos, rowsLeft - 1, currentCoin, bombStatus);
            playGame(pos - 1, rowsLeft - 1, currentCoin, bombStatus);
            playGame(pos + 1, rowsLeft - 1, currentCoin, bombStatus);
            for (i = rowsLeft; i >= 0 && i > rowsLeft - 5; i--)
            {
                for (j = pos - 2; j <= pos + 2; j++)
                {
                    if (j >= 0 && j < m)
                    {
                        Field[i][j] = copyField[i][j];
                    }
                }
            }
        }
    }
}

int main()
{
    int copyT, t;
    cin >> t, copyT = t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> Field[i][j];
                copyField[i][j] = Field[i][j];
            }
        }
        int pos = 2, coin = 0, bombStatus = 1;
        max_coin = 0;
        playGame(pos, n - 1, coin, bombStatus);
        playGame(pos - 1, n - 1, coin, bombStatus);
        playGame(pos + 1, n - 1, coin, bombStatus);
        cout << "#" << (copyT - t) << " " << max_coin << endl;
    }
    return 0;
}
