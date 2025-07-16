#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> dq;
    
    sort(people.begin(), people.end());
    
    for (int person : people)
    {
        dq.emplace_back(person);
    }
    
    while (dq.size() > 1)
    {
        int front = dq.front();
        int back = dq.back();
        
        if (limit < front + back)
        {
            dq.pop_back();
        }
        else
        {
            dq.pop_front();
            dq.pop_back();
        }
        
        answer++;
    }
    
    answer += dq.size();
    
    return answer;
}