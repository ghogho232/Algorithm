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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		ll ans = 0;
		int max_v = 0;
		for (int i = n - 1; i >= 0; i--) {
			max_v = max(v[i], max_v);
			ans += max_v - v[i];
		}
		cout << ans <<"\n";
	}

	return 0;
}