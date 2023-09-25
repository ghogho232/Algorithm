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

const int MAX = 601;
char graph[MAX][MAX];
int visited[MAX][MAX] = {0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
int cnt = 0;

void dfs(int x, int y) {
    visited[x][y] = 1;
    if (graph[x][y] == 'P') {
        cnt++;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == 'X' || visited[nx][ny]) {
            continue;
        }
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cx = 0, cy = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'I') {
                cx = i;
                cy = j;
            }    
        }
    }

    dfs(cx, cy);
    if (cnt == 0) {
        cout << "TT";
    } else {
        cout << cnt;
    }
    return 0;
}