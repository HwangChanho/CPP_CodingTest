#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end(), comp);
    
    int boxCount = score.size() / m;
    int left = score.size() % m;
    
    for (int i = 1; i <= score.size(); i++)
    {
        if (i % m == 0)
        {
            answer += score[i - 1] * m;
        }
    }
    
    return answer;
}