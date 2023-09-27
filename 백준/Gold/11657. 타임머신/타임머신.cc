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
#define MAX 501 
#define INF 1e9
using namespace std;
vector<pair<int,int>> adj[501];
vector<long long> dist;
int N, M;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M ;
    for(int i=0; i<M; i++){
        int src, dest, cost;
        cin >> src >> dest >> cost;
        adj[src].push_back({cost, dest});
    }

    dist.resize(N+1, INF);
    dist[1] = 0 ;

    bool Cycle = false;
    for( int round = 1;  round <= N ; round ++ ){
        // 모든 edge 들을 조사한다.
        for(int i=1; i<=N; i++){
            for(auto item : adj[i]){
                int cost = item.first;
                int next = item.second;

                if( dist[i] != INF && dist[next] > dist[i] + cost ){
                    dist[next] = dist[i] + cost;
                    if( round == N ) Cycle = true;
                }
            }
        }
    }
        if(Cycle)
        cout << -1 << '\n';
    else{
        for(int i=2; i<=N; i++){
            if( dist[i] >= INF ) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }

    return 0;
}