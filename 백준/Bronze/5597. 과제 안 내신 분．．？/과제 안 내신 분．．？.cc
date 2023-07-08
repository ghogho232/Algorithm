#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;

int arr[31];

int main() {
	for (int i = 0; i < 28; i++) {
		int a;
		cin >> a;
		arr[a] = a;
	}

	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0)
			cout << i << "\n";
	}
	return 0;

}
