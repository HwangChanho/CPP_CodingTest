#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num){
    long long n = num;
    int answer = 0;
    
    while(true){
        if (n == 1)
            return answer;
        
        n % 2 == 0 ? (n /= 2) : (n = 3 * n + 1);
        answer++;
        
        if (answer == 500) {
            return -1;
        }
    }
}
