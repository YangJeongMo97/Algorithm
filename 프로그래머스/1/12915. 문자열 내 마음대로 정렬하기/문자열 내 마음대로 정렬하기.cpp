#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int num;

bool stringSort(string a, string b)
{
    if(a[num] == b[num])
    {
        return a < b;
    }
    return a[num] < b[num];
}

vector<string> solution(vector<string> strings, int n) {
    num = n;
    
    sort(strings.begin(), strings.end(), stringSort);
    
    return strings;
}