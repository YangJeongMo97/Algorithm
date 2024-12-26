#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < min) min = arr[i];
    }
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(min != arr[i]) answer.push_back(arr[i]);
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}