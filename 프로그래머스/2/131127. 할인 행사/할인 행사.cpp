#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0, count = 0;
    map<string, int> m1;
    
    for(int i = 0; i < want.size(); i++)
    {
        m1[want[i]] = number[i];
    }
    
    while(count <= discount.size() - 10)
    {
        map<string, int> m2;
        
        for(int i = count; i < 10 + count; i++)
        {
            m2[discount[i]]++;
        }
    
        if(m1 == m2)
        {
            answer++;
        }
        
        count++;
    }
    
    return answer;
}