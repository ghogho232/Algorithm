#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define MAX 51

using namespace std;

int m,n;
char map[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

int bfs(int x, int y) {
	int cnt = 0;
	memset(visited, 0, sizeof(visited));
	q.push(make_pair(x, y));
	visited[x][y] = 1;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == 'W' || visited[nx][ny])
				continue;
			q.push(make_pair(nx, ny));
			visited[nx][ny] = visited[cur_x][cur_y] + 1;
			cnt = max(cnt, visited[nx][ny]);	

		}
	}
	return cnt;
}

int main() {
	int ans = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans-1;
}
