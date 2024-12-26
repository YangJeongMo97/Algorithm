#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int TimeToInt(string inString)  //시간 표시를 숫자로 치환
{
    char separator = ':';   // ':'를 기준으로 앞 뒤 숫자 추출
    istringstream iss(inString);
    string s_buf;
    bool isMinutes = false; //시와 분을 구분
    int result = 0;
    while(getline(iss, s_buf, separator))
    {
        if(!isMinutes)  //시 표시일 때
        {
            result += stoi(s_buf) * 60;
            isMinutes = true;
        }
        else    //분 표시일 때
        {
            result += stoi(s_buf);
        }
    }
    
    //전부 더해서 분 값으로 변경
    return result;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<int> reservate;
    
    sort(book_time.begin(), book_time.end());   //시간순으로 정렬
    
    for(int i = 0; i < book_time.size(); i++)
    {
        int start = TimeToInt(book_time[i][0]); //각 예약 별 시작 시간
        int end = TimeToInt(book_time[i][1]) + 10;  //예약 종료 시간
        int most_close = 1500, idx; //가장 빠른 퇴실 시간 탐색을 위한 변수
        
        for(int j = 0; j < reservate.size(); j++)
        {
            if(most_close > reservate[j])
            {
                most_close = reservate[j];
                idx = j;
            }
        }
        
        if(most_close <= start)     //가장 빠른 퇴실 시간이 이미 지나 빈 방이라면
        {
            reservate.erase(reservate.begin() + idx);   //요소를 지우고
        }
        reservate.push_back(end);   //새로운 방 추가
    }
    
    answer = reservate.size();
    
    return answer;
}
