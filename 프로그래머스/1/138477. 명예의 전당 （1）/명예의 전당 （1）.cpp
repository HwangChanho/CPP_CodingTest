#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> kTemp;
    
    for (int i = 0; i < score.size(); i++)
    {
        if (kTemp.size() >= k) // 명예의 전당 사이즈 초과시
        {
            auto minScore = min_element(kTemp.begin(), kTemp.end());
            if (*minScore < score[i])
            {
                kTemp.erase(minScore);
                kTemp.push_back(score[i]);
            }
        } 
        else 
        {
            kTemp.push_back(score[i]);
        }
        
        answer.push_back(*min_element(kTemp.begin(), kTemp.end()));
    }
    
    return answer;
}