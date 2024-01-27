#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
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

int n, m;
int r, c, dir;
int cnt = 0;
vector<vector<int>> arr(51, vector<int>(51,0));
int visited[51][51];

int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    while (true) {
        if (!visited[r][c]) {
            visited[r][c] = 1;
            cnt++;
        }
        bool clean = true;
        for (int i = 1; i <= 4; i++) {
            int nd = (dir + 4 - i) % 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if (visited[nr][nc] || arr[nr][nc])
                continue;
            clean = false;
            r = nr;
            c = nc;
            dir = nd;
            break;
        }
        if (clean) {
            int bdir = (dir + 2) % 4;
            int br = r + dr[bdir];
            int bc = c + dc[bdir];
            if (arr[br][bc] == 1)
                break;
            else {
                r = br;
                c = bc;
            }
        }
    }
    cout << cnt;
    return 0;
}