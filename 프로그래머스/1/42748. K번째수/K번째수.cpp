#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int j = 0; j < commands.size(); j++) {
        vector<int> command = commands[j];
        int from = command[0] - 1;
        int to = command[1] - 1;
        int where = command[2] - 1;
        vector<int> toSort;
        
        for (int i = 0; i < array.size(); i++) {
    if (i >= from && i <= to) {
        toSort.push_back(array[i]);
    }
}
        
        sort(toSort.begin(), toSort.end());
        answer.push_back(toSort[where]);
    }
    
    return answer;
}