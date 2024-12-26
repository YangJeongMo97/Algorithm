#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int TimeToInt(string inString)
{
    char separator = ':';
    istringstream iss(inString);
    string s_buf;
    bool isMinutes = false;
    int result = 0;
    while(getline(iss, s_buf, separator))
    {
        if(!isMinutes)
        {
            result += stoi(s_buf) * 60;
            isMinutes = true;
        }
        else
        {
            result += stoi(s_buf);
        }
    }
    
    return result;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> reservate;
    
    sort(book_time.begin(), book_time.end());
    
    for(int i = 0; i < book_time.size(); i++)
    {
        int start = TimeToInt(book_time[i][0]);
        int end = TimeToInt(book_time[i][1]) + 10;
        int most_close = 1500, idx;
        
        for(int j = 0; j < reservate.size(); j++)
        {
            if(most_close > reservate[j])
            {
                most_close = reservate[j];
                idx = j;
            }
        }
        
        if(most_close <= start)
        {
            reservate.erase(reservate.begin() + idx);
        }
        reservate.push_back(end);
    }
    
    answer = reservate.size();
    
    return answer;
}

