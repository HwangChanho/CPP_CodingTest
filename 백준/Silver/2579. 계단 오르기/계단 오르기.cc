#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음
using namespace std;

int floorNum;
int maxScore;
vector<int> floorScore;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> floorNum;

    for (int i = 0; i < floorNum; i++)
    {
        int score;
        cin >> score;
        floorScore.push_back(score);
    }

    if (floorNum < 3)
    {
        for (int score : floorScore)
            maxScore += score;

        cout << maxScore << "\n";
        return 0;
    }

    vector<int> dpArr(floorNum);

    dpArr[0] = floorScore[0];
    dpArr[1] = floorScore[0] + floorScore[1];
    dpArr[2] = max(floorScore[0] + floorScore[2], floorScore[1] + floorScore[2]);

    for (int i = 3; i < floorNum; i++)
    {
        dpArr[i] = max(dpArr[i - 2], dpArr[i - 3] + floorScore[i - 1]) + floorScore[i];
    }

    cout << dpArr[floorNum - 1] << "\n";
    return 0;
}