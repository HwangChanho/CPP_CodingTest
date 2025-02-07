#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> vSkip(128, false);

    for (char c : skip) {
        vSkip[c] = true;
    }
    
    for (char c : s)
    {
        int count = index;
        char newChar = c;
        
        while (count > 0)
        {
            newChar++;
            
            if (newChar > 'z')
            {
                newChar = 'a';
            }
            
            if (!vSkip[newChar])
            {
                count--;
            }
        }
        
        answer += newChar;
    }
    
    return answer;
}