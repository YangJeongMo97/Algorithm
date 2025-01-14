#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack = {0};
    
    for(int i : ingredient)
    {   
        if(stack.back() == 1 && i == 2) stack.back() = 12;
        else if(stack.back() == 12 && i == 3) stack.back() = 123;
        else if(stack.back() == 123 && i == 1){answer++; stack.pop_back();}
        else stack.push_back(i);
    }
    
    return answer;
}