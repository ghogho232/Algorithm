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

int arr[65][65];

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
    if (check) {
        cout << arr[x][y];
    }
    else {
        cout << "(";
        recur(x, y, n / 2);
        recur(x, y + n / 2, n / 2);
        recur(x + n / 2, y, n / 2);
        recur(x + n / 2, y + n / 2, n / 2);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = stoi(s.substr(j, 1));
        }
    }
    recur(0, 0, n);
    return 0;
}