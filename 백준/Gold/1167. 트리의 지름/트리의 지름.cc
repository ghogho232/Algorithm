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
#define ll long long
using namespace std;

const int MAX = 100001;
vector<pair<int,int>>graph[MAX];
int visited[MAX];
int maxdist = 0, newNode = 0;

void dfs(int v, int dist){
    visited[v] = 1;

    if(maxdist < dist){
        maxdist = dist;
        newNode = v;
    }
    for(int i = 0; i < graph[v].size(); i++){
        int nextNode = graph[v][i].first;
        int nextDist = graph[v][i].second;
        if(!visited[nextNode])
            dfs(nextNode,nextDist + dist);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int v1, v2, w;
        cin >> v1;
        while(1){
            cin >> v2;
            if(v2 == -1)
                break;
            cin >> w;
            graph[v1].push_back({v2,w});
            graph[v2].push_back({v1,w});
        }
    }
    dfs(1,0);
    memset(visited, 0, sizeof(visited));
    maxdist = 0;
    dfs(newNode, 0);
    
    cout << maxdist;
    return 0;
}