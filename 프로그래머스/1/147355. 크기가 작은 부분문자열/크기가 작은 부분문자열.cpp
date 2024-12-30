#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    unsigned long long pn = stoull(p);
    
    for(int i = 0; i < t.length() - p.length() + 1; i++)
    {
        string temp;
        
        for(int j = i; j < i + p.length(); j++)
        {
            temp += t[j];
        }
        
        unsigned long long a;
        
        a = stoull(temp);
        
        if(a <= pn) answer++;
    }
    
    return answer;
}