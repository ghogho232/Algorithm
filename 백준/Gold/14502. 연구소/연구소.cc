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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m; 
int arr[8][8], visited[8][8], wall[8][8];
vector<pair<int,int>> virus, safe;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || wall[nx][ny])
                continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
            wall[nx][ny] = 2;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2)
                virus.push_back({i,j});
            else if(arr[i][j] == 0)
                safe.push_back({i,j});
        }
    }
    vector<bool> idx(safe.size(), false);
    for(int i = 0; i < 3; i++)
        idx[i] = true;
    sort(idx.begin(), idx.end());

    do{
        int cnt = 0;
        memcpy(wall, arr, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < idx.size(); i++){
            if(idx[i])
                wall[safe[i].first][safe[i].second] = 1;
        }
        for(int i = 0; i < virus.size(); i++){
            bfs(virus[i].first, virus[i].second);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(wall[i][j] == 0)
                    cnt++;
            }
        }
        ans = max(ans, cnt);
    }while(next_permutation(idx.begin(), idx.end()));

    cout << ans;
    return 0;
}