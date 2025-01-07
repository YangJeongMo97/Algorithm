#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ranking = {1, 2, 3, 4, 5, 6, 6};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count = 0, zero_count = 0;
    
    for(int i = 0; i < lottos.size(); i++)
    {
        if(lottos[i] == 0)
        {
            zero_count++;
            continue;
        }
        if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end()) count++;
    }
    
    answer.push_back(ranking[6 - (count + zero_count)]);
    answer.push_back(ranking[6 - count]);
    
    return answer;
}