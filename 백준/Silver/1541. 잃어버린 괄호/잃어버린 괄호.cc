#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

vector<int> nums;
int sum;

int main()
{
    string input;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> input;

    string temp = "";

    for (const char c : input)
    {
        if (c == '-')
        {
            sum += atoi(temp.c_str());
            nums.push_back(sum);
            temp = "";
            sum = 0;
        }
        else if (c == '+')
        {
            sum += atoi(temp.c_str());
            temp = "";
        }
        else
        {
            temp += c;
        }
    }

    sum += atoi(temp.c_str());
    nums.push_back(sum);
    sum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        sum -= nums[i];
    }

    cout << sum;
}