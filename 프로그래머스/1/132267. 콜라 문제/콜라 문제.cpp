#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, remain = 0;
    
    while(n / a >= 1)
    {   
        remain = n % a;
        
        answer += (n / a) * b;
        
        n = remain + ((n / a) * b);
    }
    
    return answer;
}