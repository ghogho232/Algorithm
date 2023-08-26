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

int graph[MAX];
int visited[MAX] = { 0 };
int n, m;
vector<pair<int, int>>l, s;
queue<pair<int, int>>q;
int dx[6] = { 1,2,3,4,5,6 };

int isSnakeLadder(int n) {
	for (int i = 0; i < l.size(); i++) {
		if (n == l[i].first)
			return l[i].second;
	}
	for (int i = 0; i < s.size(); i++) {
		if (n == s[i].first)
			return s[i].second;
	}
	return n;
}
void bfs() {
	q.push({ 1,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		visited[cur] = 1;
		if (cur == 100){
			cout << cnt;
			return;
		}

		for (int i = 0; i < 6; i++) {
			int nx = cur + dx[i];
			int nnx = isSnakeLadder(nx);
			if (!visited[nnx] && nnx <= 100)
				q.push({ nnx,cnt+1 });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		l.push_back({ a,b });
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		s.push_back({ a,b });
	}
	bfs();
	return 0;
}