#include <string>
#include <vector>
//#include <iostream>

using namespace std;

int getPrimeCnt(int n) {
    int cnt = 0;
    
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cnt += (i * i == n) ? 1 : 2;
		}
	}
    
	return cnt;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++)
    {
        int num = getPrimeCnt(i);
        
        if (num <= limit)
        {
            answer += num;
        }
        else
        {
            answer += power;
        }
        
        //std::cout << num << endl;
        //std::cout << answer << endl;
    }
    
    return answer;
}