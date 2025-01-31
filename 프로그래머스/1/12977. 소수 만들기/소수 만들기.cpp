#include <vector>
#include <iostream>
#include <cmath>
// #include <algorithm>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
    
	return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    // 완전탐색밖에 모르겠다..
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isPrime(nums[i] + nums[j] + nums[k])) {
                    // std::cout << nums[i] << " " << nums[j] << " " << nums[k] << "\n";
                    answer += 1;
                }
            }
        }
    }

    return answer;
}