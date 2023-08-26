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


using namespace std;

int v, e;
vector<int> graph[20001];
int color[20001] = { 0 };

void dfs(int v) {
	if (!color[v]) {
		color[v] = 2;
	}
	for (int i = 0; i < graph[v].size(); i++) {
		int nx = graph[v][i];
		if (!color[nx]) {
			if (color[v] == 2)
				color[nx] = 3;
			else if (color[v] == 3)
				color[nx] = 2;
			dfs(nx);
		}
	}
	return;
}

bool isGood() {
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int nx = graph[i][j];
			if (color[i] == color[nx])
				return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			graph[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) { 
			if (!color[i])
				dfs(i);
		}
		if (isGood())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}