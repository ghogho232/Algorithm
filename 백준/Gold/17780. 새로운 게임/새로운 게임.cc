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
#define INF 987654321

using namespace std;
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0};

struct Piece {
    int idx, col, row, dir;
};

vector<vector<int>> board(13, vector<int>(13));
vector<vector<vector<int>>> graph(13, vector<vector<int>>(13));
Piece piece[11];

bool is_valid(int nx, int ny, int n) {
    return nx >= 1 && nx <= n && ny >= 1 && ny <= n;
}

void move_pieces(int x, int y, int nx, int ny, int idx, bool reverse_flag) {
    vector<int> tmp;
    for (int i = idx; i < graph[x][y].size(); i++) {
        int nidx = graph[x][y][i];
        piece[nidx].col = nx;
        piece[nidx].row = ny;
        tmp.push_back(nidx);
    }
    graph[x][y].erase(graph[x][y].begin() + idx, graph[x][y].end());
    if (reverse_flag) reverse(tmp.begin(), tmp.end());
    graph[nx][ny].insert(graph[nx][ny].end(), tmp.begin(), tmp.end());
}

void reverse_direction(int &dir) {
    if (dir == 0) dir = 1;
    else if (dir == 1) dir = 0;
    else if (dir == 2) dir = 3;
    else dir = 2;
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    for (int i = 0; i < k; i++) {
        cin >> piece[i].col >> piece[i].row >> piece[i].dir;
        piece[i].idx = i;
        piece[i].dir--; // 입력된 방향값을 0base로 조정
        graph[piece[i].col][piece[i].row].push_back(i);
    }

    for (int turn = 1; turn <= 1000; turn++) {
        for (int i = 0; i < k; i++) {
            int x = piece[i].col, y = piece[i].row, dir = piece[i].dir;
            if (graph[x][y][0] != i) continue; // 맨 아래 말이 아니라면 스킵

            int nx = x + dx[dir], ny = y + dy[dir];

            if (!is_valid(nx, ny, n) || board[nx][ny] == 2) { // 범위 밖 or 파란색
                reverse_direction(dir);
                piece[i].dir = dir;
                nx = x + dx[dir];
                ny = y + dy[dir];
                if (!is_valid(nx, ny, n) || board[nx][ny] == 2) continue; // 다시 파란색이면 이동 안 함
            }

            if (board[nx][ny] == 0) { // 흰색
                move_pieces(x, y, nx, ny, 0, false);
            } else if (board[nx][ny] == 1) { // 빨간색
                move_pieces(x, y, nx, ny, 0, true);
            }

            if (graph[nx][ny].size() >= 4) { // 말 4개 이상 쌓이면 게임 종료
                cout << turn;
                return 0;
            }
        }
    }

    cout << -1; // 1000턴 초과
    return 0;
}