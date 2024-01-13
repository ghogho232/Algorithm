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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int ans = 0;
    int dp[1001][1001];
    memset(dp, 0, sizeof(dp));  

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            dp[i][j] = str[j]-'0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(dp[i][j] != 0){  
                if(i == 0 || j == 0) 
                    continue;
                else 
                    dp[i][j] += min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans*ans;
    return 0;
}