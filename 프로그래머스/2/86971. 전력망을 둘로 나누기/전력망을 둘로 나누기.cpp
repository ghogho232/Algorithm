#include <string>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

vector<vector<int>> arr(101);
int cnt = 0;

void bfs(int v1, int v2){
    cnt = 1;
    queue<int>q;
    vector<int>visited(101);
    q.push(v1);
    visited[v1] = 1;
    visited[v2] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < arr[cur].size(); i++){
            int newnode = arr[cur][i];
            if(visited[newnode]) continue;
            q.push(newnode);
            visited[newnode] = 1;
            cnt++;
        }
    }
    
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i = 0; i < wires.size(); i++){
        arr[wires[i][0]].push_back(wires[i][1]);
        arr[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 0; i < wires.size(); i++){
        auto wire = wires[i];
        int v1 = wire[0];
        int v2 = wire[1];
        bfs(v1, v2); // BFS 함수 호출
        answer = min(answer, abs(cnt - (n - cnt))); 
    }
    return answer;
}