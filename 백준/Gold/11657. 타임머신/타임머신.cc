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
#define MAX 501
#define INF 1e9
using namespace std;
vector<pair<int, int>> graph[MAX];
vector<long long> dist;
int N, M;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // 입력된 간선 정보를 그래프에 저장
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }

    // 거리 배열 초기화
    dist.resize(N + 1, INF);
    dist[1] = 0;

    bool Cycle = false;
    // 최단 거리 갱신
    for (int round = 1; round <= N; round++) {
        for (int i = 1; i <= N; i++) {
            for (auto item : graph[i]) {
                int cost = item.first;
                int next = item.second;

                // 현재 거리와 비교하여 최단 거리 갱신
                if (dist[i] != INF && dist[next] > dist[i] + cost) {
                    dist[next] = dist[i] + cost;
                    if (round == N) // 음수 사이클 검출
                        Cycle = true;
                }
            }
        }
    }
    // 음수 사이클이 있을 경우 출력
    if (Cycle)
        cout << -1 << '\n';
    else {
        // 1번 정점을 제외한 나머지 정점의 최단 거리 출력
        for (int i = 2; i <= N; i++) {
            if (dist[i] >= INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}
