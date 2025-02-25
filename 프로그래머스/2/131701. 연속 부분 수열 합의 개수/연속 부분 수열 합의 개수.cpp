#include <string>
#include <vector>
#include <set>

//#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    //int answer = 0;
    set<int> s;
    int sumCnt = 0;
    
    while (sumCnt != elements.size())
    {
        for (int j = 0; j < elements.size(); j++) // 원소 순환
        {
            int sum = 0;
            for (int n = j; n <= j + sumCnt; n++)
            {
                sum += elements[n % elements.size()];
            }
            s.insert(sum);
            //cout << sum << " ";
        }
        //cout << "\n";
        ++sumCnt;
    }
    
    //for (const auto& a : s) cout << a << " ";
    //cout << endl;
    
    return s.size();
}