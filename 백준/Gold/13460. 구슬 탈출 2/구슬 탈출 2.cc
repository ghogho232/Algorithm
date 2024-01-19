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

const int wall = 1;
const int goal = 2;
int n, m;
int graph[11][11];
int visited[11][11][11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans = -1;

pair<int, int> red, blue;
struct ball {
    int rx, ry, bx, by;
    int cnt;
} Ball;

void move(int& x, int& y, int dir) {
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (graph[x][y] == wall) {
            x -= dx[dir];
            y -= dy[dir];
            break;
        } else if (graph[x][y] == goal) {
            break;
        }
    }
}

void bfs() {
    queue<ball> q;
    q.push({red.first, red.second, blue.first, blue.second, 0});
    visited[red.first][red.second][blue.first][blue.second] = 1;

    while (!q.empty()) {
        ball cur = q.front();
        q.pop();

        if (cur.cnt > 10)
            break;
        if (graph[cur.rx][cur.ry] == goal) {
            ans = cur.cnt;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int rx = cur.rx;
            int ry = cur.ry;
            int bx = cur.bx;
            int by = cur.by;
            move(rx, ry, i);
            move(bx, by, i);

            if (graph[bx][by] == goal)
                continue;

            if (rx == bx && ry == by) {
                switch (i) {
                case 0:
                    cur.rx < cur.bx ? bx++ : rx++;
                    break;
                case 2:
                    cur.rx < cur.bx ? rx-- : bx--;
                    break;
                case 1:
                    cur.ry < cur.by ? by++ : ry++;
                    break;
                case 3:
                    cur.ry < cur.by ? ry-- : by--;
                    break;
                }
            }
            if (!visited[rx][ry][bx][by]) {
                q.push({rx, ry, bx, by, cur.cnt + 1});
                visited[rx][ry][bx][by] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    char ch;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch;
            if (ch == '#')
                graph[i][j] = wall;
            else if (ch == 'O')
                graph[i][j] = goal;
            else if (ch == 'B') {
                blue.first = i;
                blue.second = j;
            } else if (ch == 'R') {
                red.first = i;
                red.second = j;
            }
        }
    }
    bfs();
    cout << ans;
    return 0;
}