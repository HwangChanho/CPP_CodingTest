#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int T;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int count;
        cin >> count;

        priority_queue<int, vector<int>, less<int>> maxPQ;
        priority_queue<int, vector<int>, greater<int>> minPQ;
        unordered_map<int, int> deleted; // lazy deletion

        for (int j = 0; j < count; j++)
        {
            string operation;
            int value;

            cin >> operation >> value;

            if (operation == "I") // insert
            {
                maxPQ.push(value);
                minPQ.push(value);
                deleted[value]++;
            }
            else if (operation == "D") // delete
            {
                if (value > 0)
                {
                    if (!maxPQ.empty())
                    {
                        deleted[maxPQ.top()]--;
                        maxPQ.pop();
                    }
                }
                else if (value < 0)
                {
                    if (!minPQ.empty())
                    {
                        deleted[minPQ.top()]--;
                        minPQ.pop();
                    }
                }

                while (!minPQ.empty() && deleted[minPQ.top()] == 0) minPQ.pop();
                while (!maxPQ.empty() && deleted[maxPQ.top()] == 0) maxPQ.pop();
            }
        }

        while (!minPQ.empty() && deleted[minPQ.top()] == 0) minPQ.pop();
        while (!maxPQ.empty() && deleted[maxPQ.top()] == 0) maxPQ.pop();

        if (minPQ.empty() || maxPQ.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << maxPQ.top() << " ";
            cout << minPQ.top() << "\n";
        }
    }
}