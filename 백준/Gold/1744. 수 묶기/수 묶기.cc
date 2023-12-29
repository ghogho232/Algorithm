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
	int n;
	ll ans = 0;
	cin >> n;
	vector<int>v(n);
	vector<int>visited(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i > 0; i--) {
		if (!visited[i] && !visited[i - 1] && v[i] > 1 && v[i - 1] > 1) {
			visited[i] = 1;
			visited[i - 1] = 1;
			ans += v[i] * v[i - 1];
		}
	}
	for (int i = 0; i < v.size() - 1; i++) {
		if (!visited[i] && !visited[i + 1] && v[i] <= 0 && v[i + 1] <= 0) {
			visited[i] = 1;
			visited[i + 1] = 1;
			ans += v[i] * v[i + 1];
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			ans += v[i];
		}
	}
	cout << ans;

	return 0;
}