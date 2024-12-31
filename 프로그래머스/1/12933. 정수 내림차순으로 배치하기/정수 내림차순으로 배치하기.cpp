#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    std::vector<int> numbers = {};
    
    while (n > 0) {
        numbers.push_back(n % 10);
        n /= 10;
    }
    
    sort(numbers.begin(), numbers.end(), greater<int>());
        
     string concatenated = "";
    for (int num : numbers) {
        concatenated += to_string(num);
    }
    
    return stoll(concatenated);
}