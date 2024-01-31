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

using namespace std;

int n, l, r;
int arr[51][51];
int visited[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int,int>>v;
queue<pair<int,int>>q;
int sum = 0;
int ans = 0;
bool flag = true;

void move(int x, int y){
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny])
                continue;
            if(abs(arr[nx][ny]-arr[cur.first][cur.second]) < l || abs(arr[nx][ny]-arr[cur.first][cur.second]) > r)
                continue;
            q.push({nx,ny});
            visited[nx][ny] = 1;
            v.push_back({nx,ny});
            sum += arr[nx][ny];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    while(flag){
        flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    v.clear();
                    v.push_back({i,j});
                    sum = arr[i][j];
                    move(i,j);
                }
                if(v.size() >= 2){
                    flag = true;
                    for(int i = 0; i < v.size(); i++){
                        arr[v[i].first][v[i].second] = sum / v.size(); 
                    }
                }
            }
        }
        if(flag)
            ans++;
        else
            break;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}