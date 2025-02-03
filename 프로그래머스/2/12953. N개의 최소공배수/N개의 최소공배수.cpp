#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    int x = max(a, b);
    int y = min(a, b);
    
    while(x % y != 0)
    {
        int result = x % y;
        x = y;
        y = result;
    }
    
    return y;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
    {
        int gcd = GCD(answer, arr[i]);
        int lcm = answer * arr[i] / gcd;
        answer = lcm;
    }
    
    return answer;
}