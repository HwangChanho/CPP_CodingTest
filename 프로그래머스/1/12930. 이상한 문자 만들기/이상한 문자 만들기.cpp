#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            count = 0;
        } else {
            if (count % 2) {
                answer += tolower(s[i]);
            } else {
                answer += toupper(s[i]);
            }
        
            count++;
        }
    }
    
    return answer;
}