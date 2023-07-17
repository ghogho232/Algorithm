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
	int n;
	map<string, string> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str1,str2;
		cin >> str1 >> str2;
		if (str2 == "leave") {
			m.erase(str1);
		}
		else {
			m[str1] = str2;
		}
	}
	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		cout << it->first << "\n";
	}
	return 0;
}