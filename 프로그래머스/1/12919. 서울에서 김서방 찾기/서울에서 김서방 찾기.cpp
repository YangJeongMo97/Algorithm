#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    auto idx = find(seoul.begin(), seoul.end(), "Kim");
    
    string s_idx = to_string(idx - seoul.begin());
    
    answer += s_idx + "에 있다";
    
    return answer;
}