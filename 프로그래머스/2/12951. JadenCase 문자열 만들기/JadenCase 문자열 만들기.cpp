#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int count = 0;
    
     for (int i = 0; i < s.size(); i++) {
        if (count == 0) {
            s[i] = isdigit(s[i]) ? s[i] : toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }

        count = (s[i] == ' ') ? 0 : count + 1;
    }
    
    return s;
}