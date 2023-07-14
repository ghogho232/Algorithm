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
	int cnt = 0;
	cin >> n;
	for (int i = 666;; i++) {
		int tmp = i;
		while (tmp >= 666) {
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		}
		if (cnt == n) {
			cout << i;
			break;
		}
	}
	return 0;
}