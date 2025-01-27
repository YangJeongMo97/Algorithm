#include <string>
#include <vector>

using namespace std;

int count = 0, zero = 0;

void change(string s)
{
    if(s.length() <= 1) return;
    
    string temp;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '0') zero++;
        else temp += s[i];
    }
    
    int result = temp.length();
    
    temp = "";
    
    while(result > 0)
    {
        temp = to_string(result % 2) + temp;
        result /= 2;
    }
    
    count++;
    
    change(temp);
}

vector<int> solution(string s) {
    vector<int> answer;
    
    change(s);
    
    answer.push_back(count);
    answer.push_back(zero);
    
    return answer;
}