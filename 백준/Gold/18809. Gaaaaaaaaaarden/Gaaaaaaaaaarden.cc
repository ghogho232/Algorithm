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

int graph[51][51];
vector<pair<int, int>> soil;
vector<pair<int, int>> green;
vector<pair<int, int>> red;
int gtime[51][51];
int rtime[51][51];
bool flower[51][51];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int soilSize;
int n, m, g, r;
int ans = 0;

void bfs() {
    queue<pair<int, int>> gq;
    queue<pair<int, int>> rq;
    memset(gtime, -1, sizeof(gtime));
    memset(rtime, -1, sizeof(rtime));
    memset(flower, 0, sizeof(flower));

    for(pair<int, int> p : green) {
        gq.push({p.first, p.second});
        gtime[p.first][p.second] = 0;
    }
    for(pair<int, int> p : red) {
        rq.push({p.first, p.second});
        rtime[p.first][p.second] = 0;
    }

    int tmp = 0;
    while (!gq.empty() || !rq.empty()) {
        int gqsize = gq.size();
        int rqsize = rq.size();

        while (gqsize--) {
            int curx = gq.front().first;
            int cury = gq.front().second;
            gq.pop();

            if (flower[curx][cury])
                continue;
            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                    continue;
                if(gtime[nx][ny] != -1 || graph[nx][ny] == 0)
                    continue;
                if (rtime[nx][ny] != -1) 
                    continue;
                gtime[nx][ny] = gtime[curx][cury] + 1;
                gq.push({nx, ny});
            }
        }

        while (rqsize--) {
            int curx = rq.front().first;
            int cury = rq.front().second;
            rq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curx + dx[i];
                int ny = cury + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) 
                    continue;
                if (rtime[nx][ny] != -1 || graph[nx][ny] == 0) 
                    continue;               
                if (gtime[nx][ny] == -1) {  
                    rtime[nx][ny] = rtime[curx][cury] + 1;
                    rq.push(make_pair(nx, ny));
                }
                else if (gtime[nx][ny] == rtime[curx][cury] + 1) {
                    flower[nx][ny] = true;
                    rtime[nx][ny] = rtime[curx][cury] + 1;
                    tmp++;
                }
            }
        }
    }
    ans = max(ans, tmp);
}

void dfs(int idx, int gcnt, int rcnt) {
    if (gcnt + rcnt > soilSize - idx) {
        return;
    }

    if (gcnt == 0 && rcnt == 0) {
        bfs();
        return;
    }

    int x = soil[idx].first;
    int y = soil[idx].second;

    dfs(idx + 1, gcnt, rcnt);

    if (gcnt > 0) {
        green.push_back({x, y});
        dfs(idx + 1, gcnt - 1, rcnt);
        green.pop_back();
    }

    if (rcnt > 0) {
        red.push_back({x, y});
        dfs(idx + 1, gcnt, rcnt - 1);
        red.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> g >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                soil.push_back({i, j});
            }
        }
    }

    soilSize = soil.size();
    dfs(0, g, r);
    cout << ans;

    return 0;
}