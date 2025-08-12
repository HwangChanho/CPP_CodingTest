#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N;
vector<vector<int>> board;
int answer = 0;

// 파이프의 끝점 위치와 방향(0:가로, 1:세로, 2:대각선)
void dfs(int r, int c, int dir)
{
    if (r == N - 1 && c == N - 1)
    {
        answer++;
        return;
    }

    if (dir == 0 || dir == 2)
    {
        if (c + 1 < N && board[r][c + 1] == 0)
        {
            dfs(r, c + 1, 0);
        }
    }
    if (dir == 1 || dir == 2)
    {
        if (r + 1 < N && board[r + 1][c] == 0)
        {
            dfs(r + 1, c, 1);
        }
    }
    if (r + 1 < N && c + 1 < N && board[r + 1][c] == 0 && board[r][c + 1] == 0 && board[r + 1][c + 1] == 0)
    {
        if (dir == 0 || dir == 1 || dir == 2)
        {
            dfs(r + 1, c + 1, 2);
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    if (board[N - 1][N - 1] == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    dfs(0, 1, 0);

    cout << answer << endl;
    return 0;
}