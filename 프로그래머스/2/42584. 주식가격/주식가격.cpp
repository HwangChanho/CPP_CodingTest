#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), -1);
    
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i; j < prices.size(); j++)
        {
            if (prices[i] <= prices[j])
            {
                answer[i]++;
            }
            else
            {
                answer[i]++;
                break;
            }
        }
    }
        
    
    return answer;
}