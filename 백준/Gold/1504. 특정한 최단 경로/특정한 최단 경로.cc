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
#define ll long long

using namespace std;

vector<pair<int, int>> graph[801];
int V, E;
int value[801];

int djikstra(int begin,int end) {
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
	return value[end];
}
	
int main() {

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({ to,weight });
		graph[to].push_back({ from,weight });

	}
	int v1, v2;
	cin >> v1 >> v2;

	fill(value, value + 801, INF);
	ll atov1 = djikstra(1, v1);
	fill(value, value + 801, INF);
	ll v1tov2 = djikstra(v1, v2);
	fill(value, value + 801, INF);
	ll v2tob = djikstra(v2, V);
	
	fill(value, value + 801, INF);
	ll atov2 = djikstra(1,v2);
	fill(value, value + 801, INF);
	ll v2tov1 = djikstra(v2, v1);
	fill(value, value + 801, INF);
	ll v1tob = djikstra(v1, V);

	ll ans1 = atov1 + v1tov2 + v2tob;
	ll ans2 = atov2 + v2tov1 + v1tob;

	if (ans1 >= INF && ans2 >= INF)
		cout << "-1" << "\n";
	else
		cout << min(ans1, ans2);
	return 0;
}