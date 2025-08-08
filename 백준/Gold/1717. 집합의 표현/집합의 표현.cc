#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

vector<int> parent;
int n, m;

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y) return;
    
    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    parent.reserve(n + 1);
    for (int i = 0; i < n + 1; i++) parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) // Union
        {
            Union(a, b);
        }
        else // 확인
        {
            if (Find(a) == Find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}