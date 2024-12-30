#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int min_h = 0, min_w = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];
        
        if(w < h)
        {
            int temp = w;
            w = h;
            h = temp;
        }
        
        if(min_w < w) min_w = w;
        if(min_h < h) min_h = h;
    }
    
    return min_w * min_h;
}