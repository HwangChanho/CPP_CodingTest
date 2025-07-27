#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

long long N;
long long M;
vector<long long> trees;

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        long long n;
        cin >> n;
        trees.push_back(n);
    }

    sort(trees.begin(), trees.end());

    long long low = 0;
    long long high = trees[N - 1];
    long long answer = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long sum = 0;

        for (long long value : trees)
        {
            if (value > mid)
            {
                sum += (value - mid);
            }
        }

        if (sum >= M)
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << answer;
    return 0;
}