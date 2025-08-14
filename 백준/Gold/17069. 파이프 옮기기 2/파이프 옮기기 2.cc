#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N;
vector<vector<int>> board;
int answer = 0;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    board.resize(N, vector<int>(N));
    vector<vector<vector<long long>>> dp(3, vector<vector<long long>>(N, vector<long long>(N, 0))); // 0 가로, 1 세로, 2 대각

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    dp[0][0][1] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 2; j < N; j++)
        {
            if (board[i][j] == 1)
                continue;

            dp[0][i][j] = dp[0][i][j - 1] + dp[2][i][j - 1];

            if (i > 0)
            {
                dp[1][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];

                if (board[i - 1][j] == 0 && board[i][j - 1] == 0)
                {
                    dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
                }
            }
        }
    }

    long long count = dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];
    cout << count;
}