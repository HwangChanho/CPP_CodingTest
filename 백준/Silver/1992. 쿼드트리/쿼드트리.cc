#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

string answer;
vector<string> board;

char IsSame(int row, int col, int size) 
{
    char first = board[row][col];
    
    for (int i = row; i < row + size; i++) 
    {
        for (int j = col; j < col + size; j++) 
        {
            if (board[i][j] != first) 
            {
                return '2';
            }
        }
    }
    return first;
}

void dfs(int row, int col, int size) 
{
    char same = IsSame(row, col, size);
    
    if (same != '2') 
    {
        answer += same;
        return;
    }
    
    answer += "(";
    
    int half = size / 2; // 인덱스의 중간
    
    dfs(row, col, half);
    dfs(row, col + half, half);
    dfs(row + half, col, half);
    dfs(row + half, col + half, half);
    
    answer += ")";
}

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    int size;
    cin >> size;

    board.resize(size);
    for (int i = 0; i < size; i++) 
    {
        cin >> board[i];
    }

    dfs(0, 0, size);
    
    cout << answer << '\n';

    return 0;
}