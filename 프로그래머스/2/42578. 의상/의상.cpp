#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> type;
    
    for(auto it : clothes)
    {
        type[it[1]]++;
    }
    
    for(auto it : type)
    {
        answer *= it.second + 1;
    }
    
    return answer - 1;
}