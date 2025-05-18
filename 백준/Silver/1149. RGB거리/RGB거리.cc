#include <bits/stdc++.h>

using namespace std;

int num;
vector<vector<int>> cost;
vector<vector<int>> dp;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> num;

    for (int j = 0; j < num; j++)
    {
        vector<int> temp;
        for (int i = 0; i < 3; i++)
        {
            int n = 0;
            cin >> n;
            temp.push_back(n);
        }
        cost.push_back(temp);
    }

    dp.resize(num, vector<int>(3, 0));

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < num; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }
    
    cout << min({dp[num-1][0], dp[num-1][1], dp[num-1][2]});
}