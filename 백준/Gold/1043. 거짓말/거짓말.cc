#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    queue<int> q;
    vector<bool> visited(N + 1);

    int personCnt;
    cin >> personCnt;

    if (personCnt == 0)
    {
        cout << M;
        return 0;
    }

    for (int i = 0; i < personCnt; i++)
    {
        int num;
        cin >> num;

        q.push(num);
        visited[num] = true;
    }

    vector<vector<int>> visitors(M);
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int Cnt;
        cin >> Cnt;

        int first;
        cin >> first;
        visitors[i].push_back(first);

        for (int j = 1; j < Cnt; j++)
        {
            int next;
            cin >> next;

            visitors[i].push_back(next);
            graph[first].push_back(next);
            graph[next].push_back(first);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto val : graph[node])
        {
            if (visited[val])
                continue;
            visited[val] = true;

            q.push(val);
        }
    }

    for (auto val : visitors)
    {
        for (auto el : val)
        {
            if (visited[el])
            {
                M--;
                break;
            }
        }
    }

    cout << M;
}