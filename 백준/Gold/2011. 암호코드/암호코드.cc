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
const int MOD = 1000000;
int dp[5001]={0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;

    cin >> str;
    if(str[0] == '0'){
        cout << 0;
        return 0;
    }
    dp[0]=dp[1]=1;
    for(int i = 2; i <= str.length(); i++){
        if(str[i-1] != '0')
            dp[i] = dp[i-1] % MOD;
        if(str[i-2] == '1' || str[i-2] == '2' && str[i-1] <= '6'){
            dp[i] = (dp[i]+dp[i-2])%MOD;
        }
    }
    cout << dp[str.length()] % MOD;
    return 0;
}