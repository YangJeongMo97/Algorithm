#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i = 0; i < s.length(); i++)
    {
        int idx = 0;
        char final;
        for(int j = 0; j < index; j++)
        {
            idx++;
            if(skip.find((s[i] + idx - 'a') % 26 + 'a') != string::npos)
            {
                j--;
                continue;
            }
            final = (s[i] + idx - 'a') % 26 + 'a';
        }
        answer += final;
        idx = 0;
    }
    
    return answer;
}