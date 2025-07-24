#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int globalIndex;
int N, row, col; // (1, 3)

void dfs(int x, int y, int size) 
{
    if(x == col && y == row)
    {
        cout << globalIndex;
        return;
    }
    else if (col < x + size && row < y + size && col >= x && row >= y)
    {
        int currentSize = size / 2;

        dfs(x, y, currentSize); // 좌상
        dfs(x + currentSize, y, currentSize); // 우상
        dfs(x, y + currentSize, currentSize); // 좌하
        dfs(x + currentSize, y + currentSize, currentSize); // 우하
    }
    else
    {
        globalIndex += size * size;
    }
}

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> row >> col;

    dfs(0, 0, pow(2, N));
}