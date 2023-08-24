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

using namespace std;

int graph[51][51] = { 0 };
int visit[51][51] = { 0 };
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int n, m, k;
int cnt = 0;

void dfs(int x, int y) {
    visit[x][y] = 1;
    int nx, ny;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visit[nx][ny] || !graph[nx][ny])
                continue;
            else
                dfs(nx, ny);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        memset(graph, 0, sizeof(graph));
        memset(visit, 0, sizeof(visit));
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visit[i][j] && graph[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;

}