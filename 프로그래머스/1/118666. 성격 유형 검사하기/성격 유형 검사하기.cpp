#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int size = choices.size();
    int RT = 0, CF = 0, JM = 0, AN = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(survey[i] == "RT") RT += choices[i] - 4;
        else if(survey[i] == "TR") RT -= choices[i] - 4;
        
        if(survey[i] == "CF") CF += choices[i] - 4;
        else if(survey[i] == "FC") CF -= choices[i] - 4;
        
        if(survey[i] == "JM") JM += choices[i] - 4;
        else if(survey[i] == "MJ") JM -= choices[i] - 4;
        
        if(survey[i] == "AN") AN += choices[i] - 4;
        else if(survey[i] == "NA") AN -= choices[i] - 4;
    }
    
    if(RT <= 0) answer += 'R';
    else answer += 'T';
    
    if(CF <= 0) answer += 'C';
    else answer += 'F';
    
    if(JM <= 0) answer += 'J';
    else answer += 'M';
    
    if(AN <= 0) answer += 'A';
    else answer += 'N';
    
    return answer;
}