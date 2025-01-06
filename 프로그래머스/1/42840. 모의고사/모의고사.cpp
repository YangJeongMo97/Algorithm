#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> first = {1, 2, 3, 4, 5};
vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    unordered_map<int, int> um;
    int index = 0, size1 = first.size(), size2 = second.size(), size3 = third.size();
    
    for(int a : answers){
        if(a == first[index % size1]) um[1]++;
        if(a == second[index % size2]) um[2]++;
        if(a == third[index % size3]) um[3]++;
        index++;
    }
    
    vector<pair<int, int>> v(um.begin(), um.end());
    
    sort(v.begin(), v.end(), cmp);
    
    int max_value = v[0].second;
    
    for(auto i : v){
        if(i.second < max_value) break;
        answer.push_back(i.first);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}