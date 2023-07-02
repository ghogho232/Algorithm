#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

int map[26][26];
int visited[26][26] = { 0 };
int cnt = 0;
int acnt = 0;
vector<int> v;
int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int x, int y) {
    visited[x][y] = 1;
    acnt++;
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || map[nx][ny] != map[x][y])
            continue;
        dfs(nx, ny);
    }
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]&&map[i][j]) {
                dfs(i, j);
                cnt++;
                v.push_back(acnt);
                acnt = 0;
            }
        }
    }
    sort(v.begin(), v.end());


    cout << cnt <<"\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
}