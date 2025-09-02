#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int maxLen = 0;
int R, C;

void dfs(vector<vector<char>> &board, vector<bool> &visited, pair<int, int> current, int len)
{
    maxLen = max(maxLen, len);

    for (auto val : dir)
    {
        int col = current.first + val.first;
        int row = current.second + val.second;

        if (col < 0 || col >= R || row < 0 || row >= C)
            continue;

        int next = board[col][row] - 'A';
        if (!visited[next])
        {
            visited[next] = true;
            dfs(board, visited, {col, row}, len + 1);
            visited[next] = false;
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> R >> C;

    vector<vector<char>> board(R, vector<char>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];

    vector<bool> visited(26, false);
    visited[board[0][0] - 'A'] = true;
    visited.push_back(board[0][0]);
    dfs(board, visited, {0, 0}, 1);

    cout << maxLen;
}