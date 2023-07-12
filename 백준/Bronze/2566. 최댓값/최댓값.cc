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
	int arr[9][9];
	int maxi = -1;
	int ni, nj;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (maxi < arr[i][j]) {
				maxi = arr[i][j];
				ni = i+1;
				nj = j+1;
			}
		}
	}
	cout << maxi << "\n";
	cout << ni << " " << nj << "\n";

	return 0;

}