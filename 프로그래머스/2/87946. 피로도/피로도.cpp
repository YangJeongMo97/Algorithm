#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    vector<int> v;
    pair<int, int> p[9];
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        p[i + 1] = {dungeons[i][0], dungeons[i][1]};
        v.push_back(i + 1);
    }
    
    do
    {
        int temp = k;
        int cnt = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(temp >= p[v[i]].first)
            {
                temp -= p[v[i]].second;
                cnt++;
            }
        }
        
        answer = max(answer, cnt);
        
    }while(next_permutation(v.begin(), v.end()));
    
    
    return answer;
}