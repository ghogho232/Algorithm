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

int r, c;
char graph[21][21];
int visited[26];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = 0;

void dfs(int x, int y, int cnt){
    bool flag = false;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || visited[graph[nx][ny]-'A'])
            continue;
        flag = true;
        visited[graph[nx][ny]-'A'] = true;
        dfs(nx, ny, cnt + 1);
        visited[graph[nx][ny]-'A'] = false;
    }
    if(!flag){
        ans = max(ans, cnt);
        return;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> graph[i][j];
        }
    }
    visited[graph[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}