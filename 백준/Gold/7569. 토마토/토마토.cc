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
#define MAX 101
using namespace std;
int graph[MAX][MAX][MAX];
int state[MAX][MAX][MAX];

struct xyz {
	int x, y, z;
};

int m, n, h;
int dx[6] = { 0, 0, 1, 0, -1, 0 };
int dy[6] = { 0, 0, 0, -1, 0, 1 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };
queue<xyz> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = dx[i] + y;						
            int ny = dy[i] + z;
            int nz = dz[i] + x;
			if (nx >= n || nx < 0 || ny >= m || ny < 0 || nz >= h || nz < 0) continue;
			else if (!state[nz][nx][ny] && graph[nz][nx][ny] == 0) {
				state[nz][nx][ny] = 1;
				graph[nz][nx][ny] = graph[x][y][z] + 1;
				q.push({ nz, nx, ny });
			}
		}
	}
}
int main() {
    int ans = 0;
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) {
                    state[i][j][k] = 1;
                    q.push({ i, j, k });
                }
            }
        }
    }
    bfs();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (graph[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, graph[i][j][k]);
            }
        }
    }
    if (ans - 1 == 0) {
        cout << 0;
        return 0;
    }

    cout << ans - 1;
}