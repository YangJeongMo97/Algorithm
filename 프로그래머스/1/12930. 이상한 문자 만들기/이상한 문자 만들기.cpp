#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isEven = true;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            answer += ' ';
            isEven = true;
            continue;
        }
        if(isEven)
        {
            answer += toupper(s[i]);
            isEven = false;
        }
        else
        {
            answer += tolower(s[i]);
            isEven = true;
        }
    }
    
    return answer;
}