#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int current = 0;
    
    for(int i = 0; i < n; i++)
    {
        current += x;
        answer.push_back(current);
    }
    
    return answer;
}