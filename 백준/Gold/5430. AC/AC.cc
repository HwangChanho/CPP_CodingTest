#include <bits/stdc++.h> // gcc 에만 있음 헤더 묶음

using namespace std;

int T;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string cmd;
        cin >> cmd;

        int num;
        cin >> num;

        string data;
        cin >> data;

        deque<int> dq;
        bool isReversed = false;
        string temp = "";

        for (int j = 0; j < data.size(); j++)
        {
            if (data[j] != '[' && data[j] != ']')
            {
                if (data[j] == ',')
                {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
                else
                {
                    temp += data[j];
                }
            }
        }

        if (!temp.empty())
        {
            dq.push_back(stoi(temp));
        }

        for (const auto value : cmd)
        {
            if (value == 'D') // 삭제
            {
                num--;
                if (isReversed)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }
            }
            else // 반전
            {
                isReversed = !isReversed;
            }
        }

        if (num >= 0)
        {
            cout << "[";

            if (!dq.empty())
            {
                if (isReversed)
                {
                    cout << dq.back();
                    dq.pop_back();
                }
                else
                {
                    cout << dq.front();
                    dq.pop_front();
                }

                while (!dq.empty())
                {
                    cout << ",";
                    if (isReversed)
                    {
                        cout << dq.back();
                        dq.pop_back();
                    }
                    else
                    {
                        cout << dq.front();
                        dq.pop_front();
                    }
                }
            }

            cout << "]\n";
        }
        else
        {
            cout << "error\n";
        }
    }
}