#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }
    
    for (char c : s) {
        if (std::isalpha(c)) {
            return false;
        }  
    }
    
    return true;
}