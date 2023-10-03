#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;
vector<pair<int, int>> graph[1001];
int value[1001];
const int INF = 987654321;

void djikstra(int begin) { 
    priority_queue<pair<int, int>> pq;
    pq.push({0, begin});
    fill(value, value + 1001, INF); 

    value[begin] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (value[cur] < dist) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int cost = dist + graph[cur][i].second;

            if (cost < value[next]) {
                value[next] = cost;
                pq.push({-cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }

    int begin, end;
    cin >> begin >> end;

    djikstra(begin); 

    cout << value[end];

    return 0;
}