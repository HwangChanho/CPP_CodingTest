#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s) {
    string answerStr = "";
    string alphabat = "";
    
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            // 숫자
            answerStr += s[i];
        } else {
            // 문자
            alphabat += s[i];
            
            if (alphabat == "one") {
                answerStr += '1'; 
                alphabat = "";
            } else if (alphabat == "two") {
                answerStr += '2';
                alphabat = "";
            } else if (alphabat == "three") {
                answerStr += '3';
                alphabat = "";
            } else if (alphabat == "four") {
                answerStr += '4';
                alphabat = "";
            } else if (alphabat == "five") {
                answerStr += '5';
                alphabat = "";
            } else if (alphabat == "six") {
                answerStr += '6';
                alphabat = "";
            } else if (alphabat == "seven") {
                answerStr += '7';
                alphabat = "";
            } else if (alphabat == "eight") {
                answerStr += '8';
                alphabat = "";
            } else if (alphabat == "nine") {
                answerStr += '9';
                alphabat = "";
            } else if (alphabat == "zero") {
                answerStr += '10';
                alphabat = "";
            }
        }
    }
    
    return stoi(answerStr);
}