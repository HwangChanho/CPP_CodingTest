#include <string>
#include <vector>
#include <map>

#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int days = 0;
    map<string, int> wantValue;
    
    for (int i = 0; i < want.size(); i++)
    {
        wantValue[want[i]] = number[i];
    }
    
    int totalDays = discount.size();
    int windowSize = 10;
    
    for (int i = 0; i <= totalDays - windowSize; i++) {
        map<string, int> tempMap = wantValue;
        bool isValid = true;

        for (int j = i; j < i + windowSize; j++) {
            if (tempMap.find(discount[j]) != tempMap.end()) {
                tempMap[discount[j]]--;
            }
        }

        for (const auto& item : tempMap) {
            if (item.second > 0) { 
                isValid = false;
                break;
            }
        }

        if (isValid) {
            answer++;
        }
    }
    
    return answer;
}