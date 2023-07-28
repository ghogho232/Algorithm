#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<deque>
#include <sstream>

using namespace std;

const int MAX = 10;

int n;
int s[MAX][MAX];
vector<pair<int, int>>v;

bool check(int y,int x, int i) {
    for (int j = 0; j < 9; j++) {
        if (s[y][j] == i || s[j][x] == i) {
            return false;
        }
    }
    for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) {
        for (int k = (x / 3) * 3; k < (x / 3) * 3 + 3; k++) {
            if (s[j][k] == i)
                return false;
        }
    }
    return true;
}
bool dfs(int cur) {
    if (cur == v.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << s[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }
    int x = v[cur].second;
    int y = v[cur].first;
    for (int i = 1; i <= 9; i++) {
        if (check(y, x, i)) {
            s[y][x] = i;
            if(dfs(cur + 1))
                return true;
            s[y][x] = 0;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> s[i][j];
            if (s[i][j] == 0) {
                v.push_back({ i,j });
            }
        }
    }       
    dfs(0);
    return 0;
}