#include <string>
#include <vector>

using namespace std;

vector<int> v = {0, 1, 2, 3};

long long solution(int n) {
    for(int i = 4; i <= n; i++)
    {
        v.push_back((v[i - 2] + v[i - 1]) % 1234567);
    }
    
    return v[n];
}