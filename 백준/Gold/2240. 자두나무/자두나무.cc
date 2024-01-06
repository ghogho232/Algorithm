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
#include <iomanip>
#define ll long long

using namespace std;

int t, w;
int arr[1001];
int dp[31][2][1001]; //[이동횟수][현재위치][시간]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> arr[i];

	for (int j = 0; j <= w; j++){ //위치
		for (int i = 1; i <= t; i++){ //시간
			if (j == 0){ //첫 시작
				dp[j][0][i] = dp[j][0][i - 1] + (arr[i] == 1);
			}
			else{
				dp[j][0][i] = max(dp[j][0][i - 1] + (arr[i] == 1), dp[j - 1][1][i - 1] + (arr[i] == 1));
				dp[j][1][i] = max(dp[j][1][i - 1] + (arr[i] == 2), dp[j - 1][0][i - 1] + (arr[i] == 2));
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j <= w; j++){
			ans = max(ans, dp[j][i][t]);
		}
	}

	cout << ans;
    return 0;
}