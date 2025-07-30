#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int main() 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    int size;
    cin >> size;

    vector<int> list(size);
    vector<int> answer(size, -1);
    stack<int> mono;

    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < size; i++) 
    {
        while (!mono.empty() && list[mono.top()] < list[i]) 
        {
            answer[mono.top()] = list[i];
            mono.pop();
        }
        mono.push(i);
    }

    for (int a : answer) cout << a << " ";
}