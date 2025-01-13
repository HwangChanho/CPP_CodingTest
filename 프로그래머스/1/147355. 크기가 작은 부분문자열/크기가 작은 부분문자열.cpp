#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pLength = p.length();
    
    for (int i = 0; i <= t.length() - pLength; i++) {
        string tmp = t.substr(i, pLength);
        
        long tmpInt = stol(tmp);
        long pInt = stol(p);
        
        if (tmpInt <= pInt) {
            answer++;
        }
    }
    
    return answer;
}