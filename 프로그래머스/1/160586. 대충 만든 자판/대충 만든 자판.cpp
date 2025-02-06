#include <string>
#include <vector>
#include <unordered_map>

//#include <iostream>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> min_presses;
    
    for (const auto& key : keymap) 
    {
        for (int i = 0; i < key.size(); i++) {
            char ch = key[i];
            
            if(min_presses.count(ch))
            {
                min_presses[ch] = min(min_presses[ch], i + 1);
            }
            else
            {
                min_presses[ch] = i + 1;
            }
        }
    }
    
    // for (const auto value : min_presses)
    // {
    //     cout << value.first << ": " << value.second << endl;
    // }
    
    for (const string target : targets)
    {
        int total = 0;
        bool unable = false;
        
        for (char ch : target) {
            if (min_presses.count(ch)) {
                total += min_presses[ch];
            } else {
                unable = true;
                break;
            }
        }
        
        if (unable)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(total);
        }
    }
    
    return answer;
}