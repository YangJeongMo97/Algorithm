#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<string>> report_list;
unordered_map<string, int> reported_count;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i = 0; i < id_list.size(); i++)
    {
        reported_count[id_list[i]] = 0;
        answer.push_back(0);
    }
    
    for(int i = 0; i < report.size(); i++)
    {
        size_t space_pos = report[i].find(' ');
        string first, second;
        if (space_pos != string::npos) {
            first = report[i].substr(0, space_pos);
            second = report[i].substr(space_pos + 1);
            
            if(find(report_list[first].begin(), report_list[first].end(), second) == report_list[first].end())
            {
                report_list[first].push_back(second);
                reported_count[second]++;
            }
        }
    }
    
    for(auto it : report_list)
    {
        int idx = distance(id_list.begin(), find(id_list.begin(), id_list.end(), it.first));
        for(int i = 0; i < it.second.size(); i++)
        {
            if(reported_count[it.second[i]] >= k)
            {
                answer[idx]++;
            }
        }
    }
    
    return answer;
}