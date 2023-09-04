#include <iostream>
#include <queue>
using namespace std;

int i, j, n, m = 5;
int Field[15][5], copyField[15][5];
int max_coin = 0;

void playGame(int pos, int rowsLeft, int currentCoin, int bombStatus) {
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(pos, make_pair(rowsLeft, currentCoin)));

    while (!q.empty()) {
        int currentPos = q.front().first;
        int currentRowsLeft = q.front().second.first;
        int currentCoins = q.front().second.second;
        q.pop();

        if (currentRowsLeft == -1) {
            continue;
        }

        if (currentPos == m || currentPos == -1) {
            continue;
        }

        if (Field[currentRowsLeft][currentPos] == 1) {
            currentCoins += 1;
            if (currentCoins > max_coin) max_coin = currentCoins;
        }

        if (Field[currentRowsLeft][currentPos] == 2) {
            if (bombStatus == 0) {
                continue;
            } else {
                for (i = currentRowsLeft; i >= 0 && i > currentRowsLeft - 5; i--) {
                    for (j = currentPos - 2; j <= currentPos + 2; j++) {
                        if (j >= 0 && j < m && Field[i][j] == 2) {
                            Field[i][j] = 0;
                        }
                    }
                }
                bombStatus = 0;
                // Continue exploration after using bomb
                q.push(make_pair(currentPos, make_pair(currentRowsLeft - 1, currentCoins)));
                q.push(make_pair(currentPos - 1, make_pair(currentRowsLeft - 1, currentCoins)));
                q.push(make_pair(currentPos + 1, make_pair(currentRowsLeft - 1, currentCoins)));
                for (i = currentRowsLeft; i >= 0 && i > currentRowsLeft - 5; i--) {
                    for (j = currentPos - 2; j <= currentPos + 2; j++) {
                        if (j >= 0 && j < m) {
                            Field[i][j] = copyField[i][j];
                        }
                    }
                }
            }
        }

        // Continue exploration without bomb
        q.push(make_pair(currentPos, make_pair(currentRowsLeft - 1, currentCoins)));
        q.push(make_pair(currentPos - 1, make_pair(currentRowsLeft - 1, currentCoins)));
        q.push(make_pair(currentPos + 1, make_pair(currentRowsLeft - 1, currentCoins)));
    }
}

int main() {
    int copyT, t;
    cin >> t , copyT = t;
    while(t--) {
        cin >> n;
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                cin >> Field[i][j];
                copyField[i][j] = Field[i][j];
            }
        }
        int pos = 2 , coin = 0 , bombStatus = 1;
        max_coin = 0;
        playGame(pos, n-1, coin, bombStatus);
        playGame(pos-1, n-1, coin, bombStatus);
        playGame(pos+1, n-1, coin, bombStatus);
        cout << "#" << (copyT - t) << " " << max_coin << endl;
    }
    return 0;
}
