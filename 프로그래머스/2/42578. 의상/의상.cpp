#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> um;
    
    for(const auto& a : clothes)
    {
        um[a[1]]++;
    }
    
    for (const auto& a : um)
    {
        answer *= a.second + 1;
    }
    
    return answer - 1;
}