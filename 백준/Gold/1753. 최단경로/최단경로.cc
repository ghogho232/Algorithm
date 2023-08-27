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
	priority_queue<pair<int, int>>pq; //우선순위 큐로 다익스트라 구현
	pq.push({ 0,begin }); //초기 최단거리 값과 시작정점 삽입
	value[begin] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first; //거리 (최소 힙 처럼 사용하기 위해 -처리)
		int cur = pq.top().second; //현재 정점
		pq.pop();
		if (value[cur] < dist) //현재 최소 비용보다 이미 구해진 것보다 작다면 패스
			continue;
		for (int i = 0; i < graph[cur].size(); i++) { //현재 정점과 연결된 모든 정점에 대해
			int cost = dist + graph[cur][i].second; //현재 정점 비용+이전까지의 비용
			if (cost < value[graph[cur][i].first]) { //새로운 최단 거리가 기존의 최단 거리보다 작다면
				value[graph[cur][i].first] = cost; //최단 거리 업데이트
				pq.push({ -cost,graph[cur][i].first }); //다음 정점 큐 삽입
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
