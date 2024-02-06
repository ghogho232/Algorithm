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

int n, m;
int arr[51][51];
vector<pair<int,int>> virus;
int area = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int ans = INF;

void bfs(vector<pair<int,int>> v){

    queue<pair<int,int>>q;
    int dist[51][51];
    memset(dist,-1,sizeof(dist));
    for(int i = 0; i < v.size(); i++){
        q.push(v[i]);
        dist[v[i].first][v[i].second] = 0;
    }
    int infected = 0;
    int total = 0;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || arr[nx][ny] == 1 || dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[curx][cury] + 1;
            if(arr[nx][ny] == 0){
                infected++;
                total = dist[nx][ny];
            }
            q.push({nx,ny});

        }
    }
    if(infected == area){
        ans = min(ans,total);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                area++;
            }
            else if(arr[i][j] == 2){
                virus.push_back({i,j});
            }
        }
    }
    vector<int>support(virus.size(),0);
    for(int i = virus.size()-m; i < virus.size(); i++){
        support[i] = 1;
    }
    do{
        vector<pair<int,int>>actVirus(m);

        int index = 0;
        for(int i = 0; i < support.size(); i++){
            if(support[i] == 1){
                actVirus[index++] = virus[i];
            }
}
        // cout <<"\n"<<"act사이즈 : "<<actVirus.size()<<"\n";
        bfs(actVirus);

    }while(next_permutation(support.begin(),support.end()));
    if(ans == INF)
        cout << -1;
    else 
        cout << ans;
    return 0;
}