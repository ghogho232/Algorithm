#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	vector<int>an(m);
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		if (binary_search(v.begin(), v.end(), a)) {
			an[i] = 1;
		}
		else
			an[i] = 0;
		
	}
	for (int i = 0; i < an.size(); i++) {
		cout << an[i] << " ";
	}

}