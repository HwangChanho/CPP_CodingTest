#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#include <iostream>

using namespace std;

bool is_prime(long long n) 
{
    if (n < 2) return false;
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++)
    {
        if (n % i == 0) 
            return false;
    }
    
    return true;
}

string BinarytoString(int n, int k)
{
    string binary = "";
    while(n > k)
    {
        binary += to_string(n % k);
        n /= k;
    }
    binary += to_string(n);
    return binary;
}

int solution(int n, int k) {
    int answer = 0;
    string binary = BinarytoString(n, k);
    reverse(binary.begin(), binary.end());
    
    //cout << binary << endl;
        
    string check = "";
    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] == '0')
        {
            if (!check.empty() && is_prime(stoll(check))) ++answer;
            check = "";
        }
        else
            check += binary[i];
    }
    
    if (!check.empty() && is_prime(stoll(check)))
        ++answer;
    
    return answer;
}