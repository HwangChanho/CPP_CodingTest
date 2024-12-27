#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int a = n / 2;
    int b = 2 + n;
    
    if (a % 2 == 0) {
        answer = b * (a / 2);
    } else {
        answer = b * (a / 2) + b / 2;
    }
    
    
    return answer;
}