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
	for (int i = 0; i < n; i++) {
		int tmp = i;
		int res = i;
		while (tmp != 0) {
			res += tmp % 10;
			tmp /= 10;
		}
		if (res == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}