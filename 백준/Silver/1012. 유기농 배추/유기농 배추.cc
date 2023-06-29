#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<math.h>
#include<queue>
using namespace std;

const int MAX = 51;
int map[MAX][MAX] = { 0 };

int m, n, k;


void dfs(int y, int x) {

	if (y < 0 || y >= n || x < 0 || x >= m || !map[y][x])
		return;

	map[y][x] = 0;
	dfs(y + 1,x);
	dfs(y,x+1);
	dfs(y - 1,x);
	dfs(y,x - 1);
}

void process(int testcase) {
	cin >> m >> n >> k;
	int cnt = 0;
	for (int i = 0; i < k; i++) {

		int y,x;
		cin >> y >> x;
		map[x][y] = 1;
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (map[y][x]) {
				dfs(y, x);
				cnt++;
			}
		}
	}

	cout << cnt<<"\n";
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		process(i);
	}

	return 0;
}