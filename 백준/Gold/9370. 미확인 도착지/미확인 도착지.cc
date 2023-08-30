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
#define INF 987654321
#define MAX 2001 
using namespace std;    
int n,m,t,s,g,h,gh;
vector<pair<int,int>>graph[MAX];
vector<int>dist(2001,INF);
int S[MAX];
int G[MAX];
int H[MAX];
vector<int>candidate;

void djikstra(int s, int A[]){
    priority_queue<pair<int,int>>pq;
    pq.push({0,s});
    A[s] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur]<cost)
            continue;
        for(int i = 0;i<graph[cur].size();i++){
            int there = graph[cur][i].first;
            int nextDist = cost + graph[cur][i].second;

            if(A[there]>nextDist){
                A[there] = nextDist;
                pq.push({-nextDist,there});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        for(int i = 0;i<MAX;i++){
            graph[i].clear();
            candidate.clear();
            S[i] = INF;
            G[i] = INF;
            H[i] = INF;
        }

        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for(int i = 0; i < m; i++){
            int a,b,d;
            cin >> a >> b >> d;
            graph[a].push_back({b,d});
            graph[b].push_back({a,d});
        }
        for(int i = 0; i < t; i++){
            int x;
            cin >> x;
            candidate.push_back(x);
        }
        djikstra(s,S);
        djikstra(g,G);
        gh = G[h];
        djikstra(h,H);

        sort(candidate.begin(),candidate.end());
        for(int i = 0; i < candidate.size(); i++){
            int tmp = candidate[i];
            if(S[tmp] == S[g] + gh + H[tmp])
                cout << tmp << " ";
            else if(S[tmp] == S[h] + gh + G[tmp])
                cout << tmp << " ";
        }
        cout << "\n";
    }
    return 0;
}