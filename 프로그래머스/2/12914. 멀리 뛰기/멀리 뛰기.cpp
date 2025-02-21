#include <string>
#include <vector>

#include <algorithm>

// 순열 (시간초과) DP
using namespace std;

long long solution(int n) {
    long long answer = 0;
    int prev2 = 2;
    int prev1 = 3;
    
    if (n <= 3) return n;
    
     // f(n) = f(n-1) + f(n-2)
    for (int i = 4; i <= n; ++i) {
        answer = (prev1 + prev2) % 1234567;
        prev2 = prev1;
        prev1 = answer;
    }
    
    return answer;
}

/*
long long solution(int n) {
    long long answer = 0;
    
    for (int i = 0; i <= n / 2; i++)
    {
        int twoCnt = i;
        int oneCnt = n - 2 * i;
        
        vector<int> board;
        for (int i = 0; i < oneCnt; ++i) board.push_back(1);
        for (int i = 0; i < twoCnt; ++i) board.push_back(2);
        
        do {
            ++answer;
        } while (next_permutation(board.begin(), board.end()));
    }
    
    return answer % 1234567;
}
*/