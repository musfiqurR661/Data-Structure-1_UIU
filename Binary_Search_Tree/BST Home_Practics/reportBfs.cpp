#include <iostream>
#include <queue>
using namespace std;

int i, j, n, m = 5;
int Field[15][5], copyField[15][5];
int max_coin = 0;

void playGame(int pos, int rowsLeft, int currentCoin, int bombStatus) {
    queue<pair<int, pair<int, int>>> q;  // Use a queue for BFS
    q.push(make_pair(pos, make_pair(rowsLeft, currentCoin)));  // Enqueue initial state

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

        // Rest of your code remains mostly the same
        // Instead of recursive calls, enqueue the possible next states
        q.push(make_pair(currentPos, make_pair(currentRowsLeft - 1, currentCoins)));
        q.push(make_pair(currentPos - 1, make_pair(currentRowsLeft - 1, currentCoins)));
        q.push(make_pair(currentPos + 1, make_pair(currentRowsLeft - 1, currentCoins)));
    }
}

int main() {
    int copyT, t;
    cin >> t, copyT = t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
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
