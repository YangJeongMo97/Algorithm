#include <string>
#include <vector>

using namespace std;

int temp[3];
int answer = 0;

void findTrio(vector<int> number, int idx, int size)
{
    if(size == 3)
    {
        int sum = 0;
        for(int i : temp)
        {
            sum += number[i];
        }
        if(sum == 0) answer++;
    }
    else
    {
        for(int i = idx; i < number.size(); i++)
        {
            temp[size] = i;
            findTrio(number, i + 1, size + 1);
        }
    }
}

int solution(vector<int> number) {
    
    findTrio(number, 0, 0);
    
    return answer;
}