#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0;

    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) {
        int current = q.front().first;
        int operations = q.front().second;
        q.pop();

        int nextValues[3] = {current + n, current * 2, current * 3};

        for (int next : nextValues) {
            if (next == y) return operations + 1;

            if (next <= y * 2 && visited.find(next) == visited.end()) {
                q.push({next, operations + 1});
                visited.insert(next);
            }
        }
    }

    return -1;
}