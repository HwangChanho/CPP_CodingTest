#include <string>
#include <vector>
#include <map>
// #include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    vector<int> Score = { 3, 2, 1, 0, -1, -2, -3 };
    vector<string> Chart = { "RT", "CF", "JM", "AN" };
    map<char, int> PersonalityType;
    
    for (int i = 0; i < survey.size(); i++)
    {
        int score = Score[choices[i] - 1];
        if (score < 0)
        {
            PersonalityType[survey[i][1]] += (score * -1);
        }
        else 
        {
            PersonalityType[survey[i][0]] += score;
        }
    }
    
    for (int i = 0; i < Chart.size(); i++)
    {
        if (PersonalityType[Chart[i][0]] < PersonalityType[Chart[i][1]])
        {
            answer[i] = Chart[i][1];
        }
    }
    
	// for (auto iter : PersonalityType) {
	// 	cout << iter.first << " " << iter.second << endl;
	// }
    
    // 3, 2, 1, 0, -1, -2, -3 
    // survey 
    
    
    return answer;
}