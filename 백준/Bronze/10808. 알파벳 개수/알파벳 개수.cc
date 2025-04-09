#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    map<char, int>wordMap;

    string word = "hello";
    getline(cin, word);

    for (int i = 97; i <= 122; i++)
    {
        wordMap[static_cast<char>(i)] = 0;
    }

    for (const char& spell : word)
    {
        wordMap[spell]++;
    }

    for (const auto& value : wordMap) cout << value.second << " ";
    return 0;
}