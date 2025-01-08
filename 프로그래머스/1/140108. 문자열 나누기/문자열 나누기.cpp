#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, count_same = 0, count_diff = 0;
    
    while(!s.empty())
    {
        char first = s[0];
        for(int i = 0; i < s.length(); i++)
        {
            if(first == s[i]) count_same++;
            else count_diff++;
        
            if(count_same == count_diff) break;
        }
    
        s = s.substr(count_same + count_diff, s.length() - 1);
        answer++;
        count_same = 0;
        count_diff = 0;
    }
    
    return answer;
}