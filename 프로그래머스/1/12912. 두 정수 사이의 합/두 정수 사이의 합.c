#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a, int b) {
    long long answer = 0;
    int min = (a < b) ? a : b;
    int max = (a >= b) ? a : b;
    
    for(int i = min; i <= max; i++)
    {
        answer += i;
    }
    
    return answer;
}