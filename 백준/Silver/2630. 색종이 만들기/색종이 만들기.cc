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

using namespace std;

int arr[129][129]; int color[2];

void recur(int x, int y, int n) {
    int cur = arr[x][y];
    bool check = false;
    int br = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[x + i][y + j] != cur) {
                check = true;
                br = 1;
                break;
            }
        }
        if (br == 1) break;
    }
    if (check) {
        recur(x, y, n / 2);
        recur(x, y + (n / 2), n / 2);
        recur(x + (n / 2), y, n / 2);
        recur(x + (n / 2), y + (n / 2), n / 2);
    }
    else
        color[cur]++;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    recur(0, 0, n);
    cout << color[0] << " " << color[1] << "\n";
    return 0;
}