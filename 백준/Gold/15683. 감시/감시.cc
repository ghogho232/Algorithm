#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
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

int n, m;
int arr[9][9];

int ans = 987654321;

vector < pair<int, int>> cctv;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void record(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] == 6)
            return;
        if (arr[nx][ny] != 0)
            continue;
        arr[nx][ny] = -1;
    }
}
int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}
void dfs(int depth) {
    if (depth == cctv.size()) {
        ans = min(ans, count());
        return;
    }
    int cam[9][9];
    int x = cctv[depth].first;
    int y = cctv[depth].second;

    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cam[i][j] = arr[i][j];
            }
        }
        if (arr[x][y] == 1) {
            record(x, y, dir);
        }
        else if (arr[x][y] == 2) {
            record(x, y, dir);
            record(x, y, dir + 2);
        }
        else if (arr[x][y] == 3) {
            record(x, y, dir);
            record(x, y, dir + 1);
        }
        else if (arr[x][y] == 4) {
            record(x, y, dir);
            record(x, y, dir + 1);
            record(x, y, dir + 2);
        }
        else if (arr[x][y] == 5) {
            record(x, y, dir);
            record(x, y, dir + 1);
            record(x, y, dir + 2);
            record(x, y, dir + 3);
        }
        dfs(depth + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = cam[i][j];
            }
        }
    }   
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] != 6)
                cctv.push_back({i,j});
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}