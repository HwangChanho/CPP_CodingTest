#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer = (int*)malloc(4 * 12);
    memset(answer, 0, sizeof(int) * 12);
    int index = 0;
    
    answer[index] = n % 10;
    
    while (n > 0) {
        answer[index++] = n % 10; 
        n /= 10;
    }
    
    int* result = (int*)malloc(sizeof(int) * index);
    memcpy(result, answer, sizeof(int) * index);
    free(answer);
    
    return result;
}