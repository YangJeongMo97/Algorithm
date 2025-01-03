#include <string>
#include <vector>

using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    string answer = "";
    int currentDay = 0;
    
    for(int i = 1; i <= a; i++)
    {
        for(int j = 1; j <= month[i - 1]; j++)
        {
            if(currentDay >= 7) currentDay = 0;
            if(i == a && j == b) break;
            currentDay++;
        }
    }
    
    answer = day[currentDay];
    
    return answer;
}