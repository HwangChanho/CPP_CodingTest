#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> List(N);

    for (int i = 0; i < N; i++)
    {
        cin >> List[i];
    }

    int left = 0;
    int right = N - 1;

    int min = abs(List[left] + List[right]);
    int minLeft = List[left];
    int minRight = List[right];

    while (left < right)
    {
        int temp = List[left] + List[right];

        if (abs(temp) < min)
        {
            min = abs(temp);
            minLeft = List[left];
            minRight = List[right];
        }

        if (temp == 0) break;
        temp < 0 ? left++ : right--;
    }

    cout << minLeft << " " << minRight;
}