#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> dictionary;
char vowels[5] = { 'A', 'E', 'I', 'O', 'U' };

void generate(string word) {
  if (word.length() > 5) return;

  dictionary.push_back(word);

  for (int i = 0; i < 5; i++) {
    generate(word + vowels[i]);
  }
}

int solution(string word) {
    generate("");
    return find(dictionary.begin(), dictionary.end(), word) - dictionary.begin();
}