#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

#include <iostream>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, vector<string>> routes;
    
    for (const auto& ticket : tickets) 
    {
        routes[ticket[0]].push_back(ticket[1]);
    }
    
    for (auto& value : routes) 
    {
        sort(value.second.rbegin(), value.second.rend());
        // 내림차순 정렬
    }
    
    for (auto& value : routes) 
    {
        cout << value.first << ": ";
        for (auto& a : value.second)
        {
            cout << a << " ";
        }
        cout << "\n";
    }
    
    stack<string> s;
    s.push("ICN");
    
    while (!s.empty()) 
    {
        string current = s.top();

        if (routes[current].empty()) 
        {
            answer.push_back(current);
            s.pop();
        } 
        else 
        {
            string next = routes[current].back();
            routes[current].pop_back();   
            s.push(next);                 
        }
    }

    reverse(answer.begin(), answer.end());
    
    return answer;
}