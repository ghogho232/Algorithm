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
	cin >> n >> m;
	map<string,int> ma;
	vector<string>v;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
		ma[str] = i;
	}
	while(m--) {
		string str;
		cin >> str;
		if ('1' <= str[0] && str[0] <= '9')
			cout << v[stoi(str)-1] << "\n";
		else
			cout << ma[str] << "\n";
	}
	return 0;

}