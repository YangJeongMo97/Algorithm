#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int* answer = (int*)malloc(sizeof(int) * 11);
    
    for(int i = 0; n != 0; n /= 10)
    {
        answer[i++] = n % 10;
    }
    
    return answer;
}