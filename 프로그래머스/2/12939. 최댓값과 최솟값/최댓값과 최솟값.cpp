#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    int number;
    
    istringstream iss(s);
    
    while(iss >> number)
    {
        numbers.push_back(number);
    }
    
    sort(numbers.begin(), numbers.end());
    
    answer = to_string(numbers[0]) + " " + to_string(numbers[numbers.size() - 1]);
    
    return answer;
}