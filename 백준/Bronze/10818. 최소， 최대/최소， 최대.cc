#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* data;
	data = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	sort(data, data + n);
	cout << data[0] << " " << data[n-1];
}
