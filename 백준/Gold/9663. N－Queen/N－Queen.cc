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

const int MAX = 9;

int n, ans=0;
int col[16];

bool check(int v) {
    for (int i = 0; i < v; i++) {
        if (col[v] == col[i] || v - i == abs(col[v] - col[i]))
            return false;
    }        
    return true;
}
void dfs(int v) {
    if (v == n)
        ans++;
    else {
        for (int i = 1; i <= n; i++) {
            col[v] = i;
            if (check(v)) 
                dfs(v + 1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dfs(0);
    cout << ans;
}