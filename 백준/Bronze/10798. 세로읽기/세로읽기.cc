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
	string str[5];
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < str[j].length()) {
				cout << str[j][i];
			}
		}
	}
	return 0;
}