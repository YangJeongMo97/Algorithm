#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++)
    {
        s.push_back(s[0]);
        s.erase(0, 1);
        
        vector<char> v;
        for(char c : s)
        {
            if(v.empty()) v.push_back(c);
            else
            {
                if(v.back() == '{' && c == '}') v.pop_back();
                else if(v.back() == '[' && c == ']') v.pop_back();
                else if(v.back() == '(' && c == ')') v.pop_back();
                else v.push_back(c);
            }
        }
        
        if(v.empty()) answer++;
    }
    
    return answer;
}