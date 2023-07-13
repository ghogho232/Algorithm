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
	if (n == 1)
		return 0;
	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}
}
