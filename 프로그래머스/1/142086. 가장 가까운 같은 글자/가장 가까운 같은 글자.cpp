#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for (int i = 0; i < s.length(); i++) {
        int lastIndex = -1;

        for (int j = i - 1; j >= 0; j--) { 
            if (s[j] == s[i]) {
                lastIndex = j;
                break; 
            }
        }

        answer.push_back(lastIndex == -1 ? -1 : i - lastIndex);
    }
    
    return answer;
}