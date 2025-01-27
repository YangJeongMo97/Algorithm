#include <string>
#include <vector>

using namespace std;

vector<int> F = {0, 1};

void Fibonacci(int n)
{
    if(n > 2) Fibonacci(n - 1);
    F.push_back((F[n - 1] + F[n - 2]) % 1234567);
}

int solution(int n) {
    Fibonacci(n);
    return F.back();
}