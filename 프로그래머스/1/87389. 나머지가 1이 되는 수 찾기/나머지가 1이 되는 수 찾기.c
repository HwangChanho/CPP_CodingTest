#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int count = 1;
    
    while (true) {
        if (n % count == 1) {
            answer = count;
            break;
        }
        
        count++;
    }
    
    return answer;
}