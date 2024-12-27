#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int temp = 0;
    
    temp = n;
    
    while (true) {
        if (temp < 10) {
            answer += temp;
            break;
        }
        
        answer += temp % 10;
        temp = temp / 10;
    }
    
    return answer;
}