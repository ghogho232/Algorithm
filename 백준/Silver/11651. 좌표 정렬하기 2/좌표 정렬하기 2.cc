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

int main(){

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].second>> v[i].first;
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < n-1; i++) {
		if (v[i].first == v[i + 1].first) {
			if (v[i].second > v[i + 1].second) {
				int temp = v[i].second;
				v[i].second = v[i + 1].second;
				v[i + 1].second = temp;
			}

		}
	}

	for (int i = 0; i < n; i++) {
		cout << v[i].second << " " << v[i].first << "\n";
	}
	return 0;
}