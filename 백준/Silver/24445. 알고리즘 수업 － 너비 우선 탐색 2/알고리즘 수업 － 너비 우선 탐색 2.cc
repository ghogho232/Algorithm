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

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0 };
int res[100001] = { 0 };
int n, m, r, cnt = 0;;

void bfs(int r) {
    queue<int> q;
    q.push(r);
    visited[r] = 1;
    cnt++;
    res[r] = cnt;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int tmp = graph[cur][i];
            if (!visited[tmp]) {
                cnt++;
                res[tmp] = cnt;
                q.push(tmp);
                visited[tmp] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(),greater<int>());
    }
    bfs(r);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}