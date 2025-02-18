#include <string>
#include <vector>

//#include <iostream>

using namespace std;

int fivo(int num)
{
    if (num == 0 || num == 1) return num;
    return fivo(num - 2) + fivo(num - 1);
}

int arr[100001];
int solution(int n) {
    int answer = 0;
    
    arr[0] = 0;
    arr[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
    }
    
    answer = arr[n];
    return answer;
}