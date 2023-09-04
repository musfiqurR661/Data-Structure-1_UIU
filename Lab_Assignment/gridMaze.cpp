#include <iostream>
using namespace std;

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 2},
    {0, 0, 0, 1, 0},
    {0, 3, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

int visited[ROWS][COLS] = {0};
int shortest_path[ROWS * COLS];
int shortest_length = ROWS * COLS;

struct Point
{
    int row;
    int col;
};

bool isValid(int row, int col)
{
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

void dfs(int row, int col, int path[], int length)
{
    if (!isValid(row, col) || visited[row][col] || maze[row][col] == 1)
    {
        return;
    }

    path[length] = row * COLS + col;
    visited[row][col] = 1;

    if (maze[row][col] == 2)
    {
        int treasure_found = 0;
        for (int i = 0; i <= length; i++)
        {
            if (maze[path[i] / COLS][path[i] % COLS] == 3)
            {
                treasure_found = 1;
                break;
            }
        }
        if (treasure_found)
        {
            cout << "Path with treasure: ";
            for (int i = 0; i <= length; i++)
            {
                cout << "(" << path[i] / COLS << ", " << path[i] % COLS << ")";
                if (i < length)
                {
                    cout << " -> ";
                }
            }
            cout << endl;

            if (length + 1 < shortest_length)
            {
                shortest_length = length + 1;
                for (int i = 0; i <= length; i++)
                {
                    shortest_path[i] = path[i];
                }
            }
        }
    }

    dfs(row + 1, col, path, length + 1);
    dfs(row - 1, col, path, length + 1);
    dfs(row, col + 1, path, length + 1);
    dfs(row, col - 1, path, length + 1);

    visited[row][col] = 0; // Backtrack again 
}

void find_paths_with_treasures(int start_row, int start_col)
{
    int path[ROWS * COLS];
    dfs(start_row, start_col, path, 0);

    if (shortest_length != ROWS * COLS)
    {
        cout << "\nShortest path with treasure: ";
        for (int i = 0; i < shortest_length; i++)
        {
            cout << "(" << shortest_path[i] / COLS << ", " << shortest_path[i] % COLS << ")";
            if (i < shortest_length - 1)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "\nNo path with treasure found." << endl;
    }
}

int main()
{
    find_paths_with_treasures(1, 0);
    return 0;
}
