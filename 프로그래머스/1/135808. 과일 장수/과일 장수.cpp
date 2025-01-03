#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, max_idx = score.size() - 1;
    
    sort(score.begin(), score.end());
    
    while(score.size() / m > 0){
        answer += score[max_idx - m + 1] * m;
        score.resize(score.size() - m);
        max_idx = score.size() - 1;
    }
    
    return answer;
}