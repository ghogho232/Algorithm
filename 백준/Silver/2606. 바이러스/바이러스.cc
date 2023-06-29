#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<math.h>
#include<queue>
using namespace std;

int map[200][200] = { 0 };
int visited[200] = { 0 };
int cnt = 0;
void dfs(int v) {
	visited[v] = 0;
	//cout << v << " ";
	for (int i = 0; i < 200; i++) {
		if (map[v][i] && visited[i]) {
			cnt++;
			dfs(i);
		}
	}
}

int main(void) {
	int node, edge;
	cin >> node;
	cin >> edge;
	int v1, v2;
	for (int i = 0; i < edge; i++) {
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1;
		visited[v1] = visited[v2] = 1;
	}
	dfs(1);
	cout << cnt;
}