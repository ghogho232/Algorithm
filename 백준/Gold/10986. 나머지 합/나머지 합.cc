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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    long long cnt[100001];
    long long sum = 0, ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
        int a;
		cin >> a;
		sum += a;
		cnt[sum % m]++;
	}

	for (int i = 0; i <= m; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	
	cout << cnt[0] + ans;
}