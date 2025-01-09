#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int size = tangerine.size();
    unordered_map<int, int> um;
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        um[tangerine[i]]++;
    }
    
    vector<pair<int, int>> vp(um.begin(), um.end());
    
    sort(vp.begin(), vp.end(), cmp);
    
    answer = vp.size();
    
    for(int i = 0; i < size - k; i++)
    {
        if(--vp[0].second <= 0)
        {
            vp.erase(vp.begin());
            answer--;
        }
    }
    
    return answer;
}