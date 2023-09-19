#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
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
const int MAX = 1001;
int graph[MAX][MAX];
int dist[MAX][MAX];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>>q;

void bfs(){

    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx < 0 || nx >=n | ny < 0 || ny >= m || graph[nx][ny] == 0 || dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[cur_x][cur_y] + 1;    
            q.push({nx,ny});
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dist[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 0)
                cout << 0 <<" ";
            else
                cout << dist[i][j] <<" ";
        }
        cout << "\n";
    }

    return 0;
}