#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int startNode, int N, const vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[startNode] = 0;
    pq.push({0, startNode});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (dist[currentNode] < currentDist)
            continue;

        for (const auto &edge : adj[currentNode])
        {
            int nextNode = edge.first;
            int nextDist = edge.second + currentDist;

            if (nextDist < dist[nextNode])
            {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
    
    return dist;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist = dijkstra(1, N, adj);
    vector<int> distV1 = dijkstra(v1, N, adj);
    vector<int> distV2 = dijkstra(v2, N, adj);

    long long path1 = (long long)dist[v1] + distV1[v2] + distV2[N];
    long long path2 = (long long)dist[v2] + distV2[v1] + distV1[N];

    long long result = min(path1, path2);

    if (result >= INF)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }

    return 0;
}