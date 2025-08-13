#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N, M; // 사다리 수, 뱀의 수
unordered_map<int, int> Info;
int visited[101]; // 칸 방문여부, 굴린 횟수

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N + M; i++)
    {
        int from;
        int to;
        cin >> from >> to;

        Info[from] = to;
    }

    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == 100)
        {
            cout << visited[current];
            continue;
        }

        for (int i = 1; i < 7; i++)
        {
            int next = current + i;

            if (next > 100) continue;

            if (Info.count(next))
            {
                next = Info[next];
            }

            if (!visited[next])
            {
                visited[next] = visited[current] + 1;
                q.push(next);
            }
        }
    }
}