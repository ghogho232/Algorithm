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

int arr[2200][2200]; int ans[3];

void recur(int x, int y, int n) {
    int cur = arr[x][y];
    bool check = 1;

    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[x][y]!=arr[i][j]) {
                check = 0;
                break;
            }
        }
        if (!check) break;
    }
    if (!check) {
        recur(x, y, n / 3);
        recur(x, y + n / 3, n / 3);
        recur(x, y + (n / 3) * 2, n / 3);
        recur(x + n / 3, y, n / 3);
        recur(x + n / 3, y + n / 3, n / 3);
        recur(x + n / 3, y + (n / 3) * 2, n / 3);
        recur(x + (n / 3) * 2, y, n / 3);
        recur(x + (n / 3) * 2, y + n / 3, n / 3);
        recur(x + (n / 3) * 2, y + (n / 3) * 2, n / 3);

    }
    else {
        ans[cur+1]++;
    }
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
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << "\n";
    return 0;
}