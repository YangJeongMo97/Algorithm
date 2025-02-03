#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int S = brown + yellow;
    
    for(int w = S - 1; w > 0; w--)
    {
        if(S % w != 0) continue;
        
        int h = S / w;
        int y = (w - 2) * (h - 2);
        int b = S - y;
        
        if(y == yellow && b == brown)
        {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    return answer;
}