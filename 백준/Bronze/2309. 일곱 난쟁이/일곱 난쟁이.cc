#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>

using namespace std;


int getsum(int *height) {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += height[i];
	}
	return sum;
}
int solve(int *height) {
	int ninesum = getsum(height);
	int sevensum = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			sevensum = ninesum - height[i] - height[j];
			if (sevensum == 100) {
				height[i] = height[j] = -1;
				return 0;
			}

		}
	
	}
}
int main() {
	int height[9];
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}
	solve(height);
	sort(height, height + 9);	
	for (int i =2; i < 9; i++) {
		cout << height[i] << "\n";
	}
}

