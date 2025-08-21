#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N, M, X; // 노드수, 간선수, X

void Dijkstra(int start, vector<int> &d, vector<vector<pair<int, int>>> &e)
{
    priority_queue<pair<int, int>> pq;
    
    d[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (d[current] < distance)
            continue;

        for (const auto &edge : e[current])
        {
            int next = edge.first;
            int nextDistance = distance + edge.second;

            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> edge(N + 1);
    vector<vector<pair<int, int>>> redge(N + 1);
    vector<int> distance(N + 1);
    vector<int> rdistance(N + 1);
    int answer = 0;

    for (int i = 0; i < M; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        edge[from].push_back({to, weight});
        redge[to].push_back({from, weight});
    }

    fill(distance.begin(), distance.end(), INT_MAX);
    Dijkstra(X, distance, edge);
    fill(rdistance.begin(), rdistance.end(), INT_MAX);
    Dijkstra(X, rdistance, redge);

    for (int i = 1; i <= N; i++)
    {
        answer = max(distance[i] + rdistance[i], answer);
    }

    cout << answer;
}