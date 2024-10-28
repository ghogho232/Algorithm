#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[201];

void dfs(int n, int cur, vector<vector<int>>computers){
    visited[cur] = 1;
    
    for(int i = 0; i < n; i++){
        if(!visited[i] && computers[cur][i]){
            dfs(n, i, computers);
            
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(n, i, computers);
            answer++;
        }
    }
    return answer;
}