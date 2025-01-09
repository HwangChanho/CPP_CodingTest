#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    std::vector<int> ternary;
    int answer = 0;
    
    while (n > 0) {
        ternary.push_back(n % 3);
        n /= 3;
    }
    
    for (int i = 0; i < ternary.size(); i++) {
        answer += ternary[i] * pow(3, ternary.size() - 1 - i);
    }
    
    return answer;
}