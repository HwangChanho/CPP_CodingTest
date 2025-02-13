#include <string>
#include <vector>
#include <map>
//#include <iostream>

using namespace std;

typedef struct 
{
    int x, y;
} coordinate;

coordinate direction[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 북 남 서 동
map<char, int> mapping = { { 'N', 0 }, { 'S', 1 }, { 'W', 2 }, { 'E', 3 } };

vector<int> solution(vector<string> park, vector<string> routes) {
    pair<int, int> currentPosition;
    
    int H = park.size();
	int W = park[0].size();
    
    // 시작 위치 탐색
    for (int i = 0; i < H; i++) {
	    for (int j = 0; j < W; j++) {
	        if (park[i][j] == 'S') {
	            currentPosition = { i, j };
	            break;
	        }
	    }
	}
    
    for (const auto &route : routes)
    {
        char op = mapping[route[0]]; // 배열의 인덱스로 저장
        int n = route[2] - '0';
        
        int nx = currentPosition.first;
        int ny = currentPosition.second;
        
        while (n--) {
            nx += direction[op].x;
            ny += direction[op].y;
            
            if ((nx < 0 || H <= nx || ny < 0 || W <= ny) || park[nx][ny] == 'X')
            {
                break;
            }
        }
        
        if (n < 0) currentPosition = {nx, ny};
    }
    
    return {currentPosition.first, currentPosition.second};
}