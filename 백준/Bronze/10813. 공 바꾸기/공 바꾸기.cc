#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;

int arr[101];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}

}