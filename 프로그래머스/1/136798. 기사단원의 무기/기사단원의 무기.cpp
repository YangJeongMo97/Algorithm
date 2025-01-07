#include <string>
#include <vector>

using namespace std;

int weapon(int number)
{
    if(number == 1) return 1;
    
    int damage = 2;
    
    for(int i = 2; i <= number / 2; i++)
    {
        if(number % i == 0) damage++;
    }
    
    return damage;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++)
    {
        int result = weapon(i);
        if(result > limit) answer += power;
        else answer += result;
    }
    
    return answer;
}