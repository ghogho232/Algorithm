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
#define MAX INT_MAX
#define MOD 1000000003
using namespace std;

int n,m;
int graph[501][501];
int visited[501][501];
int dx[4]={-1,0,1,0};
int dy[4] = {0,-1,0,1};
int ans = 0;
int o[4][4][2]={
    {{1, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}
};

int odfs(int x, int y){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int tmp = 0;
        for(int j = 0; j < 4; j++){
            int nx = x + o[i][j][0];
            int ny = y + o[i][j][1];
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                tmp=0;
                break;
            }
            else 
                tmp+=graph[nx][ny];
        }
        ret = max(ret,tmp);
    }
    return ret;
}
void dfs(int x, int y, int depth, int sum){
    if(depth == 3){
        ans = max(ans,sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m||visited[nx][ny])
            continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, depth+1, sum+graph[nx][ny]);
        visited[nx][ny] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 1;
            dfs(i,j,0,graph[i][j]);
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans,odfs(i,j));
        }
    }
    cout << ans;
    return 0;
}