#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
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

int graph[501][501] = {0};
int visited[501][501] = {0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0,};
int MAX = 0, sum = 0, ret = 0;
int n, m;

const int o[4][4][2] = {
    {{1, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},
    {{1, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}}
};

int odfs(int y, int x) {
    int ret = 0; 
    for (int i = 0; i < 4; i++) {
        int tmp = 0;
        for (int j = 0; j < 4; j++) {
            int nx = x + o[i][j][1];
            int ny = y + o[i][j][0];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                tmp = 0;
                break;
            }
            else
                tmp += graph[ny][nx];     
        }
        ret = max(tmp, ret);
    }
    return ret;
}

void dfs(int y, int x, int depth, int sum){
    if(depth == 3) {
        MAX = max(MAX, sum);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >=m || ny <0 || ny >=n || visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, depth + 1, sum + graph[ny][nx]);
        visited[ny][nx] = 0;
    }

}

int main() {

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = 1;
            dfs(i, j, 0, graph[i][j]);
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            MAX = max(MAX, odfs(i,j));
        }
    }
    cout << MAX;
    return 0;
}