#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int index = 0;
    stack<int> temp;
    
    for (int box = 1; box <= order.size(); ++box) {
        if (order[index] == box) {
            index++;
        } else {
            temp.push(box);
        }

        while (!temp.empty() && temp.top() == order[index]) {
            temp.pop();
            index++;
        }
    }
    
    return index;
}