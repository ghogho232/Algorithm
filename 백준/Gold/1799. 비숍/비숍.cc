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
#define MAX INT_MAX
#define MOD 1000000003
using namespace std;

int n;
int graph[11][11];
int visited[11][11];
vector<pair<int,int>>possible;
int ans = 0;
int blackans=0, whiteans=0;

bool check(int x, int y){
    int nx = x-1;
    int ny = y-1;
    while(nx>=0 && ny >=0){
        if(visited[nx][ny])
            return false;
        nx--;
        ny--;
    }
    nx = x-1;
    ny = y+1;
    while(nx>=0 && ny<n){
        if(visited[nx][ny])
            return false;
        nx--;
        ny++;
    }
    return true;

}
void blackdfs(int idx, int cnt){
    blackans = max(blackans,cnt);

    for(int i = idx; i < possible.size(); i++){
        int x = possible[i].first;
        int y = possible[i].second;
        if(x%2==0 && y%2==1)
            continue;
        if(x%2==1 && y%2==0)
            continue;
        if(!visited[x][y]&&check(x,y)){
            visited[x][y] = 1;
            blackdfs(i+1, cnt+1);
            visited[x][y] = 0;
        }
    }
}
void whitedfs(int idx, int cnt){
    whiteans = max(whiteans,cnt);

    for(int i = idx; i < possible.size(); i++){
        int x = possible[i].first;
        int y = possible[i].second;
        if(x%2==0 && y%2==0)
            continue;
        if(x%2==1 && y%2==1)
            continue;
        if(!visited[x][y]&&check(x,y)){
            visited[x][y] = 1;
            whitedfs(i+1, cnt+1);
            visited[x][y] = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 1)
                possible.push_back({i,j});
        }
    }

    blackdfs(0,0);
    whitedfs(0,0);
    ans = blackans + whiteans;    
    cout << ans;
    return 0;
}