#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    long long totalPrice = 0;
    int maxRequest = 0;

    int num;
    cin >> num;

    vector<int> request(num);

    for (int i = 0; i < num; i++)
    {
        int n;
        cin >> n;
        request.push_back(n);
        totalPrice += n;
        maxRequest = max(maxRequest, n);
    }

    int sum;
    cin >> sum;

    if (totalPrice <= sum)
    {
        cout << maxRequest << endl;
        return 0;
    }

    int first = 0;
    int last = maxRequest;
    int answer = 0;

    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        long long currentSum = 0;

        for (int price : request)
        {
            if (price > mid)
            {
                currentSum += mid;
            }
            else
            {
                currentSum += price;
            }
        }

        if (currentSum <= sum)
        {
            answer = mid;
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    cout << answer;
}