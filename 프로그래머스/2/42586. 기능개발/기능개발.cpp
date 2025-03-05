#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int days = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] > 0)
            ++days;
        q.push(days);
    }
    
    while (!q.empty()) 
    {
        int first = q.front();
        q.pop();
        int cnt = 1;
        
        while (!q.empty() && q.front() <= first)
        {
            ++cnt;
            q.pop();
        }
        
        answer.push_back(cnt);
    }
        
    
    return answer;
}