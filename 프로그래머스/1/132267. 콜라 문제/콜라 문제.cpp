#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    int left = 0;
    int get = 0;
    
    while (n >= a) 
    {
        get = n / a * b;
        left = n % a;
        n = get + left;
        answer += get;
    }
    
    return answer;
}