#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<int, string> scorePlayer;
    map<string, int> playerScore;
    
    for(int i = 0; i < players.size(); i++)
    {
        scorePlayer[i] = players[i];
        playerScore[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++)
    {
        int cur_idx = playerScore[callings[i]];
        string change = scorePlayer[cur_idx - 1];
        
        scorePlayer[cur_idx - 1] = callings[i];
        scorePlayer[cur_idx] = change;
        
        playerScore[callings[i]] = cur_idx - 1;
        playerScore[change] = cur_idx;
    }
    
    for (auto player : scorePlayer) 
    {
        answer.push_back(player.second);
    }
    
    return answer;
}