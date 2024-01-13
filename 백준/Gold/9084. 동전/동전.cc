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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        int arr[21];
        int dp[10001];
        cin >> n;
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        cin >> m;
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = arr[i]; j <= m; j++){
                dp[j] = dp[j] + dp[j-arr[i]];
            }
        }
        cout << dp[m]<<"\n";
    }
    return 0;
}