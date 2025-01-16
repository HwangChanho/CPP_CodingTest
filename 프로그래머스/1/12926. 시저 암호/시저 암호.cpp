#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i =0; i < s.length(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            continue;
        }
         
        char currentChar = s[i];
        
         if (isupper(currentChar)) {
            answer += (currentChar - 'A' + n) % 26 + 'A';
        } else if (islower(currentChar)) {
            answer += (currentChar - 'a' + n) % 26 + 'a';
        }
        
    }
    
    return answer;
}