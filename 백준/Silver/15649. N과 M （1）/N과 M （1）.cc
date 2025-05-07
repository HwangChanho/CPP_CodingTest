#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int num, length;
vector<int> visited;
vector<int> result;

void BackTracking(int depth)
{
    if (depth == length)
    {
        for (int val : result)
            cout << val << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= num; ++i)
    {
        if (find(visited.begin(), visited.end(), i) != visited.end()) continue;

        visited.push_back(i);
        result.push_back(i);

        BackTracking(depth + 1);

        visited.pop_back();
        result.pop_back();
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> num >> length;
    BackTracking(0);
}