#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> order_list;
    int order = 0;
    int prev = (int)ceil((100 - progresses[0]) / (float)speeds[0]);
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int current = (int)ceil((100 - progresses[i]) / (float)speeds[i]);
        if(current > prev)
        {
            order++;
            prev = current;
        }
        
        order_list.push_back(order);
    }
    
    for(int i = 0; i <= order; i++)
    {
        answer.push_back(count(order_list.begin(), order_list.end(), i));
    }
    
    
    
    return answer;
}