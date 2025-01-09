#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int size = tangerine.size(), idx = 0;
    unordered_map<int, int> um;     // 크기 별 귤의 개수를 저장하기 위한 자료형
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        um[tangerine[i]]++;
    }
    
    vector<pair<int, int>> vp(um.begin(), um.end());    // 정렬을 위한 자료형
    
    sort(vp.begin(), vp.end(), cmp);    // 개수를 기준으로 오름차순 정렬
    
    answer = vp.size();     // 크기가 서로 다른 모든 종류의 수
    
    for(int i = 0; i < size - k; i++)
    {
        if(--vp[idx].second <= 0)     // 해당 크기의 귤을 모두 제외했을 때
        {
            idx++;
            answer--;      // 해당 크기 제거
        }
    }
    
    return answer;
}
