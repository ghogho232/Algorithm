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
	int arr[26] = { -1 };
	string str;
	cin >> str;
	for (char i = 'a'; i <= 'z'; i++) {
		cout << (int)str.find(i) << ' ';
	}

}