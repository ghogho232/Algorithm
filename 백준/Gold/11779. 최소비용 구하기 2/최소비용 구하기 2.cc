#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
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
#define ll long long

using namespace std;
int n, m;
vector<pair<int,int>> graph[1001];
int value[1001];
int path[1001];
const int INF = 987654321;

void djikstra(int begin){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, begin});
    value[begin] = 0;

    while(!pq.empty()){
        int dist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(value[cur] < dist)
            continue;
        for(int i = 0; i < graph[cur].size(); i++){
            int cost = dist + graph[cur][i].second;
            int next = graph[cur][i].first;
            if(cost < value[next]){
                value[next] = cost;
                path[next] = cur;
                pq.push({value[next],next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>ans;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});
    }
    int begin, dest;
    fill(value, value + n + 1, INF);
    cin >> begin >> dest;
    djikstra(begin);

    int idx = dest;
    while(1) {
        if(path[idx] == 0) {
            ans.push_back(begin);
            break;
        }
        ans.push_back(idx);
        idx = path[idx];
    }
    reverse(ans.begin(), ans.end());

    cout << value[dest] <<"\n" << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] <<" ";
    }
    return 0;
}