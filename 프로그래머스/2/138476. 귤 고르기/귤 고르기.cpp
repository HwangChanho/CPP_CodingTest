#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <iostream>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> tMap;
    
    for (const auto &t : tangerine)  ++tMap[t];
    
    vector<pair<int, int>> toSort(tMap.begin(), tMap.end());
    
    sort(toSort.begin(), toSort.end(), comp);
    
    for (const auto &t : toSort)
    {
        if (k > 0)
        {
            k = k - t.second;
            ++answer;
            
            //cout << "k: " << k << " answer: " << answer << "\n";
        }
        
        if (k == 0) break;
    }
    
    return answer;
}