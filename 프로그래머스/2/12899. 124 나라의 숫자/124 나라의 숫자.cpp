#include <string>
#include <vector>

using namespace std;

vector<string> v = {"1", "2", "4"};
string answer = "";

string change124(int n)
{
    if(n / 3 >= 1)
    {
        answer += change124(n / 3 - 1);
    }
    
    return v[n % 3];
}

string solution(int n) {
    answer += change124(n - 1);
    
    return answer;
}