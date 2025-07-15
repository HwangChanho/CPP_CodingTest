#include <string>
#include <vector>
#include <algorithm>

#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    map<int, vector<int>> cover;
    int alive = 0;
    
    vector<int> to_remove_lost, to_remove_reserve;
    
    for (int loose : lost) 
    {
        for (int me : reserve) 
        {
            if (loose == me) 
            {
                to_remove_lost.push_back(loose);
                to_remove_reserve.push_back(me);
                break;
            }
        }
    }
    
    for (int val : to_remove_lost) 
    {
        lost.erase(remove(lost.begin(), lost.end(), val), lost.end());
    }
    for (int val : to_remove_reserve) 
    {
        reserve.erase(remove(reserve.begin(), reserve.end(), val), reserve.end());
    }
    
    for (int avail : reserve)
    {
        if (avail - 1 > 0)
        {
            cover[avail].push_back(avail - 1);
        }
        if (avail + 1 <= n)
        {
            cover[avail].push_back(avail + 1);
        }
    }
    
    sort(lost.begin(), lost.end());
    
    for (int loose : lost)
    {
        bool found = false;
        
        if (cover.count(loose - 1) && !cover[loose - 1].empty()) {
            alive++;
            cover[loose - 1].clear();
            found = true;
        }
        else if (cover.count(loose + 1) && !cover[loose + 1].empty()) {
            alive++;
            cover[loose + 1].clear();
            found = true;
        }
    }
    
    int left = lost.size() - alive;
    
    if (left > 0)
        n -= left;
    
    return n;
}