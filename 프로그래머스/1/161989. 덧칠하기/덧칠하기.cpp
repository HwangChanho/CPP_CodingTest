#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int first = section[0];

    for (int j = 0; j < section.size(); j++)
    {
        if (section[j] - first + 1 > m)
        {
            answer++;
            first = section[j];
        }
    }

    
    return answer;
}