#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num1, int num2) {
    double result = (double)num1 / (double)num2 * 1000;
    int answer = (int)result;
    return answer;
}