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

    int n;
    cin >> n;
    int dp[1001];
    dp[1]=dp[3]=dp[4]=dp[5] = 1;
    dp[2] = 0;
    for(int i = 6; i <= n; i++){
        if(dp[i-1]==0 || dp[i-3]==0 || dp[i-4]==0)
            dp[i] = 1;
        else 
            dp[i] = 0;
    }
    if(dp[n] == 1)
        cout << "SK";
    else 
        cout << "CY";
    return 0;
}