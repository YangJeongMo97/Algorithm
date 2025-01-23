#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;
    
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            answer += ' ';
            isFirst = true;
        }
        else if(s[i] >= 'a' && s[i] <= 'z' && isFirst)
        {
            answer += s[i] - 32;
            isFirst = false;
        }
        else
        {
            answer += s[i];
            isFirst = false;
        }
    }
    
    
    return answer;
}