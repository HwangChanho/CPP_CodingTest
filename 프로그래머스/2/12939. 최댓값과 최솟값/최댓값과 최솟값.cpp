#include <string>
#include <vector>

//#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    string strNum = "";
    
    int min = stoi(s.substr(0, s.find(' ')));
    int max = min;
    
    for (const char& num : s)
    {
        if (num != ' ') {
            strNum += num;
            continue;
        }
        
        int intNum = stoi(strNum);
        
        if (intNum < min) min = intNum;
        if (intNum > max) max = intNum;
        
        strNum = "";
    }
    
    if (!strNum.empty())
    {
        int intNum = stoi(strNum);
        if (intNum < min) min = intNum;
        if (intNum > max) max = intNum;
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}