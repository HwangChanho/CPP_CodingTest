#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> right, left;
    
    for (int t : topping) {
        right[t]++;
    }
    
    for (int t : topping) {
        left[t]++;
        right[t]--;
        if (right[t] == 0) right.erase(t);
        if (left.size() == right.size()) answer++;
    }
    
    return answer;
}