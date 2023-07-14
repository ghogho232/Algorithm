#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 0;
	while (n >= 0) {
		if (n % 5 == 0) {
			ans += (n / 5);
			cout << ans;
			return 0;
		}
		n -= 3;
		ans++;
	}
	cout << -1;
	return 0;
}