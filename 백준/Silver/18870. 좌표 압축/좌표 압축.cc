#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N;

    vector<pair<int, int>> vlist(N);
    vector<int> answer(N);

    for (int i = 0; i < N; i++)
    {
        vlist[i].first = i;
        cin >> vlist[i].second;
    }

    sort(vlist.begin(), vlist.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
    {
        return a.second < b.second;
    });

    int last = -1;
    int cnt = -1;
    for (int i = 0; i < vlist.size(); i++)
    {
        int index = vlist[i].first;
        int value = vlist[i].second;

        if (value == last)
        {
            last = value;
            answer[index] = cnt;
        }
        else
        {
            cnt++;
            last = value;
            answer[index] = cnt;
        }
    }

    for (auto val : answer)
    {
        cout << val << " ";
    }
}