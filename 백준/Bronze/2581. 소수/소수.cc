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

int n, m, sum, minn;

void f(int k) {
	if (k == 1) return;
	for (int i = 2; i <= k / 2; i++)
		if (k % i == 0) return;
	if (!minn) minn = k;
	sum += k;
}


int main() {
	cin >> n >> m;

	for (int i = n; i <= m; i++) f(i);

	if (!sum) 
		cout << -1;

	else cout << sum << "\n" << minn;

	return 0;
}
