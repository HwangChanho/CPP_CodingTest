#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    vector<int> countY(10, 0);
    for (char ch : Y) 
    {
        countY[ch - '0']++;
    }
    
    for (char ch: X)
    {
        int num = ch - '0';
        if (countY[num])
        {
            answer += ch;
            countY[num]--;
        }
    }
    
    if (answer.empty()) return "-1";
    if (answer[0] == '0') return "0";
    
    sort(answer.begin(), answer.end(), greater<char>());
    
    return answer;
}