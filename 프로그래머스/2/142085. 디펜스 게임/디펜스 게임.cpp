#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int size = enemy.size();
    priority_queue<int> pq;     // 진행된 라운드 중 유닛이 가장 많은 라운드를 추출하기 위한 자료형

    int used = 0, pow = 0, idx = 0; // 사용된 병사 수, 무적권 잔여량, 진행 중 라운드
    
    if(k >= size) return size;  // 소모값 없이 모든 라운드 종료 가능 할 경우
    
    while(1)
    {
        if(idx == size) break;  // 모든 라운드를 진행했을 때
        
        used += enemy[idx];     // 사용된 병사 추가
        pq.push(enemy[idx]);    // 진행된 라운드 적군 수 큐에 추가
        
        if(used <= n)       // 사용 가능 한 병사가 남았을 경우
        {
            answer++;
        }
        else                // 사용 가능한 병사가 남지 않은 경우 || 병사가 초과되었을 때
        {
            if(k == 0) return answer;
            pow = pq.top(); // 진행했던 라운드 중 가장 개체수가 많은 라운드에 무적권 사용
            pq.pop();
            
            used -= pow;    // 사용된 병사수 감소
            k--;            // 무적권 감소
            answer++;
        }
        idx++;              // 다음 라운드 탐색
    }
    
    return answer;
}
