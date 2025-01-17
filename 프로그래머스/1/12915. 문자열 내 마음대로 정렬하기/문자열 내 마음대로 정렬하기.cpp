#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;

bool comp(string a, string b)
{
    if(a[index] < b[index])
        return true;
    else if(a[index] == b[index])
    {
        if(a < b)
            return true;
        return false;
    }
    return false;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    index = n;
    sort(strings.begin(),strings.end(),comp);
    answer = strings;
    
    return answer;
}