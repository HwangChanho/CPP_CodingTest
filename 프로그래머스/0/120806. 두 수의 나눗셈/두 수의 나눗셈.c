#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    int answer = 0;
    double a = num1;
    double b = num2;
    
    answer = (a / b) * 1000;
    
    return answer;
}