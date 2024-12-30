#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int>::iterator ptr;
    
    int minElement = *std::min_element(arr.begin(), arr.end());  
    
    if (arr.size() == 1) {
        answer.push_back(-1);
    } else {
        for (ptr = arr.begin(); ptr != arr.end(); ++ptr) {
            if (*ptr == minElement) {
                continue;
            }
        
            answer.push_back(*ptr);
        }
    }
    
    return answer;
}