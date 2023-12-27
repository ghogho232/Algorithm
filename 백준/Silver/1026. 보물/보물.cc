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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int ans = 0;
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> b[j];
	}

	sort(b.begin(), b.end(), greater<int>());
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
	cout << ans;
	return 0;
}