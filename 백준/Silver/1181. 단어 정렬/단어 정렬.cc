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

bool dic(string str1, string str2) {
	if (str1.length() < str2.length())
		return true;
	else if (str1.length() == str2.length()) {
		return str1 < str2;
	}
	else
		return false;
}
int main(){
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), dic);
	v.erase(unique(v.begin(), v.end()),v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}