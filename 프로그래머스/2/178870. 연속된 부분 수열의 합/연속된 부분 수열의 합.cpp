#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, -1);
    int left = 0, right = 0, sum = sequence[0];
    int min_length = 1000000;
    
    while(right < sequence.size())
    {
        if(sum == k)
        {
            if(right - left < min_length)
            {
                min_length = right - left;
                answer[0] = left;
                answer[1] = right;
            }
            sum -= sequence[left];
            left++;
        }
        else if(sum < k)
        {
            right++;
            if(right < sequence.size()) sum += sequence[right];
        }
        else
        {
            sum -= sequence[left];
            left++;
        }
    }
    
    return answer;
}