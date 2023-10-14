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
int graph[10];
int ans[10];
void dfs(int v, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << ans[i] <<" ";
        }
        cout << "\n";
        return;
    }
    else{
        for(int i = v; i < n; i++){
            ans[cnt] = graph[i];
            dfs(i, cnt + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> graph[i];
    }
    sort(graph, graph + n);
    dfs(0,0);
    return 0;
}