#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%1d", &v[i]);
	}
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	cout << sum;
}