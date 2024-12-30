#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> en_num = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    string answer = "", temp = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9') answer += s[i];
        else temp += s[i];
        if(find(en_num.begin(), en_num.end(), temp) != en_num.end())
        {
            answer += to_string(find(en_num.begin(), en_num.end(), temp) - en_num.begin());
            temp = "";
        }
    }
    
    return stoi(answer);
}