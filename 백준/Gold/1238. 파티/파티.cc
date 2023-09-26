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

const int INF = 987654321;
vector<pair<int, int>>graph[1001];
int value[10001];

void djikstra(int begin){
    priority_queue<pair<int,int>> pq;
    pq.push({0, begin});
    value[begin] = 0;    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[here].size(); i++){
            int there = graph[here][i].first;
            int next = cost + graph[here][i].second;
            if(value[there] > next){
                value[there] = next;
                pq.push({-next, there});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    int xval[1001];
    int MAX = 0;
    for(int i = 0; i < m; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to,weight});
    }
    fill(value, value + 1001, INF);
    djikstra(x);
    for(int i = 1; i <= n; i++){
        xval[i] = value[i];
    }

    for(int i = 1; i <= n; i++){
        if(i == x) continue;
        fill(value, value + 1001, INF);
        djikstra(i);
        int sum = value[x] + xval[i];
        MAX = max(sum, MAX);
    }
    cout << MAX;
    return 0;
}