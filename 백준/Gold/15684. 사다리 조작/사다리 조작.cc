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

int n, m, h;
int arr[31][11];
int ans = -1;

bool check() {
    for (int i = 1; i <= n; i++) {
        int num = i;//시작
        for (int j = 1; j <= h; j++) {
            if (arr[j][num] == 1)
                num++;
            else if (arr[j][num - 1] == 1)
                num--;
        }
        if (num != i) //시작과 끝 불일치
            return false;
    }
    return true;
}
void dfs(int depth, int cnt) {
    if (depth == cnt) {
        if (check()) {
            cout << depth;
            exit(0);
        }
        return;
    }
    for (int j = 1; j < n; j++) {
        for (int i = 1; i <= h; i++) {
            if (arr[i][j] || arr[i][j + 1] || arr[i][j - 1]) //사다리가 그 자리에 이미 있거나 양 옆에 있으면
                continue;
            arr[i][j] = 1;
            dfs(depth, cnt + 1);
            arr[i][j] = 0;
            while (!arr[i][j + 1] && !arr[i][j - 1]) { //사다리 놓을 수 있을 때까지 스킵
                i++;
            }
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for (int i = 0; i < 4; i++) {
        dfs(i, 0);
    }
    cout << ans;
    return 0;
}