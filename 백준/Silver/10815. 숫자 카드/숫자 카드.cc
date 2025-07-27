#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int cardNum;
vector<int> cardList;
int findNum;
vector<bool> answer;

// -10 2 3 6 10
void binarySearch(int lowIdx, int highIdx, int target)
{
    int pivotIdx = (lowIdx + highIdx) / 2;
    int pivot = cardList[pivotIdx];
    bool inFinal = false;

    if (highIdx - lowIdx < 10)
    {
        inFinal = true;
        for (int i = lowIdx; i <= highIdx; i++)
        {
            if (cardList[i] == target)
            {
                cout << "1 ";
                return;
            }
        }
    }

    if (inFinal) 
    {
        cout << "0 ";
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
        cout << "1 ";
    }
}

int main(int argc, char** argv) 
{
	cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> cardNum;

    for (int i = 0; i < cardNum; i++)
    {
        int n;
        cin >> n;
        cardList.push_back(n);
    }

    sort(cardList.begin(), cardList.end());

    cin >> findNum;

    for (int i = 0; i < findNum; i++)
    {
        int n;
        cin >> n;

        binarySearch(0, cardNum - 1, n);
    }
}