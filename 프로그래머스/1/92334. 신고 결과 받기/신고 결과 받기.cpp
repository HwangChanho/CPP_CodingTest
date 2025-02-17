#include <string>
#include <vector>
#include <map>
#include <set>

//#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> reportedMap;
    map<string, set<string>> reporterMap;
    
    for (const string& id : id_list)
    {
        reportedMap[id] = 0;
        reporterMap[id] = {};
    }
    
    for(const string& rep : report)
    {
        size_t pos = rep.find(' ');
        string reporter = rep.substr(0, pos);
        string reported = rep.substr(pos + 1, rep.size());
        
        if (reporterMap[reporter].insert(reported).second) {
            reportedMap[reported] += 1;
        }
    }
    
    for (const string& id : id_list) {
        int count = 0;
        for (const string& blocked : reporterMap[id]) {
            if (reportedMap[blocked] >= k) {
                count++;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}