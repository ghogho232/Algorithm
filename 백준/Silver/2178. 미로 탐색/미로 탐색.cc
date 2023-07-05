#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define MAX 101

using namespace std;

int m, n;
int map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int dist[MAX][MAX] = { 0 };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

void bfs(int x, int y) {
	visited[x][y] = 1;
	dist[x][y]++;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + cur_x;
			int ny = dy[i] + cur_y;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] && !visited[nx][ny]) {
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[cur_x][cur_y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0,0);
	cout << dist[n - 1][m - 1];
}
