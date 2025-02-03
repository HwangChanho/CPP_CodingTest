#include <string>
#include <vector>

using namespace std;

int getScore(int num)
{
    switch (num)
    {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int ifCnt = 0;
    int cnt = 0;
    
    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
        {
            ifCnt++;
        } 
        else
        {
            for (int j = 0; j < win_nums.size(); j++)
            {
                if (lottos[i] == win_nums[j])
                {
                    cnt++;
                }
            }
        }
    }
    
    return {getScore(cnt+ifCnt), getScore(cnt)};
}