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
#define MAX INT_MAX
using namespace std;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int n, m;
int arr[501][501];
int dp[501][501];

int dfs(int y, int x){
    if(y == n && x == m)
        return 1;
    int &ans = dp[y][x];
    if(ans != -1)
        return ans;
    ans = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny >= 1 && ny <= n && nx >= 1 && nx <= m){
            if (arr[y][x] > arr[ny][nx])
                ans += dfs(ny, nx);
        } 
    
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }
    cout << dfs(1,1);
    return 0;
}