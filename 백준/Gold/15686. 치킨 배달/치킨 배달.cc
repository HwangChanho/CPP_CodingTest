#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

// 0: 빈칸, 1: 집, 2: 치킨집
int N, M; // 도시 크기, 최대 치킨집의 개수
int answer = INT_MAX;
vector<vector<int>> board;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

// 조합
vector<vector<pair<int, int>>> combination;
vector<pair<int, int>> tempComb;

int getDistance(pair<int, int> &from, pair<int, int> &to)
{
    return abs(from.first - to.first) + abs(from.second - to.second);
}

void makeCombination(vector<vector<pair<int, int>>> &result, vector<pair<int, int>> &comb, int index, int k)
{
    if (k == 0)
    {
        result.push_back(comb);
        return;
    }

    if (index == chicken.size())
        return;

    comb.push_back(chicken[index]);
    makeCombination(result, comb, index + 1, k - 1);

    comb.pop_back();
    makeCombination(result, comb, index + 1, k);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;
    board.resize(N + 1, vector<int>(N + 1));

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
            else if (board[i][j] == 1)
            {
                house.push_back({i, j});
            }
        }
    }

    if (chicken.size() != M)
    {
        makeCombination(combination, tempComb, 0, M);
    }
    else
    {
        combination.push_back(chicken);
    }

    for (auto &comb : combination)
    {
        // 치킨집 조합 후보 루프 시작
        vector<int> houseNum(house.size(), INT_MAX);
        for (auto &val : comb)
        {
            for (int i = 0; i < house.size(); i++)
            {
                int value = getDistance(val, house[i]);

                houseNum[i] = min(houseNum[i], value);
            }
        }

        int total = 0;
        for (int val : houseNum) total += val;
        answer = min(answer, total);
    }

    cout << answer;
}