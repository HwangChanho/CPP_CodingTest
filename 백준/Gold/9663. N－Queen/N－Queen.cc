#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int boardSize;
int solutionCount;
vector<int> visited;

bool check(int depth)
{
    for (int i = 0; i < depth; i++)
    {
        // 세로줄 금지, 대각 금지
        if (visited[i] == visited[depth] || abs(visited[depth] - visited[i]) == depth - i)
            return false;
    }

    return true;
}

void NQueenA(int depth)
{
    if (depth == boardSize)
    {
        solutionCount++;
    }
    else
    {
        for (int i = 0; i < boardSize; i++)
        {
            visited[depth] = i;
            if (check(depth))
                NQueenA(depth + 1);
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> boardSize;
    visited.resize(boardSize, 0);
    
    NQueenA(0);

    cout << solutionCount;
}