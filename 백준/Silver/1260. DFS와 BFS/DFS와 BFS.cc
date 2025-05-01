#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> q;

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) 
    {
        if (!visited[next]) 
        {
            dfs(next);
        }
    }
}

void bfs(int node)
{
    q.push(node);
    cout << node << " ";
    visited[node] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (int next : graph[top]) 
        {
            if (visited[next]) continue;
            visited[next] = true;
            cout << next << " ";
            q.push(next);
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int node, edge, begin;
    cin >> node >> edge >> begin;

    graph.resize(node + 1);
    visited.resize(node + 1, false);

    for (int i = 0; i < edge; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for (int i = 1; i <= node; ++i) 
    {
        sort(graph[i].begin(), graph[i].end()); // 오름차순 탐색 보장
    }

    dfs(begin);
    cout << "\n";

    visited.assign(node + 1, false); // 초기화 해줘야함
    bfs(begin);
}