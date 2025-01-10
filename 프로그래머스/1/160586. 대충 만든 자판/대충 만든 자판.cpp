#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> um;
    
    for(int i = 0; i < keymap.size(); i++)
    {
        for(int j = 0; j < keymap[i].length(); j++)
        {
            char cur_key = keymap[i][j];
            if(um.find(cur_key) != um.end())
            {
                if(um[cur_key] > j) um[cur_key] = j + 1;
            }
            else um[cur_key] = j + 1;
        }
    }
    
    for(string target : targets)
    {
        int tot_val = 0;
        for(char c : target)
        {
            if(um.find(c) != um.end()) tot_val += um[c];
            else
            {
                tot_val = -1;
                break;
            }
        }
        answer.push_back(tot_val);
    }
    
    return answer;
}