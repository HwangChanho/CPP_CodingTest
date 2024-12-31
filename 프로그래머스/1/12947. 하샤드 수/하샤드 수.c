#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    int original = x;
    int a = 0;
    
    while (x > 0) {
        a += x % 10;
        x /= 10;
    }
    
    return (original % a == 0);
}