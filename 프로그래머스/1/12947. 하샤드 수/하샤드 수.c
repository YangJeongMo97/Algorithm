#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int sum = 0, n = x;
    
    while(n != 0)
    {
        sum += n % 10;
        n /= 10;
    }
    
    if(x % sum != 0) answer = false;
    
    return answer;
}