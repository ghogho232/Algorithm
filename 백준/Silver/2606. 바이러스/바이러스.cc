#define _CRT_SECURE_nO_WARnInGS
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
int n,m;
int arr[101][101] = {0};
int visited[101] = {0};
int cnt = 0;

void bfs(int v){
    queue<int>q;
    q.push(v);
    visited[v] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(arr[cur][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                cnt++;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = arr[b][a] = 1;
    }
    bfs(1);
    cout << cnt;

    return 0;
}

