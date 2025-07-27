#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N;
vector<int> AList;
int M;

void binarySearch(int lowIdx, int highIdx, int target)
{
    int pivotIdx = (lowIdx + highIdx) / 2;
    int pivot = AList[pivotIdx];
    bool inFinal = false;

    if (highIdx - lowIdx < 10)
    {
        inFinal = true;
        for (int i = lowIdx; i <= highIdx; i++)
        {
            if (AList[i] == target)
            {
                cout << "1\n";
                return;
            }
        }
    }

    if (inFinal) 
    {
        cout << "0\n";
        return;
    }

    if (pivot < target)
    {
        binarySearch(pivotIdx + 1, highIdx, target);
    }
    else if (pivot > target)
    {
        binarySearch(lowIdx, pivotIdx - 1, target);
    }
    else
    {
        cout << "1\n";
    }
}

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        AList.push_back(n);
    }

    sort(AList.begin(), AList.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;

        binarySearch(0, N - 1, n);
    }
}