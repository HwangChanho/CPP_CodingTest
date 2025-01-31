#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> cnt = {0, 0, 0};
    vector<int> byungshin1 = {1, 2, 3, 4, 5}; // 5
    vector<int> byungshin2 = {2, 1, 2, 3, 2, 4, 2, 5}; // 8
    vector<int> byungshin3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == byungshin1[i % 5])
        {
            cnt[0]++;
        }
        
        if (answers[i] == byungshin2[i % 8])
        {
            cnt[1]++;
        }
        
        if (answers[i] == byungshin3[i % 10])
        {
            cnt[2]++;
        }
    }
    
    int max = *max_element(cnt.begin(), cnt.end());
    
    for (int i = 0; i < cnt.size(); i++)
    {
        if (max == cnt[i])
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}