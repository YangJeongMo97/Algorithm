#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> terms_um;
    int year, month, day, date;
    
    year = stoi(today.substr(0, 4));
    month = stoi(today.substr(5, 2));
    day = stoi(today.substr(8, 2));
    
    date = year * 12 * 28 + month * 28 + day;
    
    for(int i = 0; i < terms.size(); i++)
    {
        stringstream ss(terms[i]);
        char c;
        int m;
        ss >> c >> m;
        terms_um[c] = m;
    }
    
    for(int i = 0; i < privacies.size(); i++)
    {
        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));
        char c = privacies[i].back();
        
        int limit = y * 12 * 28 + m * 28 + d + terms_um[c] * 28;
        
        if(limit <= date) answer.push_back(i + 1);
    }
    
    return answer;
}