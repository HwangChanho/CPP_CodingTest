#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = { 0, 0, 0, 0 };
    int SharpCount = 0;
    vector<pair<int, int>> Min;
    
    for (int y = 0; y < wallpaper.size(); y++)
    {
        cout << wallpaper[y] << endl;
        for (int x = 0; x < wallpaper[y].size(); x++)
        {
            if (wallpaper[y][x] == '#')
            {
                if (SharpCount == 0)
                {
                    answer[0] = y;
                    answer[1] = x;
                    answer[2] = y;
                    answer[3] = x;
                    
                    for (const auto a : answer)
                    {
                        cout << a;
                    }
                    cout << endl;
                }
                
                cout << y << ", " << x << endl;
                
                if (answer[0] > y)
                {
                    answer[0] = y;
                }
                
                if (answer[1] > x)
                {
                    answer[1] = x;
                }
                
                if (answer[2] < y)
                {
                    answer[2] = y;
                }
                
                if (answer[3] < x)
                {
                    answer[3] = x;
                }
                
                SharpCount++;
            }
        }
    }
    
    answer[2]++;
    answer[3]++;
    
    return answer;
}