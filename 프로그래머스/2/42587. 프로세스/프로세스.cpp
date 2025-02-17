#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, count = 1;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++)
    {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(1)
    {
        auto current = q.front();
        q.pop();
        
        if(current.second < pq.top())
        {
            q.push(current);
        }
        else if(current.first != location && current.second >= pq.top())
        {
            pq.pop();
            count++;
        }
        else
        {
            answer = count;
            break;
        }
    }
    
    return answer;
}