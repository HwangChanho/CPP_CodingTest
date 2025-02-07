#include <string>
#include <vector>

#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> burgerStack;
    
    // 1 = 빵, 2 = 야채, 3 = 고기, 1231 (ingredient 에서 재료를 제거해줘야함)
    
    for (int i = 0; i < ingredient.size(); i++)
    {
        burgerStack.push_back(ingredient[i]);
        
        if (burgerStack.size() >= 4)
        {
            if (burgerStack[burgerStack.size() - 4] == 1 && 
                burgerStack[burgerStack.size() - 3] == 2 && 
                burgerStack[burgerStack.size() - 2] == 3 && 
                burgerStack[burgerStack.size() - 1] == 1)
            {
                answer++;
                
                //ingredient.erase(ingredient.begin() + i, ingredient.begin() + i + 4);
                
                burgerStack.pop_back();
                burgerStack.pop_back();
                burgerStack.pop_back();
                burgerStack.pop_back();
                
            }
            //burgerStack.erase(burgerStack.begin());
        }
    }
    
    return answer;
}