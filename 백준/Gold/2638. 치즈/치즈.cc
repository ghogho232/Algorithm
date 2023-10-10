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

int graph[101][101];
int air[101][101];
int visited[101][101];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny])
                continue;
            if (graph[nx][ny]){
                air[nx][ny]++;
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
}

bool melt() {
    bool isMelt = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] && air[i][j] >= 2) {
                graph[i][j] = 0;
                isMelt = true;
            }
        }
    }
    return isMelt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        memset(air, 0, sizeof(air));
        bfs();
        bool isMelt = melt();
        if (isMelt)
            cnt++;
        else
            break;
    }
    
    cout << cnt;
    return 0;
}