#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> name_rank;
    unordered_map<int, string> rank_name;
    
    for(int i = 0; i < players.size(); i++)
    {
        name_rank[players[i]] = i;
        rank_name[i] = players[i];
    }
    
    for(int i = 0; i < callings.size(); i++)
    {
        int front_rank = name_rank[callings[i]] - 1;
        string front_name = rank_name[front_rank];
        
        name_rank[callings[i]]--;
        name_rank[front_name]++;
        
        rank_name[front_rank] = callings[i];
        rank_name[front_rank + 1] = front_name;
    }
    
    vector<pair<string, int>> vec(name_rank.begin(), name_rank.end());
    sort(vec.begin(), vec.end(), cmp);
    
    for(auto it : vec)
    {
        answer.push_back(it.first);
    }
    
    return answer;
}