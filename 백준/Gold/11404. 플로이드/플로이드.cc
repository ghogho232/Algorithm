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
#define MAX 101
#define INF 1e9
using namespace std;

int graph[MAX][MAX];
int n,m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++){
        int begin, end, weight;
        cin >> begin >> end >> weight;
        graph[begin][end] = min(graph[begin][end],weight);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == INF || graph[i][j] == 0)
                cout << 0 << " ";
            else cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}