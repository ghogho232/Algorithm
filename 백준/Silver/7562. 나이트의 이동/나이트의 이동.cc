#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define MAX 301

using namespace std;

int l;
int map[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };

int dx[8] = { -2,-2, -1, 1, 2, 2, 1, -1 };
int dy[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
queue<pair<int, int>> q;

void reset() {
	memset(map, 0, sizeof(map));
	memset(visited, 0, sizeof(visited));
	while (!q.empty()) {
		q.pop();
	}
}
void bfs(int x, int y,int destx,int desty) {
	q.push(make_pair(x, y));
	visited[x][y] == 1;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		if (cur_x == destx && cur_y == desty)
			break;

		for (int i = 0; i < 8; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= l || ny<0 || ny>=l || visited[nx][ny])
				continue;
			q.push(make_pair(nx, ny));
			map[nx][ny] = map[cur_x][cur_y] + 1;
			visited[nx][ny] = 1;
			
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for(int i = 0 ; i < testcase; i++){
		reset();
		cin >> l;
		int x, y, destx, desty;
		cin >> x >> y >> destx >> desty;
		bfs(x, y, destx, desty);
		cout << map[destx][desty]  << "\n";

	}
	return 0;
}