#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i = 1; i <= r2; i++)
    {
        long long max_y = floor(sqrt((long long)pow(r2, 2) - (long long)(pow(i, 2))));
        long long min_y = (r1 > i)? ceil(sqrt((long long)pow(r1, 2) - (long long)(pow(i, 2)))) : 0;
        
        answer += (max_y - min_y + 1);
    }
    
    return answer * 4;
}