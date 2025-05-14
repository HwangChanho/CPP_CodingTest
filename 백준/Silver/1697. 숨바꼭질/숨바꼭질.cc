#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<bool> visited(100001, false);
    queue<pair<int,int>> q;

    q.push({n, 0});
    visited[n] = true;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        int depth = current.second;
        int value = current.first;
        q.pop();

        if (value == k)
        {
            cout << depth;
            return 0;
        }

        vector<int> next = {value * 2, value - 1, value + 1};

        for (int step : next)
        {
            if (step >= 0 && step <= 100000 && !visited[step])
            {
                visited[step] = true;
                q.push({step, depth + 1});
            }
        }
    }
}