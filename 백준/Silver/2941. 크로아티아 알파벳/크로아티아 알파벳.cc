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
	vector<string> v = { "c=", "c-","dz=", "d-","lj","nj","s=","z=" };
	string str;
	cin >> str;
	for (int i = 0; i < v.size(); i++) {
		while (1) {
			int idx = str.find(v[i]);
			if (idx == string::npos)
				break;
			str.replace(idx, v[i].length(), "a");
		}
	}
	cout << str.length();

}