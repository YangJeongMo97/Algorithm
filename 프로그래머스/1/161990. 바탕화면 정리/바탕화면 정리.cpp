#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int min_x = wallpaper[0].length(), min_y = wallpaper.size(), max_x = 0, max_y = 0;
    
    
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].length(); j++)
        {
            if(wallpaper[i][j] != '#') continue;
            min_y = min(min_y, i);
            max_y = max(max_y, i + 1);
            min_x = min(min_x, j);
            max_x = max(max_x, j + 1);
        }
    }
    
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y);
    answer.push_back(max_x);
    
    return answer;
}