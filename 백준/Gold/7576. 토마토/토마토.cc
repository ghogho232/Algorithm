#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define MAX 1001

using namespace std;

queue<pair<int, int>> q;
int map[MAX][MAX] ;
int visited[MAX][MAX] ;
int M, N;
int dx[4] = { 1, 0, -1, 0  };
int dy[4] = { 0, 1, 0, -1 };


void bfs() {
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0 && visited[nx][ny] == -1) {
				visited[nx][ny] = visited[x][y] + 1;
				q.push(make_pair(nx,ny));
				
			}
		}
	}
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visited[i][j] = -1;

			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = 0;
			}
		}
	}

	bfs();

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, visited[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visited[i][j] == -1)
				ans = -1;
		}
	}
	cout << ans;
}
