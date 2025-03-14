#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>

// ceil()
// fees[0] -> 기본 시간
// fees[1] -> 기본 요금
// fees[2] -> 단위 시간
// fees[3] -> 단위 요금

#include <iostream>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, double> recordMap;
    
    for (const string& record : records)
    {
        istringstream iss(record);
        string word;
        vector<string> temp;
    
        while (iss >> word) {
            temp.push_back(word);
        }
        
        if (temp[2] == "IN")
        {
            double hour = 0;
            double min = 0;
            size_t pos = temp[0].find(':');
            
             if (pos != string::npos) {
                hour = stoi(temp[0].substr(0, pos));
                min = stoi(temp[0].substr(pos + 1));
            }
            recordMap[temp[1]] -= hour * 60 + min;
        }
        else if (temp[2] == "OUT")
        {
            double hour = 0;
            double min = 0;
            size_t pos = temp[0].find(':');
            
             if (pos != string::npos) {
                hour = stoi(temp[0].substr(0, pos));
                min = stoi(temp[0].substr(pos + 1));
            }
            recordMap[temp[1]] += hour * 60 + min;
        }
        
        temp = {};
    }
    
    for (const auto& a : recordMap)
    {
        if (a.second <= 0)
        {
            recordMap[a.first] += 24 * 60 - 1;
        }
        
        double fee = fees[1] + ceil((a.second - fees[0]) / fees[2]) * fees[3];
        if (fee < fees[1]) fee = fees[1];
        answer.push_back(fee);
        
        //cout << "ceil: " << ceil((a.second - fees[0]) / fees[2]) << endl;
        //cout << "number: " << a.first << " total hour: " << a.second << " fee: " << fee << endl;
    }
    
    return answer;
}