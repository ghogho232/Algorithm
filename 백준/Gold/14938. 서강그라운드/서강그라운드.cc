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
const int INF = 987654321;
int n, m, r;
int value[101];
int graph[101][101];
int path[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    int root, max_val=0, ans=0;
    for(int i = 1; i <= n; i++){
        cin >> value[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for(int i = 0; i < r; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from][to] = graph[to][from] = min(graph[from][to],weight);

    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][k] + graph[k][j] , graph[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
		path[i] = value[i];
		for (int j = 1; j <= n; ++j) {
			if (i != j && graph[i][j] <= m) {
				path[i] += value[j];
			}
		}
		ans = max(ans, path[i]);
	}
    cout << ans;

    return 0;
}