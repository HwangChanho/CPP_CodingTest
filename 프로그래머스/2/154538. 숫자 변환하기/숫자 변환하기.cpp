#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int solution(int x, int y, int n) {
    int dp[1'000'001];
    memset(dp, 1'000'001, 1'000'001 * sizeof(int));
    
    dp[y] = 0;
    for(int i = y; i > x; --i)
    {
        if(i-n > 0)
            dp[i-n] = min(dp[i-n], dp[i]+1); 
    
        if(i%2 == 0)
            dp[i/2] = min(dp[i/2], dp[i]+1);
        
        if(i%3 == 0)
            dp[i/3] = min(dp[i/3], dp[i]+1);
    }
    
    if(dp[x] >= 1'000'001)
        dp[x] = -1;
    
    return dp[x];
}