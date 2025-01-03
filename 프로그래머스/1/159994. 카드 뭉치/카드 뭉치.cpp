#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    bool isPossible = true;
    int card1_idx = 0, card2_idx = 0;
    
    for(int i = 0; i < goal.size(); i++)
    {
        if(goal[i] == cards1[card1_idx]) card1_idx++;
        else if(goal[i] == cards2[card2_idx]) card2_idx++;
        else
        {
            isPossible = false;
            break;
        }
    }
    
    if(isPossible) return "Yes";
    else return "No";
}