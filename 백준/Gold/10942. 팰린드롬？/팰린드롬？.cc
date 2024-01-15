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

int arr[2001];
int dp[2001][2001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        dp[i][i] = 1;
    }
    for(int i = n; i > 0; i--){
        for(int j = i + 1; j <= n; j++){
            if(arr[i]==arr[j]){
                if(j-i==1)
                    dp[i][j] = 1;
                else if(dp[i+1][j-1])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            else dp[i][j] = 0;
        }
    }
    cin >> m;
    while(m--){
        int from, to;
        cin >> from >> to;
        cout << dp[from][to]<<"\n";
    }
    return 0;
}