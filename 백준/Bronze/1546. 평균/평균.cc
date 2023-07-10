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
	double arr[1001];
	int m, n;
	double maxi = 0;
	double sum = 0;
	double average = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, arr[i]);
	}
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / maxi * 100;
		sum += arr[i];
	}
	average = sum / n;

	cout << average;
}