#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map <long long, long long> weights_map;
    vector<int> distances = { 2, 3, 4 };
    
    for(long long item : weights)
    {
        weights_map[item]++;
    }
    
    for(pair<long long, long long> p : weights_map)
    {
        long long weight = p.first;
        long long count = p.second;
        
        if(count > 1)
        {
            answer += count * (count - 1) / 2;
        }
        
        if(weight * 3 % 2 == 0)
            if(weights_map.find(weight * 3 / 2) != weights_map.end())
                answer += (weights_map[weight * 3 / 2] * count);
        
        if(weight * 4 % 2 == 0)
            if(weights_map.find(weight * 4 / 2) != weights_map.end())
                answer += (weights_map[weight * 4 / 2] * count);
        
        if(weight * 4 % 3 == 0)
            if(weights_map.find(weight * 4 / 3) != weights_map.end())
                answer += (weights_map[weight * 4 / 3] * count);
    }
    
    return answer;
}