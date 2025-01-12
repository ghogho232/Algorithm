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

int n, m;
vector<vector<int>> board;  // 체스판

// Queen의 8방향 (상하좌우 + 대각선)
int qx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int qy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

// Knight의 8방향 (L자 이동)
int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// Queen의 공격 범위 처리
void markQueen(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x, ny = y;
        while (true) {
            nx += qx[i];
            ny += qy[i];

            // 체스판 범위를 벗어나면 중단
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;

            // 다른 기물을 만나면 중단
            if (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 3) break;

            // 빈 칸이면 공격 범위 표시
            if (board[nx][ny] == 0) board[nx][ny] = 4;
        }
    }
}

// Knight의 공격 범위 처리
void markKnight(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + kx[i];
        int ny = y + ky[i];

        // 체스판 범위를 벗어나면 무시
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        // 빈 칸이면 공격 범위 표시
        if (board[nx][ny] == 0) board[nx][ny] = 4;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));  // 체스판 초기화

    // Queen 입력 및 배치
    int q;
    cin >> q;
    vector<pair<int, int>> queens;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;  // 0-indexed로 변환
        board[x][y] = 1;  // Queen 배치
        queens.emplace_back(x, y);
    }

    // Knight 입력 및 배치
    int k;
    cin >> k;
    vector<pair<int, int>> knights;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;  // 0-indexed
        board[x][y] = 2;  // Knight 배치
        knights.emplace_back(x, y);
    }

    // Pawn 입력 및 배치
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;  // 0-indexed
        board[x][y] = 3;  // Pawn 배치
    }

    // Queen의 공격 범위 표시
    for (auto& queen : queens) {
        markQueen(queen.first, queen.second);
    }

    // Knight의 공격 범위 표시
    for (auto& knight : knights) {
        markKnight(knight.first, knight.second);
    }

    // 안전한 칸 개수 세기
    int safeCount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0)
                safeCount++;

    cout << safeCount << "\n";
    return 0;
}