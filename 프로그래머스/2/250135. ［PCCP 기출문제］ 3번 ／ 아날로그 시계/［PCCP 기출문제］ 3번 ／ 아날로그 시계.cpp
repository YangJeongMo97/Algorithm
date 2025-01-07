#include <string>
#include <vector>

using namespace std;

vector<float> currentDegree;
vector<float> nextDegree;

vector<float> getDegree(int time)
{
    int h = time / 3600;
    int m = (time % 3600) / 60;
    int s = (time % 3600) % 60;
    
    float h_degree = (s * (1 / 120.0)) + (m * 0.5) + ((h % 12) * 30.0);
    float m_degree = (s * 0.1) + (m * 6.0);
    float s_degree = s * 6.0;
    
    return vector<float> {h_degree, m_degree, s_degree};
}

bool checkHourCondition()
{    
    if(currentDegree[2] == 354 && currentDegree[0] > 354) return true;
        
    if(currentDegree[0] > currentDegree[2] && nextDegree[0] <= nextDegree[2]) return true;
    
    return false;
}

bool checkMinuteCondition()
{
    if(currentDegree[2] == 354 && currentDegree[1] > 354) return true;
        
    if(currentDegree[1] > currentDegree[2] && nextDegree[1] <= nextDegree[2]) return true;
    
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int total_h1 = h1 * 3600 + m1 * 60 + s1;
    int total_h2 = h2 * 3600 + m2 * 60 + s2;
    
    if(total_h1 == 0 || total_h1 == 43200) answer++;
    
    for(int i = total_h1; i < total_h2; i++)
    {
        currentDegree = getDegree(i);
        nextDegree = getDegree(i + 1);
        
        bool hCondition = checkHourCondition();
        bool mCondition = checkMinuteCondition();
        
        if(hCondition && mCondition)
        {
            if(nextDegree[0] == nextDegree[1]) answer++;
            else answer += 2;
        }
        
        else if(hCondition || mCondition) answer++;
    }
    
    return answer;
}