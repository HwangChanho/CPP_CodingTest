#include <string>
#include <vector>

using namespace std;

int countWays(const vector<int>& numbers, int target, int idx, int sum) {
    if (idx == numbers.size())
        return (sum == target) ? 1 : 0;
    return countWays(numbers, target, idx + 1, sum + numbers[idx]) +
           countWays(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    return countWays(numbers, target, 0, 0);
}