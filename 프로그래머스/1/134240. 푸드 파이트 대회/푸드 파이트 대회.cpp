#include <string>
#include <vector>

using namespace std;
string reverseString(const string &str) {
    string temp;
    for (int i = str.length() - 1; i >= 0; --i) {
        temp += str[i];
    }
    return temp;
}

string solution(vector<int> food) {
    string answer = "";
    string answerT = "";

    // 1번 음식부터 마지막 음식까지 순회
    for (int i = 1; i < food.size(); i++) {
        int count = food[i] / 2; // 절반만 사용
        for (int j = 0; j < count; j++) {
            answerT += to_string(i); // 숫자를 문자로 변환
        }
    }

    answer = answerT;         // 정방향 음식 추가
    answer += '0';            // 중앙의 물 추가
    answer += reverseString(answerT); // 뒤집은 음식 추가

    return answer;
}