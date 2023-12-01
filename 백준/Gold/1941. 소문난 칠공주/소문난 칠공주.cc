#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;
char graph[5][5];
int visited[5][5];
int cur[5][5];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
bool pick[25];
int ans = 0;

bool four(){
    int s_cnt = 0;
    for(int i = 0; i < 25; i++){
        if(pick[i] && graph[i/5][i%5] == 'S')
            s_cnt++;
    }
    return s_cnt >= 4;
}

bool bfs(){
    memset(visited,0,sizeof(visited));
    memset(cur,0,sizeof(cur));
    queue<pair<int,int>>q;
    bool flag = true;
    for(int i = 0; i < 25; i++){
        if(pick[i]){
            cur[i/5][i%5] = 1;
            if(flag){
                flag = false;
                q.push({i/5,i%5});
                visited[i/5][i%5] = 1;
            }
        }
    }
    int cnt = 1;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();        
        if(cnt == 7)
            return true;
        for(int i = 0; i < 4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || visited[nx][ny] || !cur[nx][ny])
                continue;
            q.push({nx,ny});
            visited[nx][ny] = 1;
            cnt++;
        }

    }
    return false;
}
void dfs(int depth, int cnt){
    if(cnt == 7){
        if(four() && bfs()){
            ans++;
            return;
        }
    }
    for(int i = depth; i < 25; i++){
        if(!pick[i]){
            pick[i] = 1;
            dfs(i,cnt+1);
            pick[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> graph[i][j];
        }
    }
    dfs(0,0);
    cout << ans;
    return 0;
}