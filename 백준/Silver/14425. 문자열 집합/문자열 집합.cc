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
#include<set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	map<string,int>ma;
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		ma[a] = 1;
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		if (ma[a] == 1)
			cnt++;
	}
	cout << cnt;
	return 0;

}