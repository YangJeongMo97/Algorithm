#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long levelStart = 1, levelEnd = limit;
    long long currentLevel = (levelStart + levelEnd) / 2;
    
    while(levelStart <= levelEnd)
    {
        long long time = times[0];
        for(int i = 1; i < diffs.size(); i++)
        {
            if(diffs[i] <= currentLevel) time += times[i];
            else{
                time += ((times[i - 1] + times[i]) * (diffs[i] - currentLevel)) + times[i];
            }
        }
        if(time > limit) levelStart = currentLevel + 1;
        else levelEnd = currentLevel - 1;
        currentLevel = (levelStart + levelEnd) / 2;
    }
    
    return currentLevel + 1;
}