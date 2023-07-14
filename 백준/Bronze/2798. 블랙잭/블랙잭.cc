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
	int n, m;
	cin >> n >> m;
	vector<int>v(n);
	int sum = 0;
	
	int maxs = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n-2 ; i++) {
		for (int j = i+1 ; j < n-1 ; j++) {
			for (int k = j+1 ; k < n; k++) {
				sum = v[i] + v[j] + v[k];
				if (sum <= m) {
					maxs = max(maxs, sum);

				}
			}
		}
	}
	cout << maxs;
}