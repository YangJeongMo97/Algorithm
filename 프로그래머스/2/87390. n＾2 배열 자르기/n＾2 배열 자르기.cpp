#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int num = left / n + 1;
    int idx = left % n + 1;
        
    for(long long i = 1; i <= right - left + 1; i++)
    {
        if(idx <= num) answer.push_back(num);
        else answer.push_back(idx);
        
        if(++idx > n)
        {
            idx = 1;
            ++num;
        }
    }
    
    return answer;
}