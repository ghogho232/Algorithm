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

vector<int> graph[501];
int visited[501] = { 0 };

bool dfs(int node, int before){
    visited[node] = 1;
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(next == before)
            continue;
        if(visited[next])
            return false;
        if(!dfs(next,node))
            return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int cnt = 1;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i <= n; i++){
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
        int ans = 0;
        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                if(dfs(i,0))
                    ans++;
            }
        }
        cout << "Case "<< cnt++ <<": ";
        if(ans == 0)
            cout << "No trees."<<"\n";
        else if(ans == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << ans <<" trees.\n";
    }
    return 0;
}