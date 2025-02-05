#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char firstChar = s[0];
    int same = 0;
    int different = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == firstChar)
        {
            ++same;
        }
        else 
        {
            ++different;
        }
        
        if (same == different)
        {
            ++answer;
            if (i + 1 < s.length()) 
            {
                firstChar = s[i + 1];
            }
            same = 0;
            different = 0;
        }
    }
    
    if (same != 0 || different != 0) {
        ++answer;
    }
    
    return answer;
}