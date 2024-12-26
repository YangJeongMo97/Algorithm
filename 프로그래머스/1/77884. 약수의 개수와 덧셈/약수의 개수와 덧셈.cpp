#include <string>
#include <vector>

using namespace std;

int factor_count(int num)
{
    int result = 0;
    
    for(int i = 1; i <= num / 2; i++)
    {
        if(num % i == 0) result++;
    }
    
    return result + 1;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++)
    {
        if(factor_count(i) % 2 == 0) answer += i;
        else answer -= i;
    }
    
    return answer;
}