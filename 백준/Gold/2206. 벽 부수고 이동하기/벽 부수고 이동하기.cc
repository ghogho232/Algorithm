#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
int graph[MAX][MAX] = {0};
int visited[MAX][MAX][2] = {0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n,m;
queue<pair<pair<int, int>,int>> q;

int bfs(){
    q.push({{1,1},1});
    visited[1][1][1] = 1;

    while(!q.empty()){
      int x = q.front().first.second;
      int y = q.front().first.first;
      int blc = q.front().second;
      q.pop();

      if(x == m && y == n)
          return visited[y][x][blc];

      for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny < 1 || ny > n || nx < 1 || nx > m)
            continue;
        if(graph[ny][nx] && blc){
            visited[ny][nx][blc - 1] = visited[y][x][blc] + 1;
            q.push({{ny, nx}, blc - 1});
        }
        if(!graph[ny][nx] && !visited[ny][nx][blc]){
          visited[ny][nx][blc] = visited[y][x][blc] + 1;
          q.push({{ny,nx},blc});
        }
      }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
      string str;
      cin >> str;
      for(int j = 1; j <= m; j++){
        graph[i][j] = str[j-1] - '0';
      }
    }
    cout << bfs();
    return 0;
}