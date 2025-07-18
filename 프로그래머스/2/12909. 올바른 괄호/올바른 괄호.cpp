#include <string>

using namespace std;

bool solution(string s)
{
    int sum = 0;
    
    for (char str : s) {
        str == '(' ? sum++ : sum--;
        if (sum < 0) return false;
    }
    
    return sum == 0;
}