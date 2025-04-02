#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isConvertible(const string &a, const string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) 
    {
        if (a[i] != b[i])
            diff++;
        if (diff > 1)
            return false;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    bool exists = false;
    for (const auto& word : words) 
    {
        if (word == target) 
        {
            exists = true;
            break;
        }
    }
    if (!exists) return 0;
    
    int n = words.size();
    vector<bool> visited(n, false);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while (!q.empty()) 
    {
        auto cur = q.front();
        q.pop();
        string word = cur.first;
        int cnt = cur.second;
        
        if (word == target) return cnt;
        
        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && isConvertible(word, words[i])) 
            {
                visited[i] = true;
                q.push({words[i], cnt + 1});
            }
        }
    }
    
    return 0;
}