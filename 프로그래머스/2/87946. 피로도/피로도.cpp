#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDungeons = 0;

void dfs(int k, int count, vector<vector<int>>& dungeons, vector<bool>& visited) 
{
    maxDungeons = max(maxDungeons, count);

    for (int i = 0; i < dungeons.size(); i++) 
    {
        if (!visited[i] && k >= dungeons[i][0]) 
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], count + 1, dungeons, visited);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    vector<bool> visited(dungeons.size(), false);
    dfs(k, 0, dungeons, visited);
    return maxDungeons;
}