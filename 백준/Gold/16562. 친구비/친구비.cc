#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N; // 학생수
int M; // 친구관계수
int k; // 돈

vector<int> friendCost;
unordered_map<int, int> rootCost;
vector<int> parent;

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;

    if (friendCost[u] < friendCost[v])
        parent[v] = u;
    else
        parent[u] = v;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M >> k;

    friendCost.resize(N + 1);
    parent.resize(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        cin >> friendCost[i];
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        merge(from, to);
    }

    set<int> roots;
    int totalCost = 0;

    for (int i = 1; i <= N; i++)
    {
        int root = find(i);
        roots.insert(root);
    }

    for (int r : roots)
    {
        totalCost += friendCost[r];
    }

    if (totalCost <= k)
        cout << totalCost << '\n';
    else
        cout << "Oh no\n";
}
