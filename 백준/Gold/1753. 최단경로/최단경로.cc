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
#define INF 987654321

using namespace std;

vector<pair<int, int>> graph[20001];
int V, E;
int value[20001];

void djikstra(int begin) {
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,begin });
	value[begin] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (value[cur] < dist)
			continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int cost = dist + graph[cur][i].second;
			if (cost < value[graph[cur][i].first]) {
				value[graph[cur][i].first] = cost;
				pq.push({ -cost,graph[cur][i].first });
			}
		}
	}
}
	
int main() {
	int begin;
	cin >> V >> E >> begin;
	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to,weight });

	}
	fill(value, value + 20001, INF);
	djikstra(begin);
	for (int i = 1; i <= V; i++) {
		if (value[i] == INF)
			cout << "INF" <<"\n";
		else
			cout << value[i] << "\n";
	}
	return 0;
}