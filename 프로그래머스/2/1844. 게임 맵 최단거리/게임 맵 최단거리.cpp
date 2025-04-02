#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    if (maps[0][0] == 1) 
    {
        q.push({0, 0});
        dist[0][0] = 1;
    }
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    while (!q.empty()) 
    {
        auto cur = q.front();
        q.pop();
        
        int x = cur.first, y = cur.second;
        
        if (x == n - 1 && y == m - 1)
            return dist[x][y];
        
        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i], ny = y + dy[i];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) // 범위 내에서
            {
                if (maps[nx][ny] == 1 && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return -1;
}