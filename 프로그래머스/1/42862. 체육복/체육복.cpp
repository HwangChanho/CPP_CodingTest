#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    vector<int> realLost; 
    
    for (auto it = lost.begin(); it != lost.end();) {
        if (find(reserve.begin(), reserve.end(), *it) != reserve.end()) {
            reserve.erase(find(reserve.begin(), reserve.end(), *it));
            it = lost.erase(it);
        } else {
            realLost.push_back(*it);
            ++it;
        }
    }
    
    for (auto it = realLost.begin(); it != realLost.end();) {
        bool found = false;
        for (auto resIt = reserve.begin(); resIt != reserve.end(); ++resIt) {
            if (*resIt == *it - 1 || *resIt == *it + 1) {
                reserve.erase(resIt);
                it = realLost.erase(it);
                found = true;
                break;
            }
        }
        if (!found) {
            ++it;
        }
    }
    
    return n - realLost.size();
}