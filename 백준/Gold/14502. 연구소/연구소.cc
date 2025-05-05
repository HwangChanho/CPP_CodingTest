#include <bits/stdc++.h>

using namespace std;

int height, width;
int maxSafeArea = 0;

vector<vector<int>> Map;
vector<pair<int, int>> EmptySpace;
vector<vector<int>> offset = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void BFS(const vector<pair<int, int>> &WallPoints)
{
    vector<vector<int>> MapTemp = Map;
    queue<pair<int, int>> q;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (MapTemp[i][j] == 2)
                q.push({i, j});

    for (const auto &point : WallPoints) // 벽 세우기
    {
        MapTemp[point.first][point.second] = 1;
    }

    while (!q.empty())
    {
        pair<int, int> point = q.front();
        q.pop();

        for (const auto &offsetPoint : offset)
        {
            int offsetX = offsetPoint[0] + point.first;
            int offsetY = offsetPoint[1] + point.second;

            if (offsetX >= 0 && offsetX < height && offsetY >= 0 && offsetY < width)
            {
                if (MapTemp[offsetX][offsetY] == 0)
                {
                    MapTemp[offsetX][offsetY] = 2;
                    q.push(make_pair(offsetX, offsetY));
                }
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (MapTemp[i][j] == 0)
                ++safe;

    maxSafeArea = max(maxSafeArea, safe);
}

void BruteForce() // 벽을 설치할 수 있는 공간에 대해 완전탐색 필요
{
    int n = EmptySpace.size();
    vector<int> comb(n, 0);
    fill(comb.end() - 3, comb.end(), 1);

    do
    {
        vector<pair<int, int>> WallPoints;
        for (int i = 0; i < n; ++i)
            if (comb[i])
                WallPoints.push_back(EmptySpace[i]);

        BFS(WallPoints);

    } while (next_permutation(comb.begin(), comb.end()));
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> height >> width;
    Map.resize(height, vector<int>(width));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int value;
            cin >> value;
            Map[i][j] = value;
            if (value == 0)
                EmptySpace.push_back(make_pair(i, j));
        }
    }

    BruteForce();
    cout << maxSafeArea;

    return 0;
}