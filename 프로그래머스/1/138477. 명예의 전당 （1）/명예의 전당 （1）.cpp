#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> HallOfFame;
    
    for(int i = 0; i < score.size(); i++)
    {
        if(HallOfFame.size() > 0)
        {
            if(HallOfFame.size() >= k)
            {
                if(score[i] > HallOfFame.back()) HallOfFame.pop_back();   
                else
                {
                    answer.push_back(HallOfFame.back());
                    continue;
                }
            }
            HallOfFame.push_back(score[i]);
            sort(HallOfFame.begin(), HallOfFame.end(), greater<>());
        }
        else
        {
            HallOfFame.push_back(score[i]);
        }
        answer.push_back(HallOfFame.back());
    }
    
    return answer;
}