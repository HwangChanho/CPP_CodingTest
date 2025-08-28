#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int N, M;
int answer;
int sum;

void findDeck(vector<int>& cardDeck, int current, int start)
{
    if (current == 3)
    {
        if (sum <= M)
        {
            answer = max(answer, sum);
        }
        return;
    }

    for (int i = start; i < cardDeck.size(); i++)
    {
        sum += cardDeck[i];
        findDeck(cardDeck, current + 1, i + 1);
        sum -= cardDeck[i];
    }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> M;

    vector<int> cards(N);
    for (int i = 0; i < N; i++)
        cin >> cards[i];

    findDeck(cards, 0, 0);

    cout << answer;
}