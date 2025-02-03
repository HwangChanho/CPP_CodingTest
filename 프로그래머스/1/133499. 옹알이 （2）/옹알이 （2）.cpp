#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isValid(const string& word) {
    vector<string> patterns = {"aya", "ye", "woo", "ma"};
    string last = "";  // 마지막으로 사용한 패턴 저장
    int i = 0;

    while (i < word.length()) {
        bool matched = false;

        for (const string& pattern : patterns) {
            int len = pattern.length();

            if (word.substr(i, len) == pattern && last != pattern) {
                matched = true;
                last = pattern;
                i += len;
                break;
            }
        }

        if (!matched) return false;
    }
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (const string& word : babbling) {
        if (isValid(word)) {
            answer++;
        }
    }
    return answer;
}