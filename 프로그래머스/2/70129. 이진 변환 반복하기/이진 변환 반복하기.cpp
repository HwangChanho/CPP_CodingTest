#include <string>
#include <vector>

//#include <iostream>

using namespace std;

string toBinary(int num)
{
    if (num == 0) return "0";
    
    string str = "";
    while (num)
    {
        str = char('0' + (num & 1)) + str;
        num >>= 1;
    }
    
    return str;
}

vector<int> solution(string s) {
    vector<int> answer;
    string temp = s;
    int loopCnt = 0;
    int zeroCnt = 0;
    
    while(temp != "1")
    {
        string a = "";
        for (const char& ch : temp)
        {
            if (ch == '0')
            {
                ++zeroCnt;
            } 
            else
            {
                a += ch;
            }
        }
        
        temp = toBinary(a.size());
        ++loopCnt;
    }
    
    return {loopCnt, zeroCnt};
}