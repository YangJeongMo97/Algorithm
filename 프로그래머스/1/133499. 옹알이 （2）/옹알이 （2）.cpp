#include <string>
#include <vector>

using namespace std;

vector<string> word = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i = 0; i < babbling.size(); i++)
    {
        string prev = "";
        for(int j = 0; j < word.size(); j++)
        {
            if(prev != word[j] && babbling[i].substr(0, word[j].length()) == word[j])
            {
                babbling[i] = babbling[i].substr(word[j].length(), babbling[i].length() - 1);
                prev = word[j];
                j = -1;
            }
        }
        
        if(babbling[i].empty()) answer++;
    }
    
    return answer;
}