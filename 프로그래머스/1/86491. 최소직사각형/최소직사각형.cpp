#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxLeft = 0;
    int maxRight = 0;
    
    for (int i = 0; i < sizes.size(); i++) {
        
        if (sizes[i][0] < sizes[i][1]) {
            std::swap(sizes[i][0], sizes[i][1]);
        }
        
        if (sizes[i][1] > maxRight) {
            maxRight = sizes[i][1];
        }
        
        if (sizes[i][0] > maxLeft) {
            maxLeft = sizes[i][0];
        }
    }
    
    return maxRight * maxLeft;
}