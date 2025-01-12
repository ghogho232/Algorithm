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

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    bool visited[6][6] = { false };
    string route[36];
    bool flag = true;

    for (int i = 0; i < 36; i++) {
        cin >> route[i];
    }

    int startX = route[0][0] - 'A';
    int startY = route[0][1] - '1';
    visited[startX][startY] = true;

    int prevX = startX;
    int prevY = startY;

    for (int i = 1; i < 36; i++) {
        int nextX = route[i][0] - 'A';
        int nextY = route[i][1] - '1';
        bool validMove = false;
        for (int j = 0; j < 8; j++) {
            int nx = prevX + dx[j];
            int ny = prevY + dy[j];

            if (nx == nextX && ny == nextY) {
                validMove = true;
                break;
            }
        }


        if (!validMove || visited[nextX][nextY]) {
            flag = false;
            break;
        }

        visited[nextX][nextY] = true;
        prevX = nextX;
        prevY = nextY;
    }

    bool backToStart = false;
    for (int j = 0; j < 8; j++) {
        int nx = prevX + dx[j];
        int ny = prevY + dy[j];
        if (nx == startX && ny == startY) {
            backToStart = true;
            break;
        }
    }

    if (flag && backToStart) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }

    return 0;
}