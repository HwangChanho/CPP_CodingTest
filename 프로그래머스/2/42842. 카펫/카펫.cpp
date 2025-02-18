#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

//#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    for (int height = 3; ; height++) 
    {
        if (!(total % height)) 
        {
            int weight = total / height;
            if (((height - 2) * (weight - 2)) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }
    
    return answer;
}