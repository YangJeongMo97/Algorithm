#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool cmp(char a, char b)
{
    return b < a;
}

string solution(string X, string Y) {
    string answer = "";
    unordered_map<char, int> X_um, Y_um;

    for (int i = 0; i < X.length(); i++)
    {
        X_um[X[i]]++;
    }

    for (int i = 0; i < Y.length(); i++)
    {
        Y_um[Y[i]]++;
    }

    for (auto it : X_um)
    {
        char c = it.first;
        if (Y_um.count(c) > 0)
        {
            int size = (it.second < Y_um[c]) ? it.second : Y_um[c];
            for (int i = 0; i < size; i++)
            {
                answer += c;
            }
        }
    }

    bool isAllZero = true;
    for (int i = 0; i < answer.length(); i++)
    {
        if (answer[i] != '0') isAllZero = false;
    }

    if (answer.empty()) return "-1";
    if (isAllZero) return "0";

    sort(answer.begin(), answer.end(), cmp);

    return answer;
}