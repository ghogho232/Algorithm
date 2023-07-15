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

bool so(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}
int main(){
	int n;
	cin >> n;
	vector<pair<int,string>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first>>v[i].second;
	}
	stable_sort(v.begin(), v.end(), so);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}