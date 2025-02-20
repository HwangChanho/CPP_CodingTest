#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr) {
    if (arr.size() < 2) return *arr.begin();
    
    return reduce(arr.begin(), arr.end(), 1, lcm<int, int>);
}