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

const int MAX = 10001;
vector<pair<int,int>> graph[MAX];
int visited[MAX] = {0};
int longDis = 0, longNode = 0;

void dfs(int node, int w){
    visited[node] = 1;
    if(longDis < w){
        longDis = w;
        longNode = node;
    }
    for(int i = 0; i < graph[node].size(); i++){
        int nextNode = graph[node][i].first;
        int nextWeight = graph[node][i].second;
        if(!visited[nextNode]){
            dfs(nextNode, nextWeight+w);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int parent, child, weight;
        cin >> parent >> child >> weight;
        graph[parent].push_back({child,weight});
        graph[child].push_back({parent, weight});
    }
    dfs(1,0);

    memset(visited, 0, sizeof(visited));
    longDis = 0;
    
    dfs(longNode,0);

    cout << longDis;

    return 0;
}