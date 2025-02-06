#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> result;
    
    for(int i = 0; i < elements.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < i + elements.size(); j++)
        {
            int idx = j % elements.size();
            sum += elements[idx];
            result.insert(sum);
        }
    }
    
    return result.size();
}