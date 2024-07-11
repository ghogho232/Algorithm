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

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct Shark {
    int x, y, dir, score;
};

struct Fish {
    int x, y, dir;
    bool isDead = false;
};

int arr[4][4];
Fish fishes[17];
Shark shark;
int maxScore = 0;

void move_fishes(vector<vector<int>>& arr, vector<Fish>& fishes, Shark& shark) {
    for (int i = 1; i <= 16; i++) {
        if (fishes[i].isDead) continue;

        int x = fishes[i].x;
        int y = fishes[i].y;
        int dir = fishes[i].dir;

        for (int j = 0; j < 8; j++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == shark.x && ny == shark.y)) {
                dir = (dir + 1) % 8;
                continue;
            }

            if (arr[ny][nx] == 0) {
                arr[ny][nx] = i;
                arr[y][x] = 0;
                fishes[i] = {nx, ny, dir};
            } else {
                int temp = arr[ny][nx];
                arr[ny][nx] = i;
                arr[y][x] = temp;
                fishes[i] = {nx, ny, dir};
                fishes[temp] = {x, y, fishes[temp].dir};
            }
            break;
        }
    }
}

void dfs(vector<vector<int>> arr, vector<Fish> fishes, Shark shark) {
    move_fishes(arr, fishes, shark);

    bool canMove = false;
    for (int i = 1; i <= 3; i++) {
        int nx = shark.x + dx[shark.dir] * i;
        int ny = shark.y + dy[shark.dir] * i;

        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;

        if (arr[ny][nx] != 0) {
            canMove = true;
            int fishIdx = arr[ny][nx];
            int fishDir = fishes[fishIdx].dir;

            vector<vector<int>> newGrid = arr;
            vector<Fish> newFishes = fishes;
            Shark newShark = {nx, ny, fishDir, shark.score + fishIdx};

            newFishes[fishIdx].isDead = true;
            newGrid[ny][nx] = -1;
            newGrid[shark.y][shark.x] = 0;

            dfs(newGrid, newFishes, newShark);
        }
    }

    if (!canMove) {
        maxScore = max(maxScore, shark.score);
    }
}

void solve() {
    vector<vector<int>> arrVec(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arrVec[i][j] = arr[i][j];
        }
    }

    vector<Fish> fishVec(fishes, fishes + 17);
    dfs(arrVec, fishVec, shark);
    cout << maxScore << '\n';
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);        
    cout.tie(0);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num, dir;
            cin >> num >> dir;
            fishes[num] = {j, i, dir - 1}; // j와 i의 순서를 맞춤
            arr[i][j] = num;
        }
    }

    int startFish = arr[0][0];
    shark = {0, 0, fishes[startFish].dir, startFish};
    fishes[startFish].isDead = true;
    arr[0][0] = -1;

    solve();

    return 0;
}