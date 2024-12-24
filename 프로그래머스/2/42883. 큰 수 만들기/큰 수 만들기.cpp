#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    vector<char> storage;
    
    for(char& current : number)
    {
        while(!storage.empty() && storage.back() < current && k > 0)
        {
            storage.pop_back();
            k--;
        }
        storage.push_back(current);
    }
    
    while(k > 0)
    {
        storage.pop_back();
        k--;
    }
    
    for(char& c : storage)
    {
        answer.append(1, c);
    }
    
    return answer;
}