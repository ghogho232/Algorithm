#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#define MAX 100001

using namespace std;

queue<pair<int, int>> q;
int visited[MAX] = { 0 };
int n, k;

int bfs(int n) {
	q.push(make_pair(n, 0));
	visited[n] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k)
			return cnt;

		if (x + 1 < MAX && !visited[x + 1]) {
			q.push(make_pair(x + 1, cnt + 1));
			visited[x + 1] = 1;
		}

		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push(make_pair(x - 1, cnt + 1));
			visited[x - 1] = 1;
		}

		if (x * 2 < MAX && !visited[x * 2]) {
			q.push(make_pair(x * 2, cnt + 1));
			visited[2 * x] = 1;
		}
	}
	return 0;
}

int main() {
	cin >> n >> k;
	cout << bfs(n) << "\n";
	return 0;

}