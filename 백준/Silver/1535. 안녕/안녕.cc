#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> health(n), happy(n);
    for (int i = 0; i < n; i++) 
        cin >> health[i];
    
    for (int i = 0; i < n; i++) 
        cin >> happy[i];
    
    vector<int> dp(100, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 99; j >= health[i]; j--) {
            dp[j] = max(dp[j], dp[j - health[i]] + happy[i]);
        }
    }
    
    int maxHappy = 0;
    for (int j = 0; j < 100; j++) {
        maxHappy = max(maxHappy, dp[j]);
    }
    
    cout << maxHappy;
    return 0;
}