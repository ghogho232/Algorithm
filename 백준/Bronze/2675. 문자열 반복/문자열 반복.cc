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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		string str;
		cin >> n;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < n; j++) {
				cout << str[i] ;
			}
		}
		cout << "\n";
	}
	return 0;

}