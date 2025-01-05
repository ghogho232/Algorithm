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
#define INF 987654321

using namespace std;

vector<pair<int,int>>v[50001];

int bfs(int k, int v2){
    vector<bool> visited(50001, false);
    int ans = 0;
    queue<int>q;
    visited[v2] = 1;
    q.push(v2);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            if(visited[next])
                continue;
            int USADO = v[cur][i].second;
            if(USADO >= k){
                visited[cur] = true;
                ans++;
                q.push(next);
            }
        }

    }
    return ans;
}
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n-1; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    for(int i = 0; i < q; i++){
        int k, v2;
        cin >> k >> v2;
        cout << bfs(k,v2)<<"\n";
    }

}