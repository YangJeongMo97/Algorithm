#include <string>
#include <vector>

using namespace std;

pair<int, int> current;
int height, width;

void Step(vector<string> park, char direction, int n)
{
    if(direction == 'N')
    {
        for(int i = 1; i <= n; i++)
        {
            if(current.first - i < 0 || park[current.first - i][current.second] == 'X') return;
        }
        current.first -= n;
    }
    else if(direction == 'E')
    {
        for(int i = 1; i <= n; i++)
        {
            if(current.second + i >= width || park[current.first][current.second + i] == 'X') return;
        }
        current.second += n;
    }
    else if(direction == 'S')
    {
        for(int i = 1; i <= n; i++)
        {
            if(current.first + i >= height || park[current.first + i][current.second] == 'X') return;
        }
        current.first += n;
    }
    else if(direction == 'W')
    {
        for(int i = 1; i <= n; i++)
        {
            if(current.second - i < 0 || park[current.first][current.second - i] == 'X') return;
        }
        current.second -= n;
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    height = park.size();
    width = park[0].size();
    
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(park[i][j] == 'S') current = {i, j};
        }
    }
    
    for(int i = 0; i < routes.size(); i++)
    {
        Step(park, routes[i][0], routes[i][2] - '0');
    }
    
    answer.push_back(current.first);
    answer.push_back(current.second);
    
    return answer;
}